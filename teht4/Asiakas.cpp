#include "Asiakas.h"
#include <iostream>

Asiakas::Asiakas(string n, double luottoraja) : nimi(n), pankkitili(n), luottotili(n, luottoraja) {
    cout << "Asiakkuus luotu " << nimi << "\n";
    showSaldo();
}

void Asiakas::showSaldo() const {
    cout << "\n" << nimi << "\n";
    cout << "Käyttötilin saldo " << pankkitili.getBalance() << "\n";
    cout << "Luottotilin saldo " << luottotili.getBalance() << "\n";
}

bool Asiakas::talletus(double amount) {
    return pankkitili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return pankkitili.withdraw(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.depositLuotto(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (amount > 0 && pankkitili.withdraw(amount)) {
        cout << "Pankkitili: " << nimi << " siirtää " << amount << " " << vastaanottaja.nimi << ":lle\n";
        return vastaanottaja.pankkitili.deposit(amount);
    }
    return false;
}
