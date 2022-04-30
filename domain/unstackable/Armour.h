//
// Created by stefa on 21.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ARMOUR_H
#define MC_INVENTORY_MOCKUP_ARMOUR_H

#include "UnstackableItem.h"
#include <list>
#include <map>

enum class aEnchantments {
    PROTECTION,
    FIRE_PROTECTION,
    FEATHER_FALLING,
    BLAST_PROTECTION,
    PROJECTILE_PROTECTION,
    RESPIRATION,
    AQUA_AFFINITY,
    THORNS,
    DEPTH_STRIDER
};

class ArmourBuilder;

class Armour : public UnstackableItem {
protected:
    unsigned int protectionLevel;
    std::list<aEnchantments> enchantments;
public:
    friend class EnchantmentService;

    friend class ArmourBuilder;

    static ArmourBuilder build();

    Armour(const Armour &_other);

    unsigned int getProtectionLevel() const;

    std::list<aEnchantments> getEnchantments() const;

    int use();

    string getTooltip() const override;

private:
    Armour() = default;
};

class ArmourBuilder {
private:
    Armour b_armour;
public:
    friend class Armour;

    ArmourBuilder &withID(const string &_id);

    ArmourBuilder &withDisplayName(const string &_displayName);

    ArmourBuilder &withDurabilityMax(unsigned int _durabilityMax);

    ArmourBuilder &withDurability(unsigned int _durability);

    ArmourBuilder &withProtectionLevel(unsigned int _protectionLevel);

    ArmourBuilder &withEnchantments(std::list<aEnchantments> _enchantment);

    operator Armour &&();

};

#endif //MC_INVENTORY_MOCKUP_ARMOUR_H
