#include "Asiakas.h"
#include "Pankkitili.h"

#include <iostream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string nimi;
    double summa;
    int valinta;

    cout << "Anna tilin omistajan nimi: ";
    getline(cin, nimi);

    Pankkitili tili(nimi);

    while (true) {
        cout << "\nToiminnot:\n";
        cout << "1 - Talleta rahaa\n";
        cout << "2 - Nosta rahaa\n";
        cout << "3 - Näytä saldo\n";
        cout << "4 - Lopeta\n";
        cout << "Valitse toiminto: ";
        cin >> valinta;

        switch (valinta) {
        case 1: //Talletus
            cout << "Anna talletettava summa: ";
            cin >> summa;
            if (tili.deposit(summa)) {
                cout << "Talletus onnistui!\n";
            } else {
                cout << "Talletus epäonnistui!\n";
            }
            break;
        case 2: //Nosto
            cout << "Anna nostettava summa: ";
            cin >> summa;
            if (tili.withdraw(summa)) {
                cout << "Nosto onnistui!\n";
            } else {
                cout << "Nosto epäonnistui!\n";
            }
            break;

        case 3://Saldo
            cout << "Tilin saldo: " << tili.getBalance() << " euroa\n";
            break;

        case 4://Poistuminen
            cout << "Kiitos asioinnista!\n";
            return 0;

        default:
            cout << "Virheellinen valinta! Yritä uudelleen.\n";
        }
    }

    /*Asiakas asiakas1("Aapeli", 1000);

    asiakas1.talletus(250);
    asiakas1.luotonNosto(150);
    asiakas1.showSaldo();

    Asiakas asiakas2("Bertta", 1000);

    asiakas1.tiliSiirto(50, asiakas2);

    asiakas1.showSaldo();
    asiakas2.showSaldo();*/
    return 0;
}

