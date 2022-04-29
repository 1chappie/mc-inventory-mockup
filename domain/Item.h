//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ITEM_H
#define MC_INVENTORY_MOCKUP_ITEM_H

#include <string>

using std::string;

class Item {
protected:
    string id;
    string displayName;
    //TODO Image icon; for the UI
    bool canPlace;

    Item(const string &_id, const string &_displayName, const bool &_canPlace);

    Item();

public:

    string getID() const;

    string getDisplayName() const;

    bool operator==(const Item &other) const;
};


#endif //MC_INVENTORY_MOCKUP_ITEM_H
