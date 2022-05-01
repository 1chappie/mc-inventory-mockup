//
// Created by stefa on 30.04.2022.
//

#include "CLI.h"
#include <utility>

CLI::CLI(InventoryService &invServ) : invServ(&invServ) {}

void CLI::printInventory() {
    std::ostringstream oss;
    oss << "# INVENTORY - ";
    oss << std::to_string(this->invServ->total()) << " items, ";
    oss << std::to_string(this->invServ->getAll().size()) << " slots\n";
    for (auto &i: this->invServ->getAll()) {
        oss << "\t[" << std::setw(3) << std::to_string(i.second) << "] " << i.first->getDisplayName() << "\n";
    }
    std::cout << oss.str();
}

void CLI::hdM_printDomain() {
    std::ostringstream oss;
    for (auto &i: this->domain) {
        oss << std::endl << std::setw(20) << "[" + i->getID() + "] ";
        oss << "\"" << i->getDisplayName() << "\"";
        if (i->isStackable()) oss << " (stackable)";
    }
    std::cout << oss.str();
}

void CLI::domainManager() {
    while (true) {
        std::cout << "## DOMAIN MANAGER - manage available item types\n";
        this->hdM_printDomain();
        std::cout << std::endl << std::endl;
        std::cout << " a: create new    d: delete existing    q: back \n\n";
        std::cout << ">> ";
        std::string option;
        std::cin >> option;
        std::string id_todel;
        switch (option[0]) {
            case 'a':
                this->hdM_domainWizard();
                break;
            case 'd':
                std::cout << "ID of item to be deleted: ";
                std::cin >> id_todel;
                this->hdM_delete(id_todel);
                break;
            case 'q':
                return;
            default:
                std::cout << "Invalid option\n";
                break;
        }
    }
}

void CLI::hdM_domainWizard() {
    std::cout << "\n### DOMAIN ITEM WIZARD - create new item types\n\n";
    std::cout << "Item name:";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    std::cout << "Item ID:";
    std::string id;
    std::cin >> id;
    if (std::find_if(this->domain.begin(), this->domain.end(),
                     [id](IItem *item) {
                         return item->getID() == id;
                     }) != this->domain.end()) {
        std::cout << "Item with ID \"" << id << "\" already exists! \n";
        return;
    }
    std::cout << "Is stackable? (y/n):";
    bool isStackable;
    std::string input;
    std::cin >> input;
    if (input == "y" || input == "Y") isStackable = true;
    else isStackable = false;
    if (isStackable) {
        std::cout << "Enter maximum stack size:";
        unsigned int stackSize;
        std::cin >> stackSize;
        std::cout << "Is consumable? (y/n):";
        bool isConsumable;
        std::cin >> input;
        if (input == "y" || input == "Y") isConsumable = true;
        else isConsumable = false;
        if (isConsumable) {
            int saturation;
            std::cout << "Enter saturation:";
            std::cin >> saturation;
            static Consumable newConsumable = Consumable::build()
                    .withID(id)
                    .withDisplayName(name)
                    .withMaxStack(stackSize)
                    .withSaturation(saturation)
                    .withEffects(std::list<Effects>());
            this->domain.push_back(dynamic_cast<IItem *>(&newConsumable));
        } else {
            bool canPlace;
            std::cout << "Can be placed? (y/n) ";
            std::cin >> input;
            if (input == "y" || input == "n") canPlace = true;
            else canPlace = false;
            static StackableItem newStackable = StackableItem(id, name, stackSize, canPlace);
            this->domain.push_back(dynamic_cast<IItem *>(&newStackable));
        }
    } else {
        std::cout << "Armour/ weapon/ none of these? (a/w/n):";
        std::string type;
        std::cin >> type;
        unsigned int durabilityMax;
        unsigned int durabilityCurrent;
        switch (type[0]) {
            case 'a':
                std::cout << "Max durability:";
                std::cin >> durabilityMax;
                std::cout << "Current durability:";
                std::cin >> durabilityCurrent;
                unsigned int protection;
                std::cout << "Protection level:";
                std::cin >> protection;
                static Armour newArmour = Armour::build()
                        .withID(id)
                        .withDisplayName(name)
                        .withDurabilityMax(durabilityMax)
                        .withDurability(durabilityCurrent)
                        .withProtectionLevel(protection)
                        .withEnchantments(std::list<aEnchantments>());
                this->domain.push_back(dynamic_cast<IItem *>(&newArmour));
                break;
            case 'w':
                std::cout << "Max durability:";
                std::cin >> durabilityMax;
                std::cout << "Current durability:";
                std::cin >> durabilityCurrent;
                unsigned int damage;
                std::cout << "Damage:";
                std::cin >> damage;
                static Weapon newWeapon = Weapon::build()
                        .withID(id)
                        .withDisplayName(name)
                        .withDurabilityMax(durabilityMax)
                        .withDurability(durabilityCurrent)
                        .withDamage(damage)
                        .withEnchantments(std::list<wEnchantments>());
                this->domain.push_back(dynamic_cast<IItem *>(&newWeapon));
                break;
            default:
                std::cout << "Has durability? (y/n):";
                bool hasDurability;
                std::cin >> input;
                if (input == "y" || input == "Y") hasDurability = true;
                else hasDurability = false;
                if (hasDurability) {
                    std::cout.flush();
                    std::cout << "Max durability:"; //????????????????????????????????????????
                    std::cin >> durabilityMax;
                    std::cout << "Current durability:";
                    std::cin >> durabilityCurrent;
                    static UnstackableItem newUnstackable = UnstackableItem(id, name, durabilityCurrent, durabilityMax);
                    this->domain.push_back(dynamic_cast<IItem *>(&newUnstackable));
                } else {
                    static UnstackableItem newUnstackable = UnstackableItem(id, name);
                    this->domain.push_back(dynamic_cast<IItem *>(&newUnstackable));
                }
                break;
        }
    }
    std::cout << "Item created!\n\n";
}

void CLI::hdM_delete(std::string id) {
    for (auto it = this->domain.begin(); it != this->domain.end(); it++) {
        if ((*it)->getID() == id) {
            this->domain.erase(it);
            std::cout << "Item deleted!\n\n";
            return;
        }
    }
    std::cout << "Item not found!\n\n";
}

void CLI::commandParser(std::string command) {
    std::istringstream iss(command);
    std::string commandName, arg1, arg2;
    iss >> commandName >> arg1 >> arg2;
    if (commandName == "give")
        this->hcP_giveCommand(arg1, arg2);
    else if (commandName == "clear")
        this->hcP_clearCommand(arg1, arg2);
    else if (commandName == "enchant")
        this->hcP_enchantCommand(arg1);
    else if (commandName == "domain")
        this->domainManager();
    else if (commandName == "focus")
        this->hcP_focusCommand(arg1);
    else if (commandName == "help")
        this->hcP_printHelp();
    else if (commandName == "quit" || commandName == "q" || commandName == "exit")
        exit(0);
    else
        std::cout << "Unknown command. Type \"help\" for help.\n";
}

void CLI::hcP_enchantCommand(std::string id) {
    try {
        string eqpType = dynamic_cast<UnstackableItem *>(this->invServ->getLastRef(id)->first)->equipmentType();
        if (eqpType == "armour") {
            EnchantmentService::enchant(dynamic_cast<Armour *>(this->invServ->getLastRef(id)->first));
        } else if (eqpType == "weapon") {
            EnchantmentService::enchant(dynamic_cast<Weapon *>(this->invServ->getLastRef(id)->first));
        } else {
            std::cout << "Item cannot be enchanted\n";
        }
    } catch (EnchantException e) {
        std::cout << e.what() << std::endl;
    }
}

void CLI::hcP_giveCommand(std::string id, std::string amount) {
    auto it = std::find_if(this->domain.begin(), this->domain.end(), [&id](IItem *item) {
        return item->getID() == id;
    });
    auto item = this->domain[std::distance(this->domain.begin(), it)];
    if (it == this->domain.end()) {
        std::cout << "Invalid item. Check \"domain\" for available item types.\n\n";
    } else {
        try {
            int amt;
            if (amount == "") amt = 1;
            else amt = std::stoi(amount);
            if (amt <= 0) throw std::invalid_argument("Invalid amount");
            this->invServ->give(item, amt);
            std::cout << "Given [" << item->getDisplayName() << "] x " << amt << " to Steve\n\n";
        } catch (std::invalid_argument e) {
            std::cout << "Invalid amount\n\n";
            return;
        }
    }
}

void CLI::hcP_clearCommand(std::string id, std::string amount) {
    if (id == "") {
        std::cout << "Cleared the inventory of Steve, removing " << this->invServ->total() << " items\n\n";
        this->invServ->clear();
        return;
    }
    auto it = std::find_if(this->domain.begin(), this->domain.end(), [&id](IItem *item) {
        return item->getID() == id;
    });
    auto item = this->domain[std::distance(this->domain.begin(), it)];
    if (it == this->domain.end()) {
        std::cout << "Invalid item. Check \"domain\" for available item types.\n\n";
    } else {
        try {
            int amt;
            if (amount == "") amt = 1;
            else amt = std::stoi(amount);
            if (amt <= 0) throw std::invalid_argument("Invalid amount");
            this->invServ->clear(item, amt);
            std::cout << "Cleared [" << item->getDisplayName() << "] x " << amt << " from Steve\n\n";
        } catch (std::invalid_argument e) {
            std::cout << "Invalid amount\n\n";
            return;
        }
    }
}

void CLI::hcP_focusCommand(std::string index) {
    try {
        unsigned int i = stoi(index);
        auto ref = this->invServ->repo->slotAt(i);
        while (true) {
            std::cout << "## SLOT FOCUS - details about item and slot\n\n";
            std::cout << ref.first->getTooltip();
            std::cout << "Items in slot: " << ref.second << "\n";
            std::cout << "Items in inventory: " << this->invServ->total(ref.first) << "\n";
            std::cout << std::endl;
            std::cout << " d: clear slot    q: back \n\n";
            std::cout << ">> ";
            std::string option;
            std::cin >> option;
            switch (option[0]) {
                case 'd':
                    std::cout << "Slot cleared\n\n";
                    this->invServ->repo->popSlotAt(i);
                    return;
                case 'q':
                    return;
                default:
                    std::cout << "Invalid option\n";
                    break;
            }
        }
    }
    catch (RepoException e) {
        std::cout << "Invalid index\n";
        return;
    }
    catch (std::invalid_argument e) {
        std::cout << "Invalid index\n";
        return;
    }

}

void CLI::hcP_printHelp() {
    std::ostringstream oss;
    oss << "List of available commands:\n";
    oss << ">>give <id> [amount] - add item to the inventory\n"
        << ">>clear <id> [amount] - clear item from the inventory\n"
        << ">>clear - clear all items\n"
        << ">>enchant <id> - randomly enchant an item (Weapon or Armour)\n"
        << ">>focus <slot-index> - details about a specific inventory slot\n"
        << ">>domain - manage available item types\n"
        << ">>help - this menu\n"
        << ">>quit - close the app\n\n";
    std::cout << oss.str();
}

void CLI::run() {
    std::string command;
    while (true) {
        this->printInventory();
        std::cout << ">>";
        std::getline(std::cin >> std::ws, command);
        this->commandParser(command);
    }
}
