#include <iostream>
#include <cstdlib>

using namespace std;

int game(int maxnum) {
    int userNum, randNum;
    int guessCount = 0;

    srand(time(0));
    randNum = rand() % maxnum + 1;

    do {
        cout << "Arvaa numeroa (1 - " << maxnum << "): ";
        cin >> userNum;
        guessCount++;

        if (userNum == randNum) {
            cout << "Arvasit oikein! Arvattu numero: " << userNum << ", Tietokoneen arvaus: " << randNum << endl;
        }
        else if (userNum < randNum) {
            cout << "Arvaus on liian pieni." << endl;
        }
        else {
            cout << "Arvaus on liian iso." << endl;
        }
    } while (userNum != randNum);

    return guessCount;
}

int main() {
    int maxnum;

    cout << "Syötä korkein etsittävä luku: ";
    cin >> maxnum;

    int totalGuesses = game(maxnum);
    cout << "Arvausten määrä: " << totalGuesses << endl;

    return 0;
}
