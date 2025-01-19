#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
public:
    Game(int maxNum);
    ~Game();
    int play();

private:
    int maxNum;
    int userNum;
    int randNum;
    int guessCount;
    void printGameResult() const;
};

#endif
