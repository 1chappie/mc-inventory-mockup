//
// Created by stefa on 21.04.2022.
//

#include "Armour.h"

Armour::Armour(const Armour &_other) :
        UnstackableItem(_other.id, _other.displayName, _other.durability, _other.durabilityMax),
        protectionLevel(_other.protectionLevel),
        enchantments(_other.enchantments) {}

unsigned int Armour::getProtectionLevel() const {
    return this->protectionLevel;
}

std::list<aEnchantments> Armour::getEnchantments() const {
    return this->enchantments;
}

int Armour::damage() {
    return this->addDurability(-1);
}

ArmourBuilder Armour::build() {
    return {};
}

ArmourBuilder &ArmourBuilder::withID(const string &_id) {
    this->b_armour.id = _id;
    return *this;
}

ArmourBuilder &ArmourBuilder::withDisplayName(const string &_displayName) {
    this->b_armour.displayName = _displayName;
    return *this;
}

ArmourBuilder &ArmourBuilder::withDurabilityMax(unsigned int _durabilityMax) {
    this->b_armour.durabilityMax = _durabilityMax;
    return *this;
}

ArmourBuilder &ArmourBuilder::withDurability(unsigned int _durability) {
    this->b_armour.durability = _durability;
    return *this;
}

ArmourBuilder &ArmourBuilder::withProtectionLevel(unsigned int _protectionLevel) {
    this->b_armour.protectionLevel = _protectionLevel;
    return *this;
}

ArmourBuilder &ArmourBuilder::withEnchantments(std::list<aEnchantments> _enchantments) {
    this->b_armour.enchantments = std::move(_enchantments);
    return *this;
}

ArmourBuilder::operator Armour &&() {
    return std::move(this->b_armour);
}
