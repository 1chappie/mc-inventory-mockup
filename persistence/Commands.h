//
// Created by chappie on 10.05.2022.
//

#ifndef MC_INVENTORY_MOCKUP_COMMANDS_H
#define MC_INVENTORY_MOCKUP_COMMANDS_H

#include <stack>
#include "../domain/Command.h"

using std::stack;

class Commands {
private:
    stack<Command> history;
    stack<Command> future;
public:
    Commands() = default;

    void did(const Command &command);

    Command undo();

    Command redo();
};


#endif //MC_INVENTORY_MOCKUP_COMMANDS_H
