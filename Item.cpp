#include "iostream"
#include "Item.h"
#include "TerminalUtils.h"

// MyClass myObject("Broken Knife", COMMON);

Item::Item(string name, string description, Rarity rarity) : name(name), description(description), rarity(rarity) {}

void Item::ShowItemProperties() {
    std::cout << "Name: ";
    GetItemName();
    std::cout << std::endl;
    std::cout << "Rarity: " << Item::rarity << std::endl;
}


void Item::GetItemName() {
    switch (rarity) {
        case COMMON: TerminalUtils::ChangeTerminalTextColor(BLUE); break;
        case RARE: TerminalUtils::ChangeTerminalTextColor(CYAN); break;
        case EPIC: TerminalUtils::ChangeTerminalTextColor(MAGENTA); break;
        case GODLIKE: TerminalUtils::ChangeTerminalTextColor(YELLOW); break;
    }
    cout << name;
    TerminalUtils::ChangeTerminalTextColor(WHITE);
}