#include "Game.h"
#include <iostream>

int main() {
    int maxNum;

    std::cout << "Enter highest number to search for: ";
    std::cin >> maxNum;

    Game game(maxNum);
    game.play();

    return 0;
}
