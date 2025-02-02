#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>
#include <string>
using namespace std;

class Pankkitili {
public:
    Pankkitili(string omistaja);
    virtual ~Pankkitili();
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double getBalance() const;
protected:
    double saldo;
    string nimi;
};

#endif // PANKKITILI_H
