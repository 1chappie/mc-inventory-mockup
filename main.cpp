//
// Created by stefa on 21.04.2022.
//
#include <iostream>
#include "stackable/Consumable.h"
#include "unstackable/Armour.h"
#include "unstackable/Weapon.h"
#include "Repo.h"
#include "InventoryService.h"
#include "EnchantmentService.h"
#include "interface/CLI.h"

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

    Armour GoldArmour = Armour::build()
            .withID("gold_armour")
            .withDisplayName("Gold Armour")
            .withDurabilityMax(60)
            .withDurability(30)
            .withProtectionLevel(3)
            .withEnchantments(list<aEnchantments>{
                    aEnchantments::THORNS,
                    aEnchantments::FIRE_PROTECTION,
                    aEnchantments::PROTECTION});

    StackableItem EnderPearl = StackableItem{"ender_pearl", "Ender Pearl", 16};

    StackableItem OakWood = StackableItem{"oak_wood", "Oak Wood", 64};

    UnstackableItem Bed = UnstackableItem{"bed", "Bed"};

    Repo inventory;

    InventoryService invServ(inventory);

    invServ.give(&steak, 40);

    invServ.give(&DiamondArmour);

    invServ.give(&DiamondSword, 2);

    invServ.give(&GoldArmour);

    invServ.give(&EnderPearl, 30);

    invServ.give(&OakWood, 100);

    invServ.give(&Bed);

    CLI cli(invServ);

//    cli.printInventory();

    cli.domain = std::move(
            vector<IItem *>{&steak, &DiamondArmour, &DiamondSword, &GoldArmour, &EnderPearl, &OakWood, &Bed});

//    cli.domainManager();
    cli.run();

//    Repo invRepo;
//    invRepo.addSlot(&steak, 10);
//    invRepo.addSlot(&DiamondArmour, 1);
//    invRepo.addSlot(&DiamondSword, 1);
//    std::cout << "Initial Inventory" << std::endl;
//    for (auto &i: invRepo.getAll())
//        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;
//    std::cout << std::endl;

//    std::cout << dynamic_cast<Armour *>(invRepo.getAll()[1].first)->getTooltip();

//    InventoryService invService(invRepo);
//
//    invService.give(&steak, 40);
//
//    CLI CLIApp(invService);
//
//    CLIApp.printInventory();
//
//    invService.give(&steak, 40);
//
//    CLIApp.printInventory();

//    std::cout << "After giving 40 steak" << std::endl;
//    for (auto &i: invRepo.getAll())
//        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;
//    std::cout << std::endl;
//
//    invService.clear(&steak, 100);
//    invService.give(&DiamondArmour2, 3);
//    invService.clear(&DiamondArmour2);

//    std::cout << "After clearing 100 steak" << std::endl;
//    for (auto &i: invRepo.getAll())
//        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;
//    std::cout << std::endl;
//
//    invService.clear();
//
//    std::cout << "After clearing" << std::endl;
//    for (auto &i: invRepo.getAll())
//        std::cout << i.second << " " << i.first->getDisplayName() << std::endl;
//
//    EnchantmentService::enchant(&DiamondArmour2);
//    EnchantmentService::enchant(&DiamondArmour2);
//
//    std::cout << "After enchanting" << std::endl;
//    std::cout<<DiamondArmour2.getTooltip()<<std::endl;

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