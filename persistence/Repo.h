//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPO_H
#define MC_INVENTORY_MOCKUP_REPO_H

#include <vector>
#include <algorithm>
#include "../exceptions/RepoException.h"

using std::vector;

template<typename TElem>
class Repo {
protected:
    vector<TElem> slots;
public:
    Repo() = default;

    Repo(const Repo &other);

    ~Repo() = default;

    virtual void add(const TElem &);

    virtual void update(const TElem &);

    virtual void update(unsigned int, const TElem &);

    virtual void remove(const TElem &);

    virtual void remove(unsigned int);

    virtual const TElem &search(const TElem &);

    virtual const TElem &search(unsigned int);

    virtual const vector<TElem> &getAll();

    virtual int size();
};

template<typename TElem>
Repo<TElem>::Repo(const Repo &other) {
    this->slots = other.slots;
}

template<typename TElem>
void Repo<TElem>::add(const TElem &slot) {
    // Due to the way a minecraft inventory works, the items are stackable (up to 64), therefore we will call
    // the elements of the repo "slots", rather than "items" or "elements".
    // Also, checking for duplicates isn't necessary.
    this->slots.push_back(slot);
}

template<typename TElem>
void Repo<TElem>::update(const TElem &slot) {
    // This updates slots based on the item id that lives in them.
    auto iterator = std::find(this->slots.begin(), this->slots.end(), slot);
    if (iterator == this->slots.end())
        throw RepoException("Item not found.\n");
    this->slots[iterator - this->slots.begin()] = slot;
}

template<typename TElem>
void Repo<TElem>::update(unsigned int ind, const TElem &slot) {
    // I know that "this isn't the proper way of doing this",
    // but looking up items by order isn't that far-fetched in a game inventory.
    if (ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    this->slots[ind] = slot;
}

template<typename TElem>
void Repo<TElem>::remove(const TElem &slot) {
    // The proper way.
    auto iterator = std::find(this->slots.begin(), this->slots.end(), slot);
    if (iterator == this->slots.end())
        throw RepoException("Item not found.\n");
    this->slots.erase(iterator);
}

template<typename TElem>
void Repo<TElem>::remove(unsigned int slot) {
    if (slot >= this->slots.size())
        throw RepoException("Slot not found.\n");
    this->slots.erase(this->slots.begin() + slot);
}

template<typename TElem>
const TElem &Repo<TElem>::search(const TElem &slot) {
    // The proper way.
    auto it = std::find(this->slots.begin(), this->slots.end(), slot);
    if (it == this->slots.end())
        throw RepoException("Item not found.\n");
    return *it;
}

template<typename TElem>
const TElem &Repo<TElem>::search(unsigned int ind) {
    // And bananas again.
    if (ind >= this->slots.size())
        throw RepoException("Slot not found.\n");
    return *this->slots[ind];
}

template<typename TElem>
const vector<TElem> &Repo<TElem>::getAll() {
    return this->slots;
}

template<typename TElem>
int Repo<TElem>::size() {
    return this->slots.size();
}


#endif //MC_INVENTORY_MOCKUP_REPO_H
