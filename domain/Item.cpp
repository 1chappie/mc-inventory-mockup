//
// Created by chappie on 20.04.2022.
//

#include "Item.h"

string Item::getID() const {
    return this->id;
}

string Item::getDisplayName() const {
    return this->displayName;
}

Item::Item(const string &_id, const string &_displayName, const bool &_canPlace) {
    this->id = _id;
    this->displayName = _displayName;
    this->canPlace = _canPlace;
}

Item::Item() {
    this->id = "null";
}
