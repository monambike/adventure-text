#include "Item.h"
#include "TerminalUtils.h"

Item::Item(std::string name, std::string description, Rarity rarity)
    : name(name), description(description), rarity(rarity) {}

void Item::GetName() {
    switch (rarity) {
        case COMMON: TerminalUtils::ChangeTerminalTextColor(WHITE); break;
        case UNCOMMON: TerminalUtils::ChangeTerminalTextColor(BLUE); break;
        case RARE: TerminalUtils::ChangeTerminalTextColor(CYAN); break;
        case EPIC: TerminalUtils::ChangeTerminalTextColor(MAGENTA); break;
        case LEGENDARY: TerminalUtils::ChangeTerminalTextColor(YELLOW); break;
    }
    std::cout << name;
    TerminalUtils::ChangeTerminalTextColor(WHITE);
}

void Item::ShowItemProperties() {
    std::cout << "Name: ";
    GetName();
    std::cout << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
}
