//
// Created by chappie on 20.04.2022.
//

#include "UnstackableItem.h"
#include <algorithm>


UnstackableItem::UnstackableItem(const string &_id, const string &_displayName) :
        Item(_id, _displayName, true),
        hasDurability(false),
        durability(0),
        durabilityMax(0) {}

UnstackableItem::UnstackableItem(const string &_id, const string &_displayName, unsigned int _durability,
                                 unsigned int _durabilityMax) :
        Item(_id, _displayName, false),
        hasDurability(true),
        durability(_durability),
        durabilityMax(_durabilityMax) {}

UnstackableItem::UnstackableItem(const UnstackableItem &other) :
        Item(other.id, other.displayName, other.canPlace),
        hasDurability(other.hasDurability),
        durability(other.durability),
        durabilityMax(other.durabilityMax) {}

unsigned int UnstackableItem::getDurability() const {
    return this->durability;
}

unsigned int UnstackableItem::setDurability(unsigned int _quantity) {
    this->durability = _quantity;
    return this->durability;
}

int UnstackableItem::addDurability(int _quantity) {
    int newDurability = this->durability + _quantity;
    this->durability = std::clamp<int>(newDurability, 0, this->durabilityMax);
    return newDurability;
}
