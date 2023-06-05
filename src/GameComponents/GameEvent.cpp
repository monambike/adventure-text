// Copyright(c) 2023-present, Vinícius Gabriel (@monambike)
// Distributed under Creative Commons License (https://creativecommons.org/licenses/by/4.0/)

#include <iostream>
#include "GameActions.hpp"
#include "GameEvent.hpp"

void GameEvent::strangeCandyEvent() {
    std::string question =
R"(A wild vendor appears and try to give you one mysterious candy. You
have the option to accept it.)";

    std::string actions[] = {"Buy", "\"I'm not buying your weird candy!\"", "", "" };
    GameActions::triggerBaseEvent(question, actions);
}
