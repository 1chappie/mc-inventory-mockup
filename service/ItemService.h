//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ITEMSERVICE_H
#define MC_INVENTORY_MOCKUP_ITEMSERVICE_H

#include "Repo.h"
#include "../domain/Item.h"
#include "../domain/Armour.h"
#include "../domain/Weapon.h"
#include "../domain/Consumable.h"
#include "../domain/StackableItem.h"
#include "../domain/UnstackableItem.h"

class ItemService {
private:
    Repo<Item *> repo;

    void appendSlot(Item *item);

    void updateSlot(Item *item);

    void removeSlot(Item *item);

public:
    ItemService(Repo<Item *> _repo);

    ItemService() = default;

    void addItem(Item *item, unsigned int amount);

    void removeItem(Item *item, unsigned int amount);

    unsigned itemAmount(Item *item);

    vector<Item *> getAll();

};


#endif //MC_INVENTORY_MOCKUP_ITEMSERVICE_H
