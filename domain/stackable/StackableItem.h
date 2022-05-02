//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_STACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_STACKABLEITEM_H

#include "IItem.h"

class StackableItem : public IItem {
protected:
    unsigned int maxStack;
public:
    StackableItem() = default;

    /**
     * Constructor of generic stackable item.
     * @param _id ID of the item.
     * @param _displayName Name of the item.
     * @param _maxStack Maximum stack size of the item. Defaults to 64.
     * @param _canPlace If the item can (theoretically) be placed down or not. Defaults to false.
     */
    StackableItem(const string &_id, const string &_displayName,
                  unsigned int _maxStack = 64, bool _canPlace = false);

    /**
     * Copy constructor of generic stackable item.
     * @param other Another instance of a stackable item.
     */
    StackableItem(const StackableItem &other);

    /**
     * Get the maximum stack size of the item.
     * @return Maxiumum stack size uint.
     */
    unsigned int getMaxStack() const;

    inline bool isStackable() const override { return true; }

    string getTooltip() const override;
};


#endif //MC_INVENTORY_MOCKUP_STACKABLEITEM_H
