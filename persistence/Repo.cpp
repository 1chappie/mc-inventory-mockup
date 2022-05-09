//
// Created by stefa on 29.04.2022.
//
#include "Repo.h"
#include <iostream>
#include <fstream>
#include <sstream>

Repo::Repo(Domain &_domain, const string &_filePath) :
        slots(vector<pair<IItem *, unsigned int>>()),
        filePath(_filePath),
        domain(_domain) {
}

Repo::Repo(const Repo &other) = default;

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

bool Repo::load(std::string _filePath) {
    std::ifstream file(_filePath);
    this->filePath = _filePath;
    if (!file.is_open())
        return false;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id;
        std::string qty;
        std::getline(ss, id, ',');
        std::getline(ss, qty, '\n');
        unsigned int q = std::stoi(qty);
        IItem *item = this->domain.get(id);
        if (!item)
            return false;
        this->slots.push_back(make_pair(item, q));
    }
    file.close();
    return true;
}

bool Repo::refresh() {
    return this->load(this->filePath);
}

bool Repo::save(std::string filePath) {
    std::ofstream file(filePath);
    if (!file.is_open())
        return false;
    for (auto &slot: this->slots) {
        file << slot.first->getID() << "," << slot.second << std::endl;
    }
    file.close();
    return true;
}

bool Repo::save() {
    return this->save(this->filePath);
}
