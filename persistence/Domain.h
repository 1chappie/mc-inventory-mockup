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

class Domain {
private:

    string path;
    vector<StackableItem> stackables;
    vector<UnstackableItem> unstackables;
    vector<Consumable> consumables;
    vector<Weapon> weapons;
    vector<Armour> armours;

public:
    Domain(const string &path);

    Domain();

    bool load(const string &path);

    bool refresh();

    bool save(const string &path);

    bool save();

    void write(IItem *);

    bool deleteItem(const string &id);

    IItem *get(const string &id);

    vector<IItem *> getAll();

};


#endif //MC_INVENTORY_MOCKUP_DOMAIN_H
