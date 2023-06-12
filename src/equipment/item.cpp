// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include "item.hpp"
#include "../utilities/terminal_utils.hpp"

Item::Item(std::string name, std::string description, Rarity rarity)
    : name(name), description(description), rarity(rarity) {}


std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

Rarity Item::getRarity() const {
    return rarity;
}

Color Item::getRarityColor() const {
    switch (rarity) {
        case COMMON: return WHITE;
        case UNCOMMON: return BLUE;
        case RARE: return CYAN;
        case EPIC: return MAGENTA;
        case LEGENDARY: return YELLOW;
        default: throw std::runtime_error("Unable to determine item color for current item rarity");
    }
}

void Item::displayName() {
    TerminalUtils::changeTerminalTextColor(getRarityColor());
    std::cout << name;
    TerminalUtils::changeTerminalTextColor(WHITE);
}

void Item::showDetailedInfo() {
    std::cout << "Name: ";
    displayName();
    std::cout << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
}
