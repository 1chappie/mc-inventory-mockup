//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPO_H
#define MC_INVENTORY_MOCKUP_REPO_H

#include <vector>
#include <algorithm>
#include "../exceptions/RepoException.hpp"
#include <utility>
#include "../domain/IItem.h"
#include <fstream>
#include "Domain.h"

using std::vector;
using std::pair, std::make_pair;

class Repo {
protected:
    vector<pair<IItem *, unsigned int>> slots;
    std::string filePath;

public:
    // The design of this class was updated to accommodate csv read/ write operations,
    // and it's very botched. It should've been done within a different service,
    // but it's too late now.
    Domain &domain;

    friend class InventoryService;

    /**
     * Constructor for the Repo class
     * @param _domain domain for loading and saving references
     * @param filePath path to the file to load from, defaults to "../data/inventory.csv"
     */
    Repo(Domain &_domain, const string &filePath = "../data/inventory.csv");

    /**
     * Copy constructor
     * @param other Another Repo instance
     */
    Repo(const Repo &other);

    ~Repo() = default;

    // THE CSV READ/WRITE OPERATIONS ARE DEPENDENT ON THE DOMAIN. NOT IDEAL BUT IT IS WHAT IT IS.
    // THE CSV FILE ONLY STORES THE ITEM ID S AND THE QUANTITY OF EACH SLOT.
    // ITEM BUILDING INFORMATION MUST BE READ FROM THE DOMAIN.

    /**
     * Loads the inventory from a given csv file. If successful, the new csv is saved to the filePath.
     * @param _filePath csv path
     * @return true if successful, false otherwise
     */
    bool load(std::string _filePath);

    /**
     * Reloads the inventory from the internal filePath.
     * @return true if successful, false otherwise
     */
    bool refresh();

    /**
     * Saves the inventory to the given csv path.
     * @param filePath csv path
     * @return true if successful, false otherwise
     */
    bool save(std::string filePath);

    /**
     * Saves the inventory to the internal filePath.
     * @return true if successful, false otherwise
     */
    bool save();

    /**
     * Adds a slot to the inventory. The slots are formatted as follows: <br>
     * <code>
     * pair\<IItem * _item, unsigned int quantity\> slot;
     * </code>
     * @param _item The item to be added
     * @param _qty The quantity of the item to be added
     */
    virtual void addSlot(IItem *_item, unsigned int _qty);

    /**
     * Find the slot of the last occurrence of an item by ID and replace it.
     * @param _item Item to replace
     * @param _qty New quantity in slot. By default, quantity remains unchanged.
     * @throws RepoException if the item is not found
     */
    virtual void updateSlot(IItem *_item, unsigned int _qty = 0);

    /**
     * Replaces the slot at slots[_index] with a new pair of item and quantity.
     * @param _index Index of the slot to be replaced
     * @param _item Item to replace
     * @param _qty New quantity in slot. By default, quantity remains unchanged.
     * @throws RepoException if the index is out of bounds
     */
    virtual void updateSlotAt(unsigned int _index, IItem *_item, unsigned int _qty = 0);

    /**
     * Removes the slot of the last occurrence of an item.
     * @param _item Item
     * @throws RepoException if the item is not found
     */
    virtual void popSlot(IItem *_item);

    /**
     * Removes the slot at slots[_index].
     * @param _index Index of the slot to be removed
     * @throws RepoException if the index is out of bounds
     */
    virtual void popSlotAt(unsigned int _index);

    /**
     * Return reference to the last slot where the specified item is found.
     * @param _item Item
     * @return *pair\<IItem * _item, unsigned int _qty\>
     * @throws RepoException if the item is not found
     */
    virtual pair<IItem *, unsigned int> &lastSlotWhere(IItem *_item);

    /**
     * Return reference to the first slot where the specified item is found.
     * @param _item Item
     * @return *pair\<IItem * _item, unsigned int _qty\>
     * @throws RepoException if the item is not found
     */
    virtual pair<IItem *, unsigned int> &firstSlotWhere(IItem *_item);

    /**
     * Return reference to the slot at the specified index.
     * @param _index Index of the slot
     * @return *pair\<IItem * _item, unsigned int _qty\>
     * @throws RepoException if the index is out of bounds
     */
    virtual pair<IItem *, unsigned int> &slotAt(unsigned int _index);

    /**
     * Return reference to the internal slots vector. <u>Unsafe.</u>
     * @return *vector\<pair\<IItem * _item, unsigned int _qty\>\>
     */
    virtual vector<pair<struct IItem *, unsigned int>> &getAll();

    /**
     * Return the number of slots in the inventory.
     * @return unsigned int
     */
    virtual unsigned int size();
};


#endif //MC_INVENTORY_MOCKUP_REPO_H
