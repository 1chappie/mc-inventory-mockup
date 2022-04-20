//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_STACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_STACKABLEITEM_H

#include "IItem.h"

class StackableItem : public IItem {
protected:
    unsigned int maxStack;
    unsigned int quantity;
public:
    StackableItem(unsigned int _maxStack, unsigned int _quantity,
                  const string &_id, const string &_displayName, bool _canPlace = false);

    unsigned int getQuantity() const;

    void setQuantity(unsigned int _quantity);

    void add(unsigned int _quantity);

    void spend() override;

    void spend(unsigned int _quantity);
};


#endif //MC_INVENTORY_MOCKUP_STACKABLEITEM_H
