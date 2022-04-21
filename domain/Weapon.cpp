//
// Created by stefa on 21.04.2022.
//

#include "Weapon.h"

Weapon::Weapon(const Weapon &other) :
        UnstackableItem(other.id, other.displayName, other.durability, other.durabilityMax),
        damage(other.damage),
        enchantments(other.enchantments) {}

unsigned int Weapon::getDamage() const {
    return this->damage;
}

std::list<wEnchantments> Weapon::getEnchantments() const {
    return this->enchantments;
}

int Weapon::use() {
    return this->addDurability(-1);
}

WeaponBuilder Weapon::build() {
    return {};
}

WeaponBuilder &WeaponBuilder::withID(const string &_id) {
    this->b_weapon.id = _id;
    return *this;
}

WeaponBuilder &WeaponBuilder::withDisplayName(const string &_displayName) {
    this->b_weapon.displayName = _displayName;
    return *this;
}

WeaponBuilder &WeaponBuilder::withDurabilityMax(unsigned int _durabilityMax) {
    this->b_weapon.durabilityMax = _durabilityMax;
    return *this;
}

WeaponBuilder &WeaponBuilder::withDurability(unsigned int _durability) {
    this->b_weapon.durability = _durability;
    return *this;
}

WeaponBuilder &WeaponBuilder::withDamage(unsigned int _damage) {
    this->b_weapon.damage = _damage;
    return *this;
}

WeaponBuilder &WeaponBuilder::withEnchantments(std::list<wEnchantments> _enchantment) {
    this->b_weapon.enchantments = std::move(_enchantment);
    return *this;
}

WeaponBuilder::operator Weapon &&() {
    return std::move(this->b_weapon);
}
