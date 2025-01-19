#include "Game.h"

using namespace std;

Game::Game(int maxNum) {
    this->maxNum = maxNum;
    srand(time(0));
    randNum = rand() % maxNum + 1;
    guessCount = 0;

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNum << " as a maximum value" << endl;
}

int Game::play() {
    do {
        cout << "Give your guess between 1-" << maxNum << ": ";
        cin >> userNum;
        guessCount++;

        if (userNum == randNum) {
            cout << "Your guess is correct"<< endl;
        } else if (userNum < randNum) {
            cout << "Your guess is too small" << endl;
        } else {
            cout << "Your guess is too big" << endl;
        }
    } while (userNum != randNum);

    printGameResult();

    return guessCount;
}


void Game::printGameResult() const {
    cout << "You guessed the right answer " << randNum
         << " with " << guessCount << " guesses" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}
