//
// Created by chappie on 20.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H
#define MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H

#include "IItem.h"

class UnstackableItem : public IItem {
protected:
    bool hasDurability;
    unsigned int durability;
    unsigned int durabilityMax;
public:
    UnstackableItem() = default;

    /**
     * Constructor for generic unstackable item without durability
     * @param _id ID of the item.
     * @param _displayName Name of the item.
     */
    UnstackableItem(const string &_id, const string &_displayName);

    /**
     * Constructor for generic unstackable item with durability
     * @param _id ID of the item.
     * @param _displayName Name of the item.
     * @param _durability The current durability of the item.
     * @param _durabilityMax The maximum durability of the item.
     */
    UnstackableItem(const string &_id, const string &_displayName,
                    unsigned int _durability, unsigned int _durabilityMax);

    /**
     * Copy constructor for generic unstackable items.
     * @param other UnstackableItem instance.
     */
    UnstackableItem(const UnstackableItem &other);

    /**
     * Get the durability of the item.
     * @return current durability
     */
    unsigned int getDurability() const;

    /**
     * Get the maximum durability of the item.
     * @return maximum durability
     */
    unsigned int getDurabilityMax() const;

    /**
     * Set the durability of the item. <br>
     * <u>This method is unsafe - values are not clamped. addDurability() should be used instead.</u>
     * @param _quantity new durability
     */
    void setDurability(unsigned int _quantity);

    /**
     * Add/subtract durability to/from the item. <br>
     * This is the proper way of modifying the durability of items, <br>
     * since the value is clamped between 0 and durabilityMax.
     * @param _quantity quantity to add/subtract (int)
     * @return the unclamped value of the new durability (can be used to manage overflows in service)
     */
    int addDurability(int _quantity);

    inline bool isStackable() const override { return false; }

    string getTooltip() const override;

    /**
     * Returns the equipment type.
     * @return "armour" / "weapon" / "none" for non-equippable (string)
     */
    string itemType() const override { return "unstackable-item"; }

};


#endif //MC_INVENTORY_MOCKUP_UNSTACKABLEITEM_H
