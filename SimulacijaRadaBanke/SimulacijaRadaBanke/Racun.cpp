#include <iostream>
#include <list>
#include "Racun.h"
#include "Kurs.h"


//RACUN
bool Racun::getPrekoracenje()const {
    return prekoracenje;
}
double Racun::getMaxPrekoracenje()const {
    return max_prekoracenja;
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

    os << "Naknada za mesecno odrzavanje : " << racun.naknada_za_mesecno_odrzavanje_racuna << std::endl;
    os << "MAX Depozit : " << racun.max_skidanja << std::endl;
    os << "Lista transakcija : " << std::endl;
    // os << racun.lista_tranzakcija << std::endl;
    os << "MAX novca za dodavanje : " << racun.max_dodavanja << std::endl;

    return os;
}

//DINARSKI RACUN

DinarskiRacun::DinarskiRacun() {
    
    id++;
    datum_nastanka_racuna = Datum(datum);
    broj_racuna = id;
    prekoracenje = false;
    naknada_za_mesecno_odrzavanje_racuna = 2000;
    max_skidanja = 5000;
    max_prekoracenja = 0;
    max_dodavanja = 5000;
    stanje_na_racunu_RSD = 0;
}

DinarskiRacun::DinarskiRacun(Datum datum_izdavanja_racuna,  bool prekoracenje_, std::list<int> id_transakcija_, double naknada_za_mesecno_odrzavanje_, double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje) {

    id++;
    datum_nastanka_racuna = datum_izdavanja_racuna;
    broj_racuna = id;
    prekoracenje = prekoracenje_;
    id_transakcija = id_transakcija_;
    naknada_za_mesecno_odrzavanje_racuna = naknada_za_mesecno_odrzavanje_;
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
    naknada_za_mesecno_odrzavanje_racuna = racun.naknada_za_mesecno_odrzavanje_racuna;
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
    naknada_za_mesecno_odrzavanje_racuna = 2000;
    max_skidanja = 5000;
    max_prekoracenja = 0;
    max_dodavanja = 5000;
    stanje_na_racunu_EVRO = 0;
}

DevizniRacun::DevizniRacun(Datum datum_izdavanja_racuna, bool prekoracenje_, std::list<int> id_transakcija_, double naknada_za_mesecno_odrzavanje_, double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje) {

    id++;
    datum_nastanka_racuna = datum_izdavanja_racuna;
    broj_racuna = id;
    prekoracenje = prekoracenje_;
    id_transakcija = id_transakcija_;
    naknada_za_mesecno_odrzavanje_racuna = naknada_za_mesecno_odrzavanje_;
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
    naknada_za_mesecno_odrzavanje_racuna = racun.naknada_za_mesecno_odrzavanje_racuna;
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