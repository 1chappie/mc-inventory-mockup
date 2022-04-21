//
// Created by chappie on 20.04.2022.
//

#include "StackableItem.h"
#include <algorithm>

StackableItem::StackableItem(const string &_id, const string &_displayName,
                             unsigned int _quantity, unsigned int _maxStack, bool _canPlace) :
        Item(_id, _displayName, _canPlace),
        quantity(_quantity),
        maxStack(_maxStack) {}

StackableItem::StackableItem(const StackableItem &other, unsigned int _quantity) :
        Item(other.id, other.displayName, other.canPlace),
        maxStack(other.maxStack) {
    // This constructor and setQuantity intentionally allow the user to ignore the maxStack value
    // Overflows or underflows should be handled by the service.
    if (quantity) this->quantity = _quantity;
    else this->quantity = other.quantity;
}

unsigned int StackableItem::getQuantity() const {
    return this->quantity;
}

unsigned int StackableItem::setQuantity(unsigned int _quantity) {
    // Intentionally broken-ish
    this->quantity = _quantity;
    return _quantity;
}

int StackableItem::addQuantity(int _quantity) {
    int newQuantity = this->quantity + _quantity;
    this->quantity = std::clamp<int>(newQuantity, 1, this->maxStack);
    return newQuantity;
}


