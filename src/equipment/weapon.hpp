// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "item.hpp"

class Weapon : public Item {
private:
    int damage;
public:
    // Getter methods
    int getDamage() const;

    Weapon(const Item& item, int damage);
};

#endif
