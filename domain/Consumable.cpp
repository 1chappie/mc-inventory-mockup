//
// Created by stefa on 21.04.2022.
//

#include "Consumable.h"

Consumable::Consumable(const Consumable &_other, unsigned int _quantity) :
        StackableItem(_other.id, _other.displayName, _other.quantity,
                      _other.maxStack, _other.canPlace),
        saturation(_other.saturation),
        effects(_other.effects) {
    if (_quantity) this->quantity = _quantity;
}

int Consumable::getSaturation() const {
    return this->saturation;
}

list<Effects> Consumable::getEffects() const {
    return this->effects;
}

int Consumable::consume() {
    return this->addQuantity(-1);
}

ConsumableBuilder &ConsumableBuilder::withID(const string &id) {
    this->b_consumable.id = id;
    return *this;
}

ConsumableBuilder &ConsumableBuilder::withDisplayName(const string &displayName) {
    this->b_consumable.displayName = displayName;
    return *this;
}

ConsumableBuilder &ConsumableBuilder::withMaxStack(unsigned int maxStack) {
    this->b_consumable.maxStack = maxStack;
    return *this;
}

ConsumableBuilder &ConsumableBuilder::withQuantity(unsigned int quantity) {
    this->b_consumable.quantity = quantity;
    return *this;
}

ConsumableBuilder &ConsumableBuilder::withSaturation(int saturation) {
    this->b_consumable.saturation = saturation;
    return *this;
}

ConsumableBuilder &ConsumableBuilder::withEffects(list<Effects> effects) {
    this->b_consumable.effects = std::move(effects);
    return *this;
}

ConsumableBuilder::operator Consumable &&() {
    return std::move(this->b_consumable);
}

ConsumableBuilder Consumable::build() {
    return {};
}
