#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Item.h"

class Weapon : public Item {
public:
    int damage;

    Weapon(const Item& item, int damage);
};

#endif
