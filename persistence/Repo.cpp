//
// Created by stefa on 29.04.2022.
//
#include "Repo.h"
#include <iostream>

Repo::Repo() : slots(vector<pair<IItem *, unsigned int>>()) {}

Repo::Repo(const Repo &other) : slots(other.slots) {}

void Repo::addSlot(IItem *_item, unsigned int _qty) {
    // Due to the way a minecraft inventory works, the items are stackable (up to 64), therefore we will call
    // the elements of the repo "slots", rather than "items" or "elements".
    // Also, checking for duplicates isn't necessary.
    this->slots.push_back(make_pair(_item, _qty));
}

void Repo::updateSlot(IItem *_item, unsigned int _qty) {
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](pair<IItem *, unsigned int> slot) { return slot.first->getID() == _item->getID(); });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    if (!_qty) _qty = this->slots[std::distance(this->slots.begin(), it.base() - 1)].second;
    this->slots[std::distance(this->slots.begin(), it.base() - 1)] = make_pair(_item, _qty);
}

void Repo::updateSlotAt(unsigned int _ind, IItem *_item, unsigned int _qty) {
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    if (!_qty) _qty = this->slots[_ind].second;
    this->slots[_ind] = make_pair(_item, _qty);
}

void Repo::popSlot(IItem *_item) {
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](pair<IItem *, unsigned int> slot) { return slot.first->getID() == _item->getID(); });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    this->slots.erase(it.base() - 1);
}

void Repo::popSlotAt(unsigned int _ind) {
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    this->slots.erase(this->slots.begin() + _ind);
}

pair<IItem *, unsigned int> &Repo::lastSlotWhere(IItem *_item) {
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](auto slot) { return slot.first->getID() == _item->getID(); });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    return this->slots[std::distance(this->slots.begin(), it.base() - 1)];
}

pair<IItem *, unsigned int> &Repo::firstSlotWhere(IItem *_item) {
    auto it = std::find_if(this->slots.begin(), this->slots.end(),
                           [_item](auto slot) { return slot.first->getID() == _item->getID(); });
    if (it == this->slots.end())
        throw RepoException("Item not found.\n");
    return this->slots[std::distance(this->slots.begin(), it)];
}

pair<IItem *, unsigned int> &Repo::slotAt(unsigned int _ind) {
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    return this->slots[_ind];
}

vector<pair<struct IItem *, unsigned int>> &Repo::getAll() {
    return this->slots;
}

unsigned int Repo::size() {
    return this->slots.size();
}