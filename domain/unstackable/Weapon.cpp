//
// Created by stefa on 21.04.2022.
//

#include "Weapon.h"

std::map<wEnchantments, std::string> wEnchantmentNames = {
        {wEnchantments::SHARPNESS,   "Sharpness"},
        {wEnchantments::KNOCKBACK,   "Knockback"},
        {wEnchantments::FIRE_ASPECT, "Fire Aspect"},
        {wEnchantments::LOOTING,     "Looting"}
};

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

string Weapon::getTooltip() const {
    string tooltip;
    tooltip += this->getDisplayName() + "\n" + this->getID() + "\n";
    tooltip += "Durability: " +
               std::to_string(this->durability) + "/" +
               std::to_string(this->durabilityMax) + "\n";
    tooltip += "Damage: " +
               std::to_string(this->damage) + "\n";
    if (!this->enchantments.empty()) {
        tooltip += "Enchantments: \n";
        for (auto enchantment: this->enchantments)
            tooltip += "\"" + wEnchantmentNames[enchantment] + "\"\n";
    }
    return tooltip;
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
