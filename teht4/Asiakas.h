#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>
#include "Pankkitili.h"
#include "Luottotili.h"

using namespace std;

class Asiakas {
public:
    Asiakas(string n, double raja);
    void showSaldo() const;
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonNosto(double amount);
    bool luotonMaksu(double amount);
    bool tiliSiirto(double amount, Asiakas &vastaanottaja);
private:
    string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
