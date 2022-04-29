//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPO_H
#define MC_INVENTORY_MOCKUP_REPO_H

#include <vector>
#include <algorithm>
#include "../exceptions/RepoException.h"
#include <utility>

using std::vector;
using std::pair;

template<typename TElem>
class Repo {
protected:
    vector<pair<TElem, unsigned int>> slots;
public:
    Repo() = default;

    Repo(const Repo &other);

    ~Repo() = default;

    virtual void addSlot(const TElem &, unsigned int _qty);

    //find an item by id and replace it
    virtual void updateSlot(const TElem &, unsigned int _qty = 0);

    //find an item by index replace it
    virtual void updateSlotAt(unsigned int, const TElem &, unsigned int _qty = 0);

    //by id
    virtual void popSlot(const TElem &);

    //by index
    virtual void popSlotAt(unsigned int);

    virtual pair<TElem, unsigned int> &slotWhere(const TElem &);

    virtual pair<TElem, unsigned int> &slotAt(unsigned int);

    virtual const pair<TElem, unsigned int> &getAll();

    virtual int size();
};

template<typename TElem>
Repo<TElem>::Repo(const Repo &other) {
    this->slots = other.slots;
}

template<typename TElem>
void Repo<TElem>::addSlot(const TElem &_item, unsigned int _qty) {
    // Due to the way a minecraft inventory works, the items are stackable (up to 64), therefore we will call
    // the elements of the repo "slots", rather than "items" or "elements".
    // Also, checking for duplicates isn't necessary.
    this->slots.push_back(std::make_pair(_item, _qty));
}

template<typename TElem>
void Repo<TElem>::updateSlot(const TElem &_item, unsigned int _qty) {
    // This updates slots based on the item id that lives in them.
    // Going from last to first.
    // TODO prolly broken
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](auto slot) { slot.first == _item; });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    this->slots[it - this->slots.rbegin()] = std::make_pair(_item, _qty);
}

template<typename TElem>
void Repo<TElem>::updateSlotAt(unsigned int _ind, const TElem &_item, unsigned int _qty) {
    // I know that "this isn't the proper way of doing this",
    // but looking up items by order isn't that far-fetched in a game inventory.
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    this->slots[_ind] = std::make_pair(_item, _qty);
}

template<typename TElem>
void Repo<TElem>::popSlot(const TElem &_item) {
    // The proper way.
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](auto slot) { slot.first == _item; });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    this->slots.erase(it);
}

template<typename TElem>
void Repo<TElem>::popSlotAt(unsigned int _ind) {
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    this->slots.erase(this->slots.rbegin() + _ind);
}

template<typename TElem>
pair<TElem, unsigned int> &Repo<TElem>::slotWhere(const TElem &_item) {
    // The proper way.
    auto it = std::find_if(this->slots.rbegin(), this->slots.rend(),
                           [_item](auto slot) { slot.first == _item; });
    if (it == this->slots.rend())
        throw RepoException("Item not found.\n");
    return *it;
}

template<typename TElem>
pair<TElem, unsigned int> &Repo<TElem>::slotAt(unsigned int _ind) {
    // And bananas again.
    if (_ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    return *this->slots[_ind];
}

template<typename TElem>
const pair<TElem, unsigned int> &Repo<TElem>::getAll() {
    return this->slots;
}

template<typename TElem>
int Repo<TElem>::size() {
    return this->slots.size();
}


#endif //MC_INVENTORY_MOCKUP_REPO_H
