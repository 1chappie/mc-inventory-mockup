//
// Created by chappie on 20.04.2022.
//

#include "ItemService.h"

//this is gross and i'm not sure how it works, but i need it
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

void ItemService::appendSlot(Item *item) {
    this->repo.add(item);
}

void ItemService::updateSlot(Item *item) {
    this->repo.update(item);
}

void ItemService::removeSlot(Item *item) {
//    this->repo.remove(item);
// not working for some reason TODO
}

ItemService::ItemService(Repo<Item *> _repo) {
    this->repo = _repo;
}

void ItemService::addItem(Item *item, unsigned int amount) {
    if(instanceof<StackableItem>(item))
}


