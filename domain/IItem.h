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

    /**
     * Returns the id of the item
     * @return id
     */
    string getID() const;

    /**
     * Returns the display name of the item
     * @return display name
     */
    string getDisplayName() const;

    bool operator==(const IItem &other) const;

    /**
     * Returns whether the item is stackable or not
     * @return true if stackable, false otherwise
     */
    virtual bool isStackable() const = 0;

    /**
     * Returns whether the item is enchantable or not
     * @return boolean
     */
    virtual bool isEnchantable() const { return false; }

    /**
     * Creates and returns a tooltip (list of all properties) of an item
     * @return string of description
     */
    virtual string getTooltip() const = 0;
};


#endif //MC_INVENTORY_MOCKUP_IITEM_H
