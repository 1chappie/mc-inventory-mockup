//
// Created by chappie on 20.04.2022.
//

#include "UnstackableItem.h"
#include <algorithm>


UnstackableItem::UnstackableItem(const string &_id, const string &_displayName) :
        IItem(_id, _displayName, true),
        hasDurability(false),
        durability(0),
        durabilityMax(0) {}

UnstackableItem::UnstackableItem(const string &_id, const string &_displayName, unsigned int _durability,
                                 unsigned int _durabilityMax) :
        IItem(_id, _displayName, false),
        hasDurability(true),
        durability(_durability),
        durabilityMax(_durabilityMax) {}

UnstackableItem::UnstackableItem(const UnstackableItem &other) :
        IItem(other.id, other.displayName, other.canPlace),
        hasDurability(other.hasDurability),
        durability(other.durability),
        durabilityMax(other.durabilityMax) {}

unsigned int UnstackableItem::getDurability() const {
    return this->durability;
}

void UnstackableItem::setDurability(unsigned int _quantity) {
    this->durability = _quantity;
}

int UnstackableItem::addDurability(int _quantity) {
    int newDurability = this->durability + _quantity;
    this->durability = std::clamp<int>(newDurability, 0, this->durabilityMax);
    return newDurability;
}

string UnstackableItem::getTooltip() const {
    string tooltip;
    tooltip += this->displayName + "\n" + this->id + "\n";
    if (this->hasDurability)
        tooltip += "Durability: " +
                   std::to_string(this->durability) + "/" +
                   std::to_string(this->durabilityMax) + "\n";
    return tooltip;
}
