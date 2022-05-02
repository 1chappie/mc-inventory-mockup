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
#include <string>

class InventoryService {
private:
    Repo *repo;

    // I recommend that you read the documentation of the give() function (below) before reading
    // these private ones, and also maybe look at a video of minecraft or two if you have
    // no idea how its inventory system works :)

    // Fills up, in ascending order, all the slots that currently hold the same
    // type of item, but haven't reached their stack limit yet. It returns the amount of items
    // that remained after filling everything that's available.
    unsigned int hGive_fill_preceding(StackableItem *item, unsigned int amount);

    // If the amount is greater than the max stack size of the item, it creates however many
    // slots with max stacks are necessary. It then returns the amount of items that remained.
    unsigned int hGive_normalize_surplus(StackableItem *item, unsigned int amount);


public:
    friend class CLI;

    /**
     * Constructor
     * @param _repo Repo to which the service links to
     */
    InventoryService(Repo &_repo);

    //The default constructor is deleted, because a repo should be linked
    InventoryService() = delete;

    /**
     * Gets a slot reference to the last instance of the specified item in the repository.
     * @param item The item to look for. Must be an instance of IITem.
     * @return Pointer to slot which has the desired item. <br>
     * Format of slot is pair\<IITem* item, unsigned int quantity\>. <br>
     * If no such item is found, returns nullptr.
     */
    pair<IItem *, unsigned int> *getLastRef(IItem *item);

    /**
     * Gets a slot reference to the last instance of the item with the specified ID in the repository.
     * @overloads pair\<IItem *, unsigned int\> *getLastRef(IItem *item)
     * @param _id The ID of the item to look for.
     * @return Pointer to slot which has the desired item. <br>
     * Format of slot is pair\<IITem* item, unsigned int quantity\>. <br>
     * If no such item is found, returns nullptr.
     */
    pair<IItem *, unsigned int> *getLastRef(std::string);

    /**
     * Gets a slot reference to the first instance of the specified item in the repository.
     * @param item The item to look for. Must be an instance of IITem.
     * @return Pointer to slot which has the desired item. <br>
     * Format of slot is pair\<IITem* item, unsigned int quantity\>. <br>
     * If no such item is found, returns nullptr.
     */
    pair<IItem *, unsigned int> *getFirstRef(IItem *item);

    /**
     * Gets a slot reference to the first instance of the item with the specified ID in the repository.
     * @overloads pair\<IItem *, unsigned int\> *getLastRef(IItem *item)
     * @param _id The ID of the item to look for.
     * @return Pointer to slot which has the desired item. <br>
     * Format of slot is pair\<IITem* item, unsigned int quantity\>. <br>
     * If no such item is found, returns nullptr.
     */
    pair<IItem *, unsigned int> *getFirstRef(std::string);

    /**
     * Get the total amount of a specified item in the repository. (from all slots)
     * @param item Item to look for. Must be an instance of IITem.
     * @return amount
     */
    unsigned int total(IItem *item);

    /**
     * Get the total amount of items in the inventory. <br>
     * Use <i>total(IItem*)</i> to get the total amount of a specific item.
     * @return amount of items
     */
    unsigned int total();

    /**
     * Get a copy of the inventory.
     * @return vector\<pair\<IItem *, unsigned int\>\> as slots
     */
    vector<pair<IItem *, unsigned int>> getAll();

    /**
     * @brief Add a given amount of an item to the inventory. <br>
     * Depending on the type (stackable/ non-stackable) of the item, <br>
     * and (if applicable) its stack size, the added items will occupy a different amount of slots. <br>
     * The inventory is automatically resized to fit the necessary amount of slots. <br>
     * If any slots already host that item type and they haven't reached stack limit yet, <br>
     * they will be filled in ascending order. <br>
     * If the stack limit for all available slots has been reached, new slots are created <br>
     * until all items are added to the inventory. <br>
     * @param item Item to be added. Must be an instance of IItem.
     * @param amount Amount of items to be added. Defaults to 1.
     */
    void give(IItem *item, unsigned int amount = 1);
    // I tried making this as similar to Minecraft as I could. And besides the fact
    // that you can't freely place around items in slots on a 2D grid
    // (therefore cannot have empty slots), I'd say that I've gotten pretty close.

    /**
     * @brief Clear (remove) a given amount of an item from the inventory. <br>
     * Items are removed from slots in descending order. <br>
     * If a slot has been emptied, it is removed from the inventory. <br>
     * If the amount of items to be removed exceeds the amount of available items, <br>
     * all items of that type are removed from the inventory. <br>
     * @param item Item to be removed. Must be an instance of IItem.
     * @param amount Amount of items to be removed. Defaults to 1.
     */
    void clear(IItem *item, unsigned int amount = 1);

    /**
     * Clear all items from the inventory.
     */
    void clear();

};


#endif //MC_INVENTORY_MOCKUP_INVENTORYSERVICE_H
