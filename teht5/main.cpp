#include <iostream>
#include <string>

using namespace std;

class Seuraaja {
public:
    string nimi;
    Seuraaja* next;

    Seuraaja(string n) : nimi(n), next(nullptr) {}

    void paivitys(const string& viesti) {
        cout << nimi << " vastaanotti ilmoituksen: " << viesti << endl;
    }
};

class Notifikaattori {
private:
    Seuraaja* seuraajat;
public:
    Notifikaattori() : seuraajat(nullptr) {
        cout<<"Luodaan notifikaattori\n";
    }

    void lisaa(Seuraaja* uusi) {
        uusi->next = seuraajat;
        seuraajat = uusi;
    }

    void poista(Seuraaja* poistettava) {
        if (!seuraajat) return;

        if (seuraajat == poistettava) {
            seuraajat = seuraajat->next;
            return;
        }

        Seuraaja* nykyinen = seuraajat;
        while (nykyinen->next && nykyinen->next != poistettava) {
            nykyinen = nykyinen->next;
        }

        if (nykyinen->next) {
            nykyinen->next = nykyinen->next->next;
        }
    }

    void tulosta() {
        cout << "Seuraajat:\n";
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen) {
            cout << "Seuraaja " << nykyinen->nimi << endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(const string& viesti) {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }
};

int main() {
    Notifikaattori n;

    Seuraaja a("Ville");
    Seuraaja b("Pekka");
    Seuraaja c("Matias");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    cout << "\nIlmoitus saapui:\n";
    n.postita("Ensimmainen ilmoitus!");

    cout << "\nPoistetaan Pekka ja toimitetaan uusi ilmoitus:\n";
    n.poista(&b);
    n.postita("Toinen ilmoitus!");

    return 0;
}
