#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Item.hpp"

class Weapon : public Item {
private:
    int damage;
public:
    // Getter methods
    int getDamage() const;

    Weapon(const Item& item, int damage);
};

#endif
