#include <iostream>
#include <list>
#include "Transakcija.h"

int Transakcija::ID_transakcije = -1;


Transakcija::Transakcija() {

    tip_valute = RSD;
    kolicina_novca = 0;
    broj_racuna_posiljalac = 1;
    broj_racuna_primalac = 2;
    datum_transakcije = Datum(datum);
    Primalac = "Djura";
    Posiljalac = "Pera";
    provizija = 0.05;
}

Transakcija::Transakcija(TipValute tip_valute_, double kolicina_novca_, int broj_racuna_primalac_, int broj_racuna_posiljalac_, Datum datum_transakcije_, std::string Primalac_, std::string Posiljalac_, double provizija_) {

    tip_valute = tip_valute_;
    kolicina_novca = kolicina_novca_;
    broj_racuna_posiljalac = broj_racuna_posiljalac_;
    broj_racuna_primalac = broj_racuna_primalac_;
    datum_transakcije = datum_transakcije_;
    Primalac = Primalac_;
    Posiljalac = Posiljalac_;
    provizija = provizija_;

}

Transakcija::Transakcija(const Transakcija& transakcija) {

    tip_valute = transakcija.tip_valute;
    kolicina_novca = transakcija.kolicina_novca;
    broj_racuna_posiljalac = transakcija.broj_racuna_posiljalac;
    broj_racuna_primalac = transakcija.broj_racuna_primalac;
    datum_transakcije = transakcija.datum_transakcije;
    Primalac = transakcija.Primalac;
    Posiljalac = transakcija.Posiljalac;
    provizija = transakcija.provizija;
}