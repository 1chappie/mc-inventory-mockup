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
#include "FileService.h"

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

    cli.domain = std::move(
            vector<IItem *>{&steak, &DiamondArmour, &DiamondSword, &GoldArmour, &EnderPearl, &OakWood, &Bed});

    cli.run();

    FileService fs(inventory);
    fs.load("test.csv");

}