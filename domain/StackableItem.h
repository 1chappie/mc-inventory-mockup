//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_STACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_STACKABLEITEM_H

#include "Item.h"

class StackableItem : public Item {
protected:
    unsigned int maxStack;
    unsigned int quantity;
public:
    StackableItem() = default;

    StackableItem(const string &_id, const string &_displayName,
                  unsigned int _quantity, unsigned int _maxStack = 64, bool _canPlace = false);

    StackableItem(const StackableItem &other, unsigned int _quantity = 0);

    unsigned int getQuantity() const;

    unsigned int setQuantity(unsigned int _quantity);

    int addQuantity(int _quantity);
};


#endif //MC_INVENTORY_MOCKUP_STACKABLEITEM_H
