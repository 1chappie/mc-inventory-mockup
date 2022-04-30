//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_INVENTORYSERVICE_H
#define MC_INVENTORY_MOCKUP_INVENTORYSERVICE_H

#include "Repo.h"
#include "../domain/IItem.h"
#include "unstackable/Armour.h"
#include "unstackable/Weapon.h"
#include "stackable/Consumable.h"
#include "stackable/StackableItem.h"
#include "unstackable/UnstackableItem.h"

class InventoryService {
private:
    Repo *repo;

    unsigned int hGive_fill_preceding(StackableItem *item, unsigned int amount);

    unsigned int hGive_normalize_surplus(StackableItem *item, unsigned int amount);


public:
    InventoryService(Repo &_repo);

    InventoryService() = delete;

    pair<IItem *, unsigned int> *getLastRef(IItem *item);

    pair<IItem *, unsigned int> *getFirstRef(IItem *item);

    unsigned int total(IItem *item);

    unsigned int total();

    vector<pair<IItem *, unsigned int>> getAll();

    void give(IItem *item, unsigned int amount = 1);

    void clear(IItem *item, unsigned int amount = 1);

    void clear();

};


#endif //MC_INVENTORY_MOCKUP_INVENTORYSERVICE_H
