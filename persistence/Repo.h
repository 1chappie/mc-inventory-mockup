//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPO_H
#define MC_INVENTORY_MOCKUP_REPO_H

#include <vector>
#include <algorithm>
#include "../exceptions/RepoException.hpp"
#include <utility>
#include "../domain/IItem.h"

using std::vector;
using std::pair, std::make_pair;

class Repo {
protected:
    vector<pair<IItem *, unsigned int>> slots;

public:
    friend class InventoryService;

    Repo();

    Repo(const Repo &other);

    ~Repo() = default;

    virtual void addSlot(IItem *, unsigned int _qty);

    //find an item by id and replace it
    virtual void updateSlot(IItem *, unsigned int _qty = 0);

    //find an item by index replace it
    virtual void updateSlotAt(unsigned int, IItem *, unsigned int _qty = 0);

    //by id
    virtual void popSlot(IItem *);

    //by index
    virtual void popSlotAt(unsigned int);

    virtual pair<IItem *, unsigned int> &lastSlotWhere(IItem *);

    virtual pair<IItem *, unsigned int> &firstSlotWhere(IItem *);

    virtual pair<IItem *, unsigned int> &slotAt(unsigned int);

    virtual vector<pair<struct IItem *, unsigned int>> &getAll();

    virtual int size();
};


#endif //MC_INVENTORY_MOCKUP_REPO_H
