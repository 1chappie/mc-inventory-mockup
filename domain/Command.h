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
    Command(comm c, string id, unsigned int qty);

    Command() = delete;

    Command reverse();

    comm getCommand();

    string getId();

    unsigned int getQty();
};


#endif //MC_INVENTORY_MOCKUP_COMMAND_H
