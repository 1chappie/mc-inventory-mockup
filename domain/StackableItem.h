//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_STACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_STACKABLEITEM_H

#include "Item.h"

class StackableItem : public Item {
protected:
    unsigned int maxStack;
public:
    StackableItem() = default;

    StackableItem(const string &_id, const string &_displayName,
                  unsigned int _maxStack = 64, bool _canPlace = false);

    StackableItem(const StackableItem &other);

    inline bool isStackable() const override { return true; }
};


#endif //MC_INVENTORY_MOCKUP_STACKABLEITEM_H
