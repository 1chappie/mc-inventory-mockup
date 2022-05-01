//
// Created by stefa on 21.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_WEAPON_H
#define MC_INVENTORY_MOCKUP_WEAPON_H

#include "UnstackableItem.h"
#include <list>
#include <map>

enum class wEnchantments {
    SHARPNESS,
    KNOCKBACK,
    FIRE_ASPECT,
    LOOTING
};

class WeaponBuilder;

class Weapon : public UnstackableItem {
protected:
    unsigned int damage;
    std::list<wEnchantments> enchantments;
public:
    friend class EnchantmentService;

    friend class WeaponBuilder;

    static WeaponBuilder build();

    Weapon(const Weapon &other);

    unsigned int getDamage() const;

    std::list<wEnchantments> getEnchantments() const;

    int use();

    string getTooltip() const override;

    string equipmentType() const { return "weapon"; }

private:
    Weapon() = default;
};

class WeaponBuilder {
private:
    Weapon b_weapon;
public:
    friend class Weapon;

    WeaponBuilder &withID(const string &_id);

    WeaponBuilder &withDisplayName(const string &_displayName);

    WeaponBuilder &withDurabilityMax(unsigned int _durabilityMax);

    WeaponBuilder &withDurability(unsigned int _durability);

    WeaponBuilder &withDamage(unsigned int _damage);

    WeaponBuilder &withEnchantments(std::list<wEnchantments> _enchantment);

    operator Weapon &&();

    string equipmentType() const { return "weapon"; }

};

#endif //MC_INVENTORY_MOCKUP_WEAPON_H
