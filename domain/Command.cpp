//
// Created by chappie on 10.05.2022.
//

#include "Command.h"

Command::Command(comm c, string id, unsigned int qty) : command(c), id(id), qty(qty) {}

Command Command::reverse() {
    if (this->command == comm::GIVE)
        return {comm::CLEAR, this->id, this->qty};
    else if (this->command == comm::CLEAR)
        return {comm::GIVE, this->id, this->qty};
    else
        return {comm::NULL_COMMAND, "", 0};
}

comm Command::getCommand() {
    return this->command;
}

string Command::getId() {
    return this->id;
}

unsigned int Command::getQty() {
    return this->qty;
}
