#include "Pankkitili.h"


Pankkitili::Pankkitili(string omistaja) : saldo(0), nimi(omistaja) {
    cout << "Pankkitili luotu " << nimi << ":lle\n";
}

Pankkitili::~Pankkitili() {}


bool Pankkitili::deposit(double amount) {
    if (amount > 0) {
        saldo += amount;
        cout << "Pankkitili: talletus " << amount << " tehty\n";
        return true;
    } else {
        cout << "Virhe: negatiivinen talletus ei ole sallittu.\n";
        return false;
    }
}


bool Pankkitili::withdraw(double amount) {
    if (amount > 0 && saldo >= amount) {
        saldo -= amount;
        cout << "Pankkitili: nosto " << amount << " tehty\n";
        return true;
    } else if (amount <= 0) {
        cout << "Virhe: negatiivinen nosto ei ole sallittu.\n";
    } else {
        cout << "Virhe: tilin saldo ei riitä nostoon.\n";
    }
    return false;
}
double Pankkitili::getBalance() const {
    return saldo;
}
