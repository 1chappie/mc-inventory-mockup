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

    /**
     * Builder for weapons. Static function that creates a weapon.
     * @example
     * <code>
     * Weapon DiamondSword = Weapon::build()<br>
     *              .withID("diamond_sword")<br>
     *              .withDisplayName("Diamond Sword")<br>
     *              .withDurabilityMax(200)<br>
     *              .withDurability(140)<br>
     *              .withDamage(7)<br>
     *              .withEnchantments(list\<wEnchantments\>{wEnchantments::SHARPNESS, wEnchantments::FIRE_ASPECT});<br>
     * </code>
     * @return WeaponBuilder, which can be converted to Weapon
     */
    static WeaponBuilder build();

    /**
     * Copy constructor
     * @param _other Weapon instance to copy
     */
    Weapon(const Weapon &other);

    /**
     * Get the damage of the weapon
     * @return damage
     */
    unsigned int getDamage() const;

    /**
     * Get the enchantments of the weapon
     * @return list\<wEnchantments\>
     */
    std::list<wEnchantments> getEnchantments() const;

    /**
     * Wear the weapon by one point (durability--)
     * @return new durability
     */
    int use();

    string getTooltip() const override;

    string itemType() const override { return "weapon"; }

    bool isEnchantable() const override { return true; }

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

    //this defines the behaviour of the Armour copy constructor in relation to the builder
    operator Weapon &&();

};

#endif //MC_INVENTORY_MOCKUP_WEAPON_H
