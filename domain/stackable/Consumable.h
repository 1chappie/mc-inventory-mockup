//
// Created by stefa on 21.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_CONSUMABLE_H
#define MC_INVENTORY_MOCKUP_CONSUMABLE_H

#include "StackableItem.h"
#include <list>

enum class Effects {
    HUNGER,
    REGENERATION,
    POISON
};

using std::list;

class ConsumableBuilder;

class Consumable : public StackableItem {
protected:
    int saturation;
    list<Effects> effects;
public:
    friend class ConsumableBuilder;

    /**
     * Builder for consumable items. Static function that creates a consumable.
     * @example
     * <code>
     * Consumable apple = Consumable::build()<br>
     *              .withID("apple")<br>
     *              .withDisplayName("Apple")<br>
     *              .withMaxStack(64)<br>
     *              .withSaturation(5)<br>
     *              .withEffects(list\<Effects\>{Effects::REGENERATION});
     * </code>
     * @return ConsumableBuilder, which can be converted to Consumable
     */
    static ConsumableBuilder build();

    /**
     * Copy constructor
     * @param _other Another instance of a consumable.
     */
    Consumable(const Consumable &_other);

    /**
     * Gets the saturation of the consumable.
     * @return Saturation.
     */
    int getSaturation() const;

    /**
     * Get a list of the effects of the consumable.
     * @return list\<Effects\>
     */
    list<Effects> getEffects() const;

    string itemType() const override { return "consumable"; }

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

    //this defines the behaviour of the Consumable copy constructor in relation to the builder
    operator Consumable &&();

};


#endif //MC_INVENTORY_MOCKUP_CONSUMABLE_H
