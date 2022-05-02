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

    // Accessed via the "domain" command, the domain manager
    // allows the user to delete or add new item types.
    void domainManager();

    void hdM_printDomain();

    // This function starts an item-creation wizard
    // that asks the user for input to choose the
    // appropriate item class and properties.
    void hdM_domainWizard();

    // This removes an item type from the domain.
    // Removing an item type from the domain does not mean that said
    // item type will be removed from the inventory (although it probably should).
    // It just means that the "give" command won't recognize it anymore.
    void hdM_delete(std::string);

    // This takes the keyboard input from the user and splits it into
    // 3 parts: the command, argument 1 and argument 2.
    // It matches the command, and then it sends
    // the arguments to the appropriate function.
    void commandParser(std::string command);

    // Wrapper for the give() command in the service.
    void hcP_giveCommand(std::string, std::string);

    // Wrapper for the clear() command in the service.
    void hcP_clearCommand(std::string, std::string);

    void hcP_printHelp();

    // Accessed via the "focus <index>" command, this
    // opens up a submenu that allows the user to inspect a specific slot
    // and the item type in it.
    void itemFocus(std::string);

    // As part of the focus submenu, this is a wrapper
    // for EnchantmentService::enchant().
    void hiF_enchant(unsigned int id);

public:
    /*
     * The domain vector acts as the item metadata storage that the CLI app
     * is referring to for all its operations. In order to add a new
     * item type to the inventory, the user has to first create it
     * inside the domain. This is done via the "domain" command.
     */
    vector<IItem *> domain;

    /**
     * Constructor
     * @param invServ reference to InventoryService
     */
    CLI(InventoryService &invServ);

    //The default constructor is deleted, because a service should be linked.
    CLI() = delete;

    /**
     * Print the slots of the current inventory. First slot is slot[0].
     */
    void printInventory();

    /**
     * Run the CLI app. Entry point of the program. <br>
     * The CLI instance must be initialized with a valid InventoryService instance, <br>
     * that's itself linked to a Repo.
     * <br><br>
     * [CLI] -> [InventoryService] -> [Repo]
     */
    void run();
};


#endif //MC_INVENTORY_MOCKUP_CLI_H
