#include "Chef.h"
#include "ItalianChef.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int saladA,soupA,flour,water;
    string password;
    Chef chef("Chef Gordon");

    cout<<chef.getName()<<"! Give ingredients for salad: ";
    cin>>saladA;
    cout<<"Give ingredients for soup: ";
    cin>>soupA;
    cout<<"Salad's made "<<chef.makeSalad(saladA)<<"! Soup's made "<<chef.makeSoup(soupA)<<"!"<<endl;


    ItalianChef italianChef("Chef Mario");

    cout<<italianChef.getName()<<"! Give ingredients for salad: ";
    cin>>saladA;
    cout<<"Give ingredients for soup: ";
    cin>>soupA;
    cout<<"Salad's made "<<italianChef.makeSalad(saladA)<<endl;
    cout<<"Soup's made "<<italianChef.makeSoup(soupA)<<endl;

    cout<<"Password check for secret recipe: ";
    cin>>password;
    cout<<italianChef.getName()<<"! Give ingredients for pizza"<<endl<<"Amount of flour: ";
    cin>>flour;
    cout<<"Amount of water: ";
    cin>>water;
    italianChef.askSecret(password, flour, water);

    return 0;
}
