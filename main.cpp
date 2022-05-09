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
#include "persistence/Domain.h"

int main() {


//    CLI cli(invServ);
//
//    cli.domain = std::move(
//            vector<IItem *>{&steak, &DiamondArmour, &DiamondSword, &GoldArmour, &EnderPearl, &OakWood, &Bed});

//    cli.run();

//    InvFService fs(inventory);
//    fs.load("../data/inventory.csv");

    Domain domain;
    Repo repo(domain);
    repo.refresh();
    InventoryService invServ(repo);
    CLI cli(invServ);
    cli.run();

}