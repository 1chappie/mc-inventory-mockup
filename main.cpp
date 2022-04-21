//
// Created by stefa on 21.04.2022.
//
#include <iostream>
#include "Consumable.h"

int main() {

    Consumable steak = Consumable::build()
            .withID("steak")
            .withDisplayName("Steak")
            .withMaxStack(64)
            .withQuantity(1)
            .withSaturation(2)
            .withEffects(list<Effects>{Effects::POISON});

}