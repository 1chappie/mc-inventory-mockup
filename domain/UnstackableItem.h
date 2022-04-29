//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H

#include "Item.h"

class UnstackableItem : public Item {
protected:
    bool hasDurability;
    unsigned int durability;
    unsigned int durabilityMax;
public:
    UnstackableItem() = default;

    UnstackableItem(const string &_id, const string &_displayName);

    UnstackableItem(const string &_id, const string &_displayName,
                    unsigned int _durability, unsigned int _durabilityMax);

    UnstackableItem(const UnstackableItem &other);

    unsigned int getDurability() const;

    unsigned int setDurability(unsigned int _quantity);

    int addDurability(int _quantity);

    inline bool isStackable() const override { return false; }

};


#endif //MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H
