#pragma warning( disable : 4996)
#include <iostream>
#include <list>
#include "Racun.h"
#include "Kurs.h"
#include "Banka.h"


//RACUN

Datum Racun::getDatumNastankaRacuna()const {
    return datum_nastanka_racuna;
}

int Racun::getBrojRacuna()const {
    return broj_racuna;
}

bool Racun::getPrekoracenje()const {
    return prekoracenje;
}

double Racun::getMaxPrekoracenje()const {
    return max_prekoracenja;
}

std::list<int> Racun::getIdTransakcija()const {
    return id_transakcija;
}

double Racun::getMaxDodavanja()const {
    return max_dodavanja;
}

double Racun::getMaxSkidanja()const {
    return max_skidanja;
}

void Racun::setDatumNastankaRacuna(Datum datum) {
    datum_nastanka_racuna = datum;
}

void Racun::setBrojRacuna(int broj_racuna_) {
    broj_racuna = broj_racuna_;
}

void Racun::setPrekoracenje(bool prekoracenje_) {
    prekoracenje = prekoracenje_;
}

void Racun::setMaxPrekoracenje(double max_prekoracenja_) {
    max_prekoracenja = max_prekoracenja_;
}

void Racun::setIdTransakcija(std::list<int> id_transakcija_) {
    id_transakcija = id_transakcija_;
}


void Racun::setMaxDodavanja(double max_dodavanja_) {
    max_dodavanja = max_dodavanja_;
}


void Racun::setMaxSkidanja(double max_skidanja_) {
    max_skidanja = max_skidanja_;
}


std::ostream& operator<<(std::ostream& os, const Racun& racun) {

    os << "Datum nastanka racuna : " << std::endl;
    os << racun.datum_nastanka_racuna << std::endl;
    os << "Broj racuna : " << racun.broj_racuna << std::endl;
    os << "Dozvoljeni minus / prekoracenje : ";
    if (racun.prekoracenje) {
        os << "DA" << std::endl;
        os << "MAX prekoracenje : " << racun.max_prekoracenja << std::endl;
    }
    else
    {
        os << "NE" << std::endl;
    }
    os << "MAX Depozit : " << racun.max_skidanja << std::endl;
    os << "MAX novca za dodavanje : " << racun.max_dodavanja << std::endl;

    return os;
}

//DINARSKI RACUN

DinarskiRacun::DinarskiRacun() {
    
    id++;
    datum_nastanka_racuna = Datum(datum);
    broj_racuna = id;
    prekoracenje = false;
    max_skidanja = 5000;
    max_prekoracenja = 0;
    max_dodavanja = 5000;
    stanje_na_racunu_RSD = 0;
}

DinarskiRacun::DinarskiRacun(Datum datum_izdavanja_racuna,  bool prekoracenje_, std::list<int> id_transakcija_, double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje) {

    id++;
    datum_nastanka_racuna = datum_izdavanja_racuna;
    broj_racuna = id;
    prekoracenje = prekoracenje_;
    id_transakcija = id_transakcija_;
    max_skidanja = max_depozit_;
    max_prekoracenja = max_prekoracenje_;
    max_dodavanja = max_dodavanja_;
    stanje_na_racunu_RSD = stanje;
}

DinarskiRacun::DinarskiRacun(const DinarskiRacun& racun) {

    id++;
    datum_nastanka_racuna = racun.datum_nastanka_racuna;
    broj_racuna = id;
    prekoracenje = racun.prekoracenje;
    id_transakcija = racun.id_transakcija;
    max_skidanja = racun.max_skidanja;
    max_prekoracenja = racun.max_prekoracenja;
    max_dodavanja = racun.max_dodavanja;
    stanje_na_racunu_RSD = racun.stanje_na_racunu_RSD;
}

double DinarskiRacun::getStanjeNaRacunuRSD()const {
    return stanje_na_racunu_RSD;
}
void DinarskiRacun::setStanjeNaRacunuRSD(double stanje_na_racunu_RSDD) {
    stanje_na_racunu_RSD = stanje_na_racunu_RSDD;
}
void DinarskiRacun::Deposit(double* kes) {

    double novac;

    if (*kes == 0) {
        std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
        return;
    }

    while (5)
    {

        std::cout << "Unesite svotu novca u RSD koju hocete da dodate na racun : " << std::endl;
        std::cin >> novac;
        if (novac > max_dodavanja || novac <= 0) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }
        if (*kes - novac < 0) {
            std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
            continue;
        }

        break;
    }

    *kes -= novac;
    stanje_na_racunu_RSD += novac;
}
void DinarskiRacun::Withdraw(double* kes) {

    if (prekoracenje) {
        if (stanje_na_racunu_RSD == -max_prekoracenja) {
            std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
            return;
        }
    }
    else
    {
        if (stanje_na_racunu_RSD == 0) {
            std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
            return;
        }
    }

    double novac;

    while (5)
    {
        std::cout << "Koliko para hocete da skinete sa racuna : " << std::endl;
        std::cin >> novac;
        if (novac <= 0 || novac > max_skidanja) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }

        if (prekoracenje) {
            if (stanje_na_racunu_RSD - novac < -max_prekoracenja) {
                std::cout << "Ne mozete toliko para podici sa racuna !!!" << std::endl;
                continue;
            }
        }

        break;
    }

    *kes += novac;
    stanje_na_racunu_RSD -= novac;
}
std::ostream& operator<<(std::ostream& os, const DinarskiRacun& racun) {

    os << "*** DINARSKI RACUN *** " << std::endl;
    os << (const Racun&)racun << std::endl;
    os << "Stanje na racunu RSD : " << racun.stanje_na_racunu_RSD << std::endl;

    return os;
}
int DinarskiRacun::id = -1;

//DEVIZNI RACUN

DevizniRacun::DevizniRacun() {
    id++;
    datum_nastanka_racuna = Datum(datum);
    broj_racuna = id;
    prekoracenje = false;
    max_skidanja = 5000;
    max_prekoracenja = 0;
    max_dodavanja = 5000;
    stanje_na_racunu_EVRO = 0;
}

DevizniRacun::DevizniRacun(Datum datum_izdavanja_racuna, bool prekoracenje_, std::list<int> id_transakcija_,double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje) {

    id++;
    datum_nastanka_racuna = datum_izdavanja_racuna;
    broj_racuna = id;
    prekoracenje = prekoracenje_;
    id_transakcija = id_transakcija_;
    max_skidanja = max_depozit_;
    max_prekoracenja = max_prekoracenje_;
    max_dodavanja = max_dodavanja_;
    stanje_na_racunu_EVRO = stanje;
}

DevizniRacun::DevizniRacun(const DevizniRacun& racun) {

    id++;
    datum_nastanka_racuna = racun.datum_nastanka_racuna;
    broj_racuna = id;
    prekoracenje = racun.prekoracenje;
    id_transakcija = racun.id_transakcija;
    max_skidanja = racun.max_skidanja;
    max_prekoracenja = racun.max_prekoracenja;
    max_dodavanja = racun.max_dodavanja;
    stanje_na_racunu_EVRO = racun.stanje_na_racunu_EVRO;
}

double DevizniRacun::getStanjeNaRacunuEVRO()const {
    return stanje_na_racunu_EVRO;
}
void DevizniRacun::setStanjeNaRacunuEVRO(double stanje_na_racunu_EVRO_) {
    stanje_na_racunu_EVRO = stanje_na_racunu_EVRO_;
}
void DevizniRacun::Deposit(double* kes) {

    *kes = *kes * kurs.getRSDPRODAJNA(); // prebacaj u evre
    double novac;

    if (*kes == 0) {
        std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
        return;
    }

    while (5)
    {

        std::cout << "Unesite svotu novca u RSD koju hocete da dodate na racun : " << std::endl;
        std::cin >> novac;
        if (novac > max_dodavanja || novac <= 0) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }
        novac = novac * kurs.getRSDPRODAJNA();
        if (*kes - novac < 0) {
            std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
            continue;
        }

        break;
    }

    *kes -= novac;
    *kes = *kes / kurs.getRSD(); // vracenje u dinare
    stanje_na_racunu_EVRO += novac;
}
void DevizniRacun::Withdraw(double* kes) {

    if (prekoracenje) {
        if (stanje_na_racunu_EVRO == -max_prekoracenja) {
            std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
            return;
        }
    }
    else
    {
        if (stanje_na_racunu_EVRO == 0) {
            std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
            return;
        }
    }

    double novac;

    while (5)
    {
        std::cout << "Koliko para hocete da skinete sa racuna : " << std::endl;
        std::cin >> novac;
        if (novac <= 0) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }

        novac = novac * kurs.getRSDPRODAJNA(); // prebacivanje u evro

        if (prekoracenje) {
            if (stanje_na_racunu_EVRO - novac < -max_prekoracenja) {
                std::cout << "Ne mozete toliko para podici sa racuna !!!" << std::endl;
                continue;
            }
        }

        break;
    }

    stanje_na_racunu_EVRO -= novac; // skidam u evrima
    novac = novac / kurs.getRSD(); // vracam u dinare
    *kes += novac; // dodajem u dinarima

}
std::ostream& operator<<(std::ostream& os, const DevizniRacun& racun) {

    os << "*** DINARSKI RACUN *** " << std::endl;
    os << (const Racun&)racun << std::endl;
    os << "Stanje na racunu EVRO : " << racun.stanje_na_racunu_EVRO << std::endl;
    
    
    

    return os;
}
int DevizniRacun::id = -1;

void CitajDevRacune(std::list<DevizniRacun> lista) {
    FILE* dat = fopen("devizni.txt", "r");
    if (dat == NULL) {
        printf("Greska pri citanju!\n");
        exit;
    }
    int d;
    int m;
    int g;
    int broj_racuna;
    bool prekoracenje;
    double max_skidanja;
    double max_prekoracenja;
    double max_dodavanja;
    while (5) {
        fscanf(dat, "%i", &d);
        fgetc(dat);
        if (feof(dat)) {
            break;
        }
        fscanf(dat, "%i", &m);
        fgetc(dat);
        fscanf(dat, "%i", &g);
        fgetc(dat);
        fscanf(dat, "%i", &broj_racuna);
        fgetc(dat);
        fscanf(dat, "%i", &prekoracenje);
        fgetc(dat);
        fscanf(dat, "%i", &max_skidanja);
        fgetc(dat);
        fscanf(dat, "%i", &max_prekoracenja);
        fgetc(dat);
        fscanf(dat, "%i", &max_dodavanja);
        fgetc(dat);

        char pom[100];
        std::list<int> id_transakcija;
        while (5) {
            fscanf(dat, "%[^\n]s", pom);
            fgetc(dat);
            if (pom == "!") {
                break;
            }
            id_transakcija.push_back(atoi(pom));
        }
        double stanje_na_racunu_EVRO;
        fscanf(dat, "%i", &stanje_na_racunu_EVRO);
        fgetc(dat);
        lista.push_back(DevizniRacun(Datum(d, m, g), prekoracenje, id_transakcija, max_dodavanja, max_prekoracenja, max_dodavanja, stanje_na_racunu_EVRO));
    }
}
void CitajDinRacune(std::list<DinarskiRacun> lista) {
    FILE* dat = fopen("dinarski.txt", "r");
    if (dat == NULL) {
        printf("Greska pri citanju!\n");
        exit;
    }
    int d;
    int m;
    int g;
    int broj_racuna;
    bool prekoracenje;
    double max_skidanja;
    double max_prekoracenja;
    double max_dodavanja;
    while (5) {
        fscanf(dat, "%i", &d);
        fgetc(dat);
        if (feof(dat)) {
            break;
        }
        fscanf(dat, "%i", &m);
        fgetc(dat);
        fscanf(dat, "%i", &g);
        fgetc(dat);
        fscanf(dat, "%i", &broj_racuna);
        fgetc(dat);
        fscanf(dat, "%i", &prekoracenje);
        fgetc(dat);
        fscanf(dat, "%lf", &max_skidanja);
        fgetc(dat);
        fscanf(dat, "%lf", &max_prekoracenja);
        fgetc(dat);
        fscanf(dat, "%lf", &max_dodavanja);
        fgetc(dat);

        char pom[100];
        std::list<int> id_transakcija;
        while (5) {
            fscanf(dat, "%[^\n]s", pom);
            fgetc(dat);
            if (pom == "!") {
                break;
            }
            id_transakcija.push_back(atoi(pom));
        }
        double stanje_na_racunu_EVRO;
        fscanf(dat, "%i", &stanje_na_racunu_EVRO);
        fgetc(dat);
        lista.push_back(DinarskiRacun(Datum(d, m, g), prekoracenje, id_transakcija, max_dodavanja, max_prekoracenja, max_dodavanja, stanje_na_racunu_EVRO));
    }
}
void CitajRac() {
    CitajDevRacune(banka.lista_dev_racuna);
    CitajDinRacune(banka.lista_din_racuna);
}
void IspisiDevRac() {

}