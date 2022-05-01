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
    //only a copy of the vector is returned
    return this->repo->slots;
}

void InventoryService::give(IItem *item, unsigned int amount) {
    if (amount == 0) return;
    if (item->isStackable()) {
        if (this->total(item))
            amount = this->hGive_fill_preceding(dynamic_cast<StackableItem *>(item), amount);
        if (amount > dynamic_cast<StackableItem *>(item)->getMaxStack())
            amount = this->hGive_normalize_surplus(dynamic_cast<StackableItem *>(item), amount);
        if (amount)
            this->repo->addSlot(item, amount);
    } else {
        while (amount--)
            this->repo->addSlot(item, 1);
    }
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

void InventoryService::clear(IItem *item, unsigned int amount) {
    while (amount && this->getLastRef(item)) {
        unsigned int to_clear = std::min(amount, this->getLastRef(item)->second);
        this->getLastRef(item)->second -= to_clear;
        amount -= to_clear;
        if (this->getLastRef(item)->second == 0)
            this->repo->popSlot(item);
    }
}

void InventoryService::clear() {
    this->repo->slots.clear();
}


