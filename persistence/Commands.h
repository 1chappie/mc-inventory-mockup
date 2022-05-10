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
    // This class acts as a repository for commands.
    // history - past commands
    stack<Command> history;
    // future - commands that had been "undo"d and they now live here,
    // that until they are either "redo"d or the state of the inventory is updated - which clears the "future"
    stack<Command> future;
public:
    Commands() = default;

    /**
     * Adds a command to the history and clears the future (redo states).
     * @param command command
     */
    void did(const Command &command);

    /**
     * Returns the last command in history, but reversed;
     * adds the original state of the command to the 'future' stack;
     * pops the command from history.
     * @return top command in history in reversed form
     */
    Command undo();

    /**
     * Returns the last command in "future";
     * adds it to the history;
     * pops it from the "future" stack.
     * @return top command in future
     */
    Command redo();
};


#endif //MC_INVENTORY_MOCKUP_COMMANDS_H
