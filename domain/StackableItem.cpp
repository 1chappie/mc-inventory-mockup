//
// Created by chappie on 20.04.2022.
//

#include "StackableItem.h"

StackableItem::StackableItem(unsigned int _maxStack, unsigned int _quantity,
                             const string &_id, const string &_displayName, bool _canPlace) :
        maxStack(_maxStack), quantity(_quantity) {
    this->id = _id;
    this->displayName = _displayName;
    this->canPlace = _canPlace;
}

unsigned int StackableItem::getQuantity() const {
    return this->quantity;
}

void StackableItem::setQuantity(unsigned int _quantity) {
    this->quantity = _quantity;
}

void StackableItem::add(unsigned int _quantity) {
    this->quantity += _quantity;
    //TODO make it so if the quantity is bigger than the maxStack, new item is added in repo
}

void StackableItem::spend() {
    if (this->quantity) this->quantity--;
}

void StackableItem::spend(unsigned int _quantity) {
    if (this->quantity >= _quantity)
        this->quantity -= _quantity;
    else
        quantity = 0;
    //TODO if quantity is 0, remove item from repo
}
