#include "ItalianChef.h"

using namespace std;

ItalianChef::ItalianChef(string name): Chef(name) {
    cout << "Italian created! " << name << endl;
}
ItalianChef::~ItalianChef(){
    cout<<"Italian "<<chefName<<" destructor"<<endl;
}
int ItalianChef::makePizza(int flourAmount, int waterAmount) {
    int pizzasFlour = flourAmount / 5;
    int pizzasWater = waterAmount / 5;
    return std::min(pizzasFlour, pizzasWater);
}
bool ItalianChef::askSecret(string inputPassword, int flourAmount, int waterAmount) {
    if (inputPassword == password) {

        int pizzas = makePizza(flourAmount, waterAmount);
        cout << "Pizzas made: " << pizzas << endl;
        return true;
    } else {
        cout << "Wrong password! Cannot make pizza." << endl;
        return false;
    }
}
