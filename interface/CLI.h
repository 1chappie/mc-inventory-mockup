//
// Created by stefa on 30.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_CLI_H
#define MC_INVENTORY_MOCKUP_CLI_H

#include "../service/InventoryService.h"
#include "../service/EnchantmentService.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class CLI {
private:
    InventoryService *invServ;

    void domainManager();

    void hdM_printDomain();

    void hdM_domainWizard();

    void hdM_delete(std::string);

    void commandParser(std::string command);

    void hcP_enchantCommand(std::string id);

    void hcP_giveCommand(std::string, std::string);

    void hcP_clearCommand(std::string, std::string);

    void hcP_focusCommand(std::string);

    void hcP_printHelp();

public:
    vector<IItem *> domain;

    CLI(InventoryService &invServ);

    CLI() = delete;

    void printInventory();

    void run();
};


#endif //MC_INVENTORY_MOCKUP_CLI_H
