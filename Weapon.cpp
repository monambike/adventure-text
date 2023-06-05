#include "Item.h"
#include "Weapon.h"

Weapon::Weapon(const Item& item, int damage)
    : Item(item.name, item.description, item.rarity), damage(damage) {}
