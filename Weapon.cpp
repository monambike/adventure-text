#include "Item.hpp"
#include "Weapon.hpp"

Weapon::Weapon(const Item& item, int damage)
    : Item(item.getName(), item.getDescription(), item.getRarity()), damage(damage) {}


int Weapon::getDamage() const {
    return damage;
}
