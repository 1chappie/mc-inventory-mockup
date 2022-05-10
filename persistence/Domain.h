//
// Created by stefa on 09.05.2022.
//

#ifndef MC_INVENTORY_MOCKUP_DOMAIN_H
#define MC_INVENTORY_MOCKUP_DOMAIN_H

#include "../domain/IItem.h"
#include "../domain/stackable/StackableItem.h"
#include "../domain/stackable/Consumable.h"
#include "../domain/unstackable/UnstackableItem.h"
#include "../domain/unstackable/Weapon.h"
#include "../domain/unstackable/Armour.h"
#include <vector>
#include <string>
#include <regex>
#include <fstream>

using std::vector, std::string, std::regex;
// The nature of this class might be stretching the supposed layered architecture a bit.

class Domain {
private:

    // Storing every type of item from a csv in a vector.
    string path;
    vector<StackableItem> stackables;
    vector<UnstackableItem> unstackables;
    vector<Consumable> consumables;
    vector<Weapon> weapons;
    vector<Armour> armours;

public:
    /**
     * Constructor for the Domain class. Takes a path to a csv file as a parameter,
     * and tries to load it.
     * @param path csv location
     */
    Domain(const string &path);

    /**
     * Empty constructor for the Domain class. The path for the csv file defaults
     * to "../data/items.csv".
     */
    Domain();

    /**
     * Tries to load a given csv file. If successful, the internal path is set to the given path.
     * @param path csv file
     * @return true if successful, false otherwise
     */
    bool load(const string &path);

    /**
     * Reloads the file from the internal path.
     * @return true if successful, false otherwise
     */
    bool refresh();

    /**
     * Saves the file to the given csv path. If successful, the internal path is set to the given path.
     * @param path csv path
     * @return true if successful, false otherwise
     */
    bool save(const string &path);

    /**
     * Saves the file to the internal path.
     * @overload save(const string &path)
     * @return true if successful, false otherwise
     */
    bool save();

    /**
     * Stores an item in the internal vectors and then it updates the csv file.
     * @param item item to store
     */
    void write(IItem *);

    /**
     * Removes an item from the internal vectors and then it updates the csv file.
     * @param id item to be removed
     * @return true if successful, false otherwise
     */
    bool deleteItem(const string &id);

    /**
     * Return an item instance from the internal vectors.
     * @param id item to find
     * @return IItem*
     */
    IItem *get(const string &id);

    /**
     * Returns the current csv file in vector form.
     * @return vector
     */
    vector<IItem *> getAll();

};


#endif //MC_INVENTORY_MOCKUP_DOMAIN_H
