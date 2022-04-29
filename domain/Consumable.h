//
// Created by stefa on 21.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_CONSUMABLE_H
#define MC_INVENTORY_MOCKUP_CONSUMABLE_H

enum class Effects {
    HUNGER,
    REGENERATION,
    POISON
};

#include "StackableItem.h"
#include <list>

using std::list;

class ConsumableBuilder;

class Consumable : public StackableItem {
protected:
    int saturation;
    list<Effects> effects;
public:
    friend class ConsumableBuilder;

    static ConsumableBuilder build();

    Consumable(const Consumable &_other);

    int getSaturation() const;

    list<Effects> getEffects() const;

private:
    Consumable() = default;
};

class ConsumableBuilder {
private:
    Consumable b_consumable;
public:
    friend class Consumable;

    ConsumableBuilder &withID(const string &id);

    ConsumableBuilder &withDisplayName(const string &displayName);

    ConsumableBuilder &withMaxStack(unsigned int maxStack);

    ConsumableBuilder &withSaturation(int saturation);

    ConsumableBuilder &withEffects(list<Effects> effects);

    operator Consumable &&();

};


#endif //MC_INVENTORY_MOCKUP_CONSUMABLE_H
