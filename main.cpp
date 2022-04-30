//
// Created by stefa on 21.04.2022.
//
#include <iostream>
#include "stackable/Consumable.h"
#include "unstackable/Armour.h"
#include "unstackable/Weapon.h"
#include "Repo.h"
#include "InventoryService.h"

int main() {

    Consumable steak = Consumable::build()
            .withID("steak")
            .withDisplayName("Steak")
            .withMaxStack(16)
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
    invRepo.addSlot(&steak, 10);
    invRepo.addSlot(&DiamondArmour, 1);
    invRepo.addSlot(&DiamondSword, 1);
    for (auto &i: invRepo.getAll())
        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;

    Armour DiamondArmour2 = Armour::build()
            .withID("diamond_armouvr")
            .withDisplayName("Diamond Armour")
            .withDurabilityMax(100)
            .withDurability(140)
            .withProtectionLevel(6)
            .withEnchantments(list<aEnchantments>{
                    aEnchantments::THORNS,
                    aEnchantments::FIRE_PROTECTION,
                    aEnchantments::PROTECTION});

//    std::cout << dynamic_cast<Armour *>(invRepo.getAll()[1].first)->getTooltip();

    InventoryService invService(invRepo);

    invService.give(&steak, 40);

    for (auto &i: invRepo.getAll())
        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;

//    std::cout<<invService.getLastRef(&steak).second<<std::endl;

//    std::cout << invService.total(&DiamondArmour2) << std::endl;

//    invService.add(&DiamondArmour2, 1);
//    std::cout<<invRepo.firstSlotWhere(&steak).second;
//    std::cout<<(nullptr == invService.getLastRef(&DiamondArmour2))<<std::endl;

//    invService.getAll()[0].second = 10;

//    invRepo.getAll()[0].second = 69;

//    std::cout<<invService.getAll()[0].second<<std::endl;

//    std::cout << invRepo.getAll()[0].second << std::endl;



//    invRepo.updateSlot(&DiamondArmour2, 1);

//    std::cout << invRepo.getAll()[1].first->getTooltip() << std::endl;
//
//    invRepo.updateSlotAt(1, &DiamondSword);

//    std::cout << invRepo.getAll()[1].first->getTooltip() << std::endl;
//
//    invRepo.addSlot(&DiamondArmour, 1);

//    std::cout << invRepo.size() << std::endl;

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
//
//    std::cout << invRepo.slotAt(0).first->getTooltip() << std::endl;


}