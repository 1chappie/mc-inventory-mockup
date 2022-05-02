//
// Created by stefa on 30.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H
#define MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H

#include "../domain/unstackable/Armour.h"
#include "../domain/unstackable/Weapon.h"
#include "../exceptions/EnchantException.hpp"

class EnchantmentService {
public:

    /**
     * Give a random aEnnchantment to an armour item.
     * @param _armour Reference to Armour item.
     * @throws EnchantException if 5 enchantments are exceeded.
     */
    static void enchant(Armour *_armour);

    /**
     * Give a random wEnnchantment to a weapon.
     * @param weapon Reference to Weapon item.
     * @throws EnchantException if 5 enchantments are exceeded.
     */
    static void enchant(Weapon *_weapon);
};


#endif //MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H
