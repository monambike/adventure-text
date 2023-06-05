// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

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
protected:
    std::string name;
    std::string description;
    Rarity rarity;
public:
    Item(std::string name, std::string description, Rarity rarity);
    
    // Getter methods
    std::string getName() const;
    std::string getDescription() const;
    Rarity getRarity() const;

    void showDetailedInfo();
    void displayName();
};

#endif
