//
// Created by stefa on 21.04.2022.
//
#include <iostream>
#include "stackable/Consumable.h"
#include "unstackable/Armour.h"
#include "unstackable/Weapon.h"
#include "Repo.h"

int main() {

    Consumable steak = Consumable::build()
            .withID("steak")
            .withDisplayName("Steak")
            .withMaxStack(64)
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

    Weapon DiamondSword = Weapon::build()
            .withID("diamond_sword")
            .withDisplayName("Diamond Sword")
            .withDurabilityMax(100)
            .withDurability(100)
            .withDamage(7)
            .withEnchantments(list<wEnchantments>{
                    wEnchantments::FIRE_ASPECT,
                    wEnchantments::KNOCKBACK});

    Repo invRepo;
    invRepo.addSlot(&steak, 1);
    invRepo.addSlot(&DiamondArmour, 1);
    for (auto &i: invRepo.getAll())
        std::cout << i.first->getDisplayName() << std::endl;

    std::cout << dynamic_cast<Armour *>(invRepo.getAll()[1].first)->getTooltip();

    invRepo.updateSlot(&steak, 20);
    std::cout << invRepo.getAll()[0].second << std::endl;

    Armour DiamondArmour2 = Armour::build()
            .withID("diamond_armour")
            .withDisplayName("Diamond Armour")
            .withDurabilityMax(100)
            .withDurability(140)
            .withProtectionLevel(6)
            .withEnchantments(list<aEnchantments>{
                    aEnchantments::THORNS,
                    aEnchantments::FIRE_PROTECTION,
                    aEnchantments::PROTECTION});

    invRepo.updateSlot(&DiamondArmour2, 1);

    std::cout << invRepo.getAll()[1].first->getTooltip() << std::endl;

    invRepo.updateSlotAt(1, &DiamondSword);

    std::cout << invRepo.getAll()[1].first->getTooltip() << std::endl;

    invRepo.addSlot(&DiamondArmour, 1);

    std::cout << invRepo.size() << std::endl;

//    invRepo.popSlot(&DiamondSword);
//
//    std::cout << invRepo.getAll()[1].first->getTooltip()<<std::endl;
//
//    std::cout<<invRepo.size()<<std::endl;
//
//    std::cout << invRepo.getAll()[0].first->getTooltip()<<std::endl;
//
//    invRepo.popSlotAt(0);
//
//    std::cout << invRepo.getAll()[0].first->getTooltip()<<std::endl;
//
//    std::cout<<invRepo.size()<<std::endl;

    std::cout << invRepo.slotAt(0).first->getTooltip() << std::endl;


}