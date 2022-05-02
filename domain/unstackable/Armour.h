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

    /**
     * Builder for armour. Static function that creates an armour.
     * @example
     * <code>
     * Armour DiamondChestplate = Armour::build()<br>
     *              .withID("diamond_chestplate")<br>
     *              .withDisplayName("Diamond Chestplate")<br>
     *              .withDurabilityMax(200)<br>
     *              .withDurability(140)<br>
     *              .withProtectionLevel(5)<br>
     *              .withEnchantments(list\<aEnchantments\>{aEnchantments::PROTECTION, aEnchantments::THORNS});<br>
     * </code>
     * @return ArmourBuilder, which can be converted to Armour
     */
    static ArmourBuilder build();

    /**
     * Copy constructor
     * @param _other Armour instance to copy
     */
    Armour(const Armour &_other);

    /**
     * Get the protection level of the armour
     * @return protection level
     */
    unsigned int getProtectionLevel() const;

    /**
     * Get the enchantments of the armour
     * @return list\<aEnchantments\>
     */
    std::list<aEnchantments> getEnchantments() const;

    /**
     * Wear the armour by one point (durability--)
     * @return new durability
     */
    int use();

    string getTooltip() const override;

    string equipmentType() const override { return "armour"; }

    bool isEnchantable() const override { return true; }

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

    //this defines the behaviour of the Armour copy constructor in relation to the builder
    operator Armour &&();

};

#endif //MC_INVENTORY_MOCKUP_ARMOUR_H
