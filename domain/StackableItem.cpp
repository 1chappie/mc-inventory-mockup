//
// Created by chappie on 20.04.2022.
//

#include "StackableItem.h"
#include <algorithm>

StackableItem::StackableItem(const string &_id, const string &_displayName,
                             unsigned int _maxStack, bool _canPlace) :
        Item(_id, _displayName, _canPlace),
        maxStack(_maxStack) {}

StackableItem::StackableItem(const StackableItem &other) :
        Item(other.id, other.displayName, other.canPlace),
        maxStack(other.maxStack) {}



