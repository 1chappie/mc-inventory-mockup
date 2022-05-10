//
// Created by chappie on 20.04.2022.
//

#include "InventoryService.h"
#include <iostream>

InventoryService::InventoryService(Repo &_repo) : repo(&_repo) {}

pair<IItem *, unsigned int> *InventoryService::getLastRef(IItem *item) {
    try {
        return &this->repo->lastSlotWhere(item);
    }
    catch (RepoException &e) {
        return nullptr;
    }
}

pair<IItem *, unsigned int> *InventoryService::getLastRef(std::string id) {
    StackableItem dummy = StackableItem(id, "dummy");
    try {
        return &this->repo->lastSlotWhere(dynamic_cast<IItem *>(&dummy));
    }
    catch (RepoException &e) {
        return nullptr;
    }
}

pair<IItem *, unsigned int> *InventoryService::getFirstRef(IItem *item) {
    try {
        return &this->repo->firstSlotWhere(item);
    }
    catch (RepoException &e) {
        return nullptr;
    }
}

pair<IItem *, unsigned int> *InventoryService::getFirstRef(std::string id) {
    StackableItem dummy = StackableItem(id, "dummy");
    try {
        return &this->repo->firstSlotWhere(dynamic_cast<IItem *>(&dummy));
    }
    catch (RepoException &e) {
        return nullptr;
    }
}

unsigned int InventoryService::total(IItem *item) {
    unsigned int amt = 0;
    std::for_each(this->repo->slots.begin(), this->repo->slots.end(),
                  [&amt, item](pair<struct IItem *, unsigned int> slot) {
                      if (slot.first->getID() == item->getID())
                          amt += slot.second;
                  });
    return amt;
}

unsigned int InventoryService::total() {
    unsigned int amt = 0;
    std::for_each(this->repo->slots.begin(), this->repo->slots.end(),
                  [&amt](pair<struct IItem *, unsigned int> slot) {
                      amt += slot.second;
                  });
    return amt;
}

vector<pair<IItem *, unsigned int>> InventoryService::getAll() {
    // Only a copy of the vector is returned
    return this->repo->slots;
}

void InventoryService::give(IItem *item, unsigned int amount, bool log) {
    if (amount == 0) return;
    if (log) this->commands.did({comm::GIVE, item->getID(), amount});
    if (item->isStackable()) {
        // First, if the item already exists somewhere in the inventory,
        // try filling the available slots
        if (this->total(item))
            // The store the amount that remained
            amount = this->hGive_fill_preceding(dynamic_cast<StackableItem *>(item), amount);
        // If the amount that remained is bigger than the max stack size,
        // create new slots with full stacks until less than a full stack remains
        if (amount > dynamic_cast<StackableItem *>(item)->getMaxStack())
            // And store the new amount again
            amount = this->hGive_normalize_surplus(dynamic_cast<StackableItem *>(item), amount);
        // And now finally, if anything's left after those two functions,
        // create a new slot with the remaining amount
        if (amount)
            this->repo->addSlot(item, amount);
    } else {
        // If the item is not stackable, just create a new slot for each item added
        while (amount--)
            this->repo->addSlot(item, 1);
    }
    this->repo->save();
}

unsigned int InventoryService::hGive_fill_preceding(StackableItem *item, unsigned int amount) {
    for (auto &slot: this->repo->slots) {
        if (!amount) break;
        if (slot.first->getID() == item->getID() && slot.second < item->getMaxStack()) {
            unsigned int to_give = std::min(item->getMaxStack() - slot.second, amount);
            slot.second += to_give;
            amount -= to_give;
        }
    }
    return amount;
}

unsigned int InventoryService::hGive_normalize_surplus(StackableItem *item, unsigned int amount) {
    while (amount > item->getMaxStack()) {
        this->repo->addSlot(item, item->getMaxStack());
        amount -= item->getMaxStack();
    }
    return amount;
}

void InventoryService::clear(IItem *item, unsigned int amount, bool log) {
    if (amount == 0) return;
    unsigned int cleared = 0;
    while (amount && this->getLastRef(item)) {
        unsigned int to_clear = std::min(amount, this->getLastRef(item)->second);
        this->getLastRef(item)->second -= to_clear;
        amount -= to_clear;
        cleared += to_clear;
        if (this->getLastRef(item)->second == 0)
            this->repo->popSlot(item);
    }
    if (log)this->commands.did({comm::CLEAR, item->getID(), cleared});
    this->repo->save();
}

void InventoryService::clear() { //TODO undo redo
    this->repo->slots.clear();
}

bool InventoryService::hCommands_execute(Command command) {
    switch (command.getCommand()) {
        case comm::GIVE:
            std::cout << "Giving " << command.getQty() << " " << command.getId() << "s" << std::endl;
            this->give(this->repo->domain.get(command.getId()), command.getQty(), false);
            break;
        case comm::CLEAR:
            std::cout << "Clearing " << command.getQty() << " " << command.getId() << "s" << std::endl;
            this->clear(this->repo->domain.get(command.getId()), command.getQty(), false);
            break;
        default:
            std::cout << "Cannot execute this command" << std::endl;
            return false;
    }
    return true;
}

bool InventoryService::undo() {
    auto c = this->commands.undo();
    if (c.getCommand() == comm::NULL_COMMAND) return false;
    this->hCommands_execute(c);
    return true;
}

bool InventoryService::redo() {
    auto c = this->commands.redo();
    if (c.getCommand() == comm::NULL_COMMAND) return false;
    this->hCommands_execute(c);
    return true;
}


