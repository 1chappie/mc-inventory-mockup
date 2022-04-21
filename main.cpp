//
// Created by stefa on 21.04.2022.
//
#include <iostream>
#include "Consumable.h"
#include "Armour.h"

int main() {

    Consumable steak = Consumable::build()
            .withID("steak")
            .withDisplayName("Steak")
            .withMaxStack(64)
            .withQuantity(1)
            .withSaturation(2)
            .withEffects(list<Effects>{Effects::POISON});

    Armour DiamondArmour = Armour::build()
            .withID("diamond_armour")
            .withDisplayName("Diamond Armour")
            .withDurabilityMax(100)
            .withDurability(100)
            .withProtectionLevel(5)
            .withEnchantments(list<aEnchantments>{
                    aEnchantments::THORNS,
                    aEnchantments::FIRE_PROTECTION});


}