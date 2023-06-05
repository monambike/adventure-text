#include "Item.h"
#include "Weapon.h"

Weapon::Weapon(const Item& item, int damage)
    : Item(item.getName(), item.getDescription(), item.getRarity()), damage(damage) {}
