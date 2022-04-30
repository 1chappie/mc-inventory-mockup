//
// Created by stefa on 30.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H
#define MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H

#include "../domain/unstackable/Armour.h"
#include "../domain/unstackable/Weapon.h"

class EnchantmentService {
public:
    static void enchant(Armour *);

    static void enchant(Weapon *);
};


#endif //MC_INVENTORY_MOCKUP_ENCHANTMENTSERVICE_H
