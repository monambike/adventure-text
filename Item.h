#ifndef ITEM_H
#define ITEM_H

#include <iostream>

enum Rarity {
    COMMON,
    RARE,
    EPIC,
    GODLIKE
};

class Item {
public:
    std::string name;
    std::string description;
    Rarity rarity;

    Item(string name, string description, Rarity rarity);

    void ShowItemProperties();
    void GetItemName();
};

#endif
