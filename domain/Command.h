//
// Created by chappie on 10.05.2022.
//

#ifndef MC_INVENTORY_MOCKUP_COMMAND_H
#define MC_INVENTORY_MOCKUP_COMMAND_H
#include <string>
using std::string;

enum class comm {
    GIVE, CLEAR, NULL_COMMAND
};

class Command {
private:
    comm command;
    string id;
    unsigned int qty;
public:
    /**
     * Constructor for Command
     * @param c Command type enum comm::(give, clear)
     * @param id id of the item
     * @param qty quantity
     */
    Command(comm c, string id, unsigned int qty);

    Command() = delete;

    /**
     * Reverse a command and return its opposite
     * @return opposite command
     */
    Command reverse();

    /**
     * Get the command type
     * @return comm::(give, clear)
     */
    comm getCommand();

    /**
     * Get the id of the item
     * @return id
     */
    string getId();

    /**
     * Get the quantity
     * @return quantity
     */
    unsigned int getQty();
};


#endif //MC_INVENTORY_MOCKUP_COMMAND_H
