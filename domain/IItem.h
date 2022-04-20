//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_IITEM_H
#define MC_INVENTORY_MOCKUP_IITEM_H

#include <string>

using std::string;

class IItem {
protected:
    string id;
    string displayName;
    //TODO Image icon; for the UI
    bool canPlace;
public:
    string getID() const;

    string getDisplayName() const;

    virtual void spend() = 0;
};


#endif //MC_INVENTORY_MOCKUP_IITEM_H
