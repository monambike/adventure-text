#ifndef ITEM_H
#define ITEM_H

#include <iostream>

enum Rarity {
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

class Item {
public:
    std::string name;
    std::string description;
    Rarity rarity;

    Item(std::string name, std::string description, Rarity rarity);

    void ShowItemProperties();
    void GetName();
};

#endif
