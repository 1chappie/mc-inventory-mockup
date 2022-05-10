//
// Created by chappie on 10.05.2022.
//

#include "Commands.h"
#include <iostream>

void Commands::did(const Command &command) {
    this->history.push(command);
    if (!this->future.empty())
        this->future = {};
}

Command Commands::undo() {
    if (this->history.empty())
        return {comm::NULL_COMMAND, "", 0};
    else {
        Command instruction = this->history.top();
        this->future.push(instruction);
        this->history.pop();
        return instruction.reverse();
    }
}

Command Commands::redo() {
    if (this->future.empty())
        return {comm::NULL_COMMAND, "", 0};
    else {
        Command instruction = this->future.top();
        this->history.push(instruction);
        this->future.pop();
        return instruction;
    }
}
