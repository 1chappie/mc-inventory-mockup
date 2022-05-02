//
// Created by stefa on 30.04.2022.
//

#include "EnchantmentService.h"

//maybe TODO? make it so enchantments myst be unique - but i need bigger enums

void EnchantmentService::enchant(Armour *armour) {
    if (armour == nullptr)
        throw EnchantException("Null reference");
    if (armour->getEnchantments().size() == 5) {
        throw EnchantException("An item can't have more than 5 enchantments");
    } else {
        srand(time(0));
        armour->enchantments.push_back(aEnchantments(rand() % 10));
    }
}

void EnchantmentService::enchant(Weapon *weapon) {
    if (weapon == nullptr)
        throw EnchantException("Null reference");
    if (weapon->getEnchantments().size() == 5) {
        throw EnchantException("An item can't have more than 5 enchantments");
    } else {
        srand(time(0));
        weapon->enchantments.push_back(wEnchantments(rand() % 5));
    }
}
