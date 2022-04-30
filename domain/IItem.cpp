//
// Created by chappie on 20.04.2022.
//

#include "IItem.h"

string IItem::getID() const {
    return this->id;
}

string IItem::getDisplayName() const {
    return this->displayName;
}

IItem::IItem(const string &_id, const string &_displayName, const bool &_canPlace) {
    this->id = _id;
    this->displayName = _displayName;
    this->canPlace = _canPlace;
}

IItem::IItem() {
    this->id = "null";
}

bool IItem::operator==(const IItem &other) const {
    return this->id == other.id;
}
