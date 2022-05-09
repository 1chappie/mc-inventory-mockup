//
// Created by stefa on 09.05.2022.
//

#include "Domain.h"
#include <iostream>

Domain::Domain(const string &_path) : path(_path) {
    this->refresh();
}

Domain::Domain() : path("../data/items.csv") {
    this->refresh();
}

bool Domain::load(const string &_path) {
    regex r("^.*\\.(csv|CSV)$");
    if (!regex_match(path, r)) //path must end in .csv
        return false;

    this->path = _path;

    std::ifstream fileLocation(path);
    if (!fileLocation.is_open())
        return false;

    std::string line, word;
    vector<string> row;
    while (getline(fileLocation, line)) {
        row.clear();
        std::stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        if (row.empty())
            continue;
        if (row[0] == "stackable-item") {
            this->stackables.emplace_back(row[1], row[2], stoi(row[3]));
        } else if (row[0] == "unstackable-item") {
            this->unstackables.emplace_back(row[1], row[2]);
        } else if (row[0] == "armour") {
            Armour a = Armour::build()
                    .withID(row[1])
                    .withDisplayName(row[2])
                    .withDurabilityMax(stoi(row[3]))
                    .withDurability(stoi(row[4]))
                    .withProtectionLevel(stoi(row[5]))
                    .withEnchantments({});
            this->armours.emplace_back(a);
        } else if (row[0] == "weapon") {
            Weapon w = Weapon::build()
                    .withID(row[1])
                    .withDisplayName(row[2])
                    .withDurabilityMax(stoi(row[3]))
                    .withDurability(stoi(row[4]))
                    .withDamage(stoi(row[5]))
                    .withEnchantments({});
            this->weapons.emplace_back(w);
        } else if (row[0] == "consumable") {
            Consumable c = Consumable::build()
                    .withID(row[1])
                    .withDisplayName(row[2])
                    .withMaxStack(stoi(row[3]))
                    .withSaturation(stoi(row[4]))
                    .withEffects({});
            this->consumables.emplace_back(c);
        } else {
            fileLocation.close();
            return false;
        }
    }
    fileLocation.close();
    return true;
}

bool Domain::save(const std::string &_path) {
    regex r("^.*\\.(csv|CSV)$");
    if (!regex_match(path, r))
        return false;

    this->path = _path;

    std::ofstream fileLocation(path);
    if (!fileLocation.is_open())
        return false;

    for (auto &stackable: this->stackables) {
        fileLocation << "stackable-item," << stackable.getID() << "," << stackable.getDisplayName() << ","
                     << stackable.getMaxStack() << "\n";
    }
    for (auto &consumable: this->consumables) {
        fileLocation << "consumable," << consumable.getID() << "," << consumable.getDisplayName() << ","
                     << consumable.getMaxStack() << "," << consumable.getSaturation() << "\n";
    }
    for (auto &unstackable: this->unstackables) {
        fileLocation << "unstackable-item," << unstackable.getID() << "," << unstackable.getDisplayName() << "\n";
    }
    for (auto &armour: this->armours) {
        fileLocation << "armour," << armour.getID() << "," << armour.getDisplayName() << ","
                     << armour.getDurabilityMax() << "," << armour.getDurability() << "," << armour.getProtectionLevel()
                     << "\n";
    }
    for (auto &weapon: this->weapons) {
        fileLocation << "weapon," << weapon.getID() << "," << weapon.getDisplayName() << ","
                     << weapon.getDurabilityMax() << "," << weapon.getDurability() << "," << weapon.getDamage() << "\n";
    }
    fileLocation.close();
    return true;
}

bool Domain::save() {
    return this->save(this->path);
}

bool Domain::refresh() {
    return this->load(this->path);
}

void Domain::write(IItem *item) {
    if (item->itemType() == "stackable-item")
        this->stackables.push_back(*dynamic_cast<StackableItem *>(item));
    else if (item->itemType() == "consumable")
        this->consumables.push_back(*dynamic_cast<Consumable *>(item));
    else if (item->itemType() == "unstackable-item")
        this->unstackables.push_back(*dynamic_cast<UnstackableItem *>(item));
    else if (item->itemType() == "armour")
        this->armours.push_back(*dynamic_cast<Armour *>(item));
    else if (item->itemType() == "weapon")
        this->weapons.push_back(*dynamic_cast<Weapon *>(item));
    this->save();
}

IItem *Domain::get(const string &id) {
    for (auto &stackable: this->stackables)
        if (stackable.getID() == id)
            return &stackable;
    for (auto &consumable: this->consumables)
        if (consumable.getID() == id)
            return &consumable;
    for (auto &unstackable: this->unstackables)
        if (unstackable.getID() == id)
            return &unstackable;
    for (auto &armour: this->armours)
        if (armour.getID() == id)
            return &armour;
    for (auto &weapon: this->weapons)
        if (weapon.getID() == id)
            return &weapon;
    return nullptr;
}

vector<IItem *> Domain::getAll() {
    vector<IItem *> items;
    for (auto &stackable: this->stackables)
        items.push_back(&stackable);
    for (auto &consumable: this->consumables)
        items.push_back(&consumable);
    for (auto &unstackable: this->unstackables)
        items.push_back(&unstackable);
    for (auto &armour: this->armours)
        items.push_back(&armour);
    for (auto &weapon: this->weapons)
        items.push_back(&weapon);
    return items;
}

bool Domain::deleteItem(const string &id) {
    // I know that this is very bad
    auto it1 = find_if(this->stackables.begin(), this->stackables.end(),
                       [&id](StackableItem &stackable) {
                           return stackable.getID() == id;
                       });
    if (it1 != this->stackables.end()) {
        this->stackables.erase(it1);
        this->save();
        return true;
    }
    auto it2 = find_if(this->consumables.begin(), this->consumables.end(),
                       [&id](Consumable &consumable) {
                           return consumable.getID() == id;
                       });
    if (it2 != this->consumables.end()) {
        this->consumables.erase(it2);
        this->save();
        return true;
    }
    auto it3 = find_if(this->unstackables.begin(), this->unstackables.end(),
                       [&id](UnstackableItem &unstackable) {
                           return unstackable.getID() == id;
                       });
    if (it3 != this->unstackables.end()) {
        this->unstackables.erase(it3);
        this->save();
        return true;
    }
    auto it4 = find_if(this->armours.begin(), this->armours.end(),
                       [&id](Armour &armour) {
                           return armour.getID() == id;
                       });
    if (it4 != this->armours.end()) {
        this->armours.erase(it4);
        this->save();
        return true;
    }
    auto it5 = find_if(this->weapons.begin(), this->weapons.end(),
                       [&id](Weapon &weapon) {
                           return weapon.getID() == id;
                       });
    if (it5 != this->weapons.end()) {
        this->weapons.erase(it5);
        this->save();
        return true;
    }
    return false;
}
