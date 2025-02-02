#include "Luottotili.h"

Luottotili::Luottotili(string omistaja, double raja) : Pankkitili(omistaja), luottoraja(raja) {
    cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoraja << "\n";
}

bool Luottotili::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Virhe: Ei voi nostaa negatiivista summaa.\n";
        return false;
    }

    if ((saldo - amount) >= -luottoraja) {
        saldo -= amount;
        cout << "Luottotili: nosto " << amount << " tehty, luottoa jäljellä "
                  << (luottoraja + saldo) << "\n";
        return true;
    } else {
        cout << "Virhe: Nostaminen ylittäisi luottorajan.\n";
        return false;
    }
}
bool Luottotili::depositLuotto(double amount) {
    if (amount > 0 && saldo + amount <= 0) {
        saldo += amount;
        return true;
    }
    return false;
}

