// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include "item.hpp"
#include "weapon.hpp"

Weapon::Weapon(const Item& item, int damage)
    : Item(item.getName(), item.getDescription(), item.getRarity()), damage(damage) {}


int Weapon::getDamage() const {
    return damage;
}
