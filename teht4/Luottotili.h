#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"
#include <string>
using namespace std;

class Luottotili : public Pankkitili {
public:
    Luottotili(string omistaja, double raja);
    bool withdraw(double amount) override;
    bool depositLuotto(double amount);

protected:
    double luottoraja;
};

#endif // LUOTTOTILI_H
