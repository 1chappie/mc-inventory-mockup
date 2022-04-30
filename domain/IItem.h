//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_IITEM_H
#define MC_INVENTORY_MOCKUP_IITEM_H

#include <string>

using std::string;

class IItem {
protected:
    string id;
    string displayName;
    //TODO Image icon; for the UI
    bool canPlace;

    IItem(const string &_id, const string &_displayName, const bool &_canPlace);

    IItem();

public:

    string getID() const;

    string getDisplayName() const;

    bool operator==(const IItem &other) const;

    virtual bool isStackable() const = 0;

    virtual string getTooltip() const = 0;
};


#endif //MC_INVENTORY_MOCKUP_IITEM_H
