#include <iostream>
#include <list>
#include "Transakcija.h"

int Transakcija::ID_transakcije = -1;


Transakcija::Transakcija() {

    ID_transakcije++;
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

    ID_transakcije++;
    tip_valute = tip_valute_;
    kolicina_novca = kolicina_novca_;
    broj_racuna_posiljalac = broj_racuna_posiljalac_;
    broj_racuna_primalac = broj_racuna_primalac_;
    datum_transakcije = Datum(datum_transakcije_);
    Primalac = Primalac_;
    Posiljalac = Posiljalac_;
    provizija = provizija_;

}

Transakcija::Transakcija(const Transakcija& transakcija) {

    ID_transakcije++;
    tip_valute = transakcija.tip_valute;
    kolicina_novca = transakcija.kolicina_novca;
    broj_racuna_posiljalac = transakcija.broj_racuna_posiljalac;
    broj_racuna_primalac = transakcija.broj_racuna_primalac;
    datum_transakcije = Datum(transakcija.datum_transakcije);
    Primalac = transakcija.Primalac;
    Posiljalac = transakcija.Posiljalac;
    provizija = transakcija.provizija;
}


TipValute Transakcija::getTipValute()const {
    return tip_valute;
}
double Transakcija::getKolicinaNovca()const {
    return kolicina_novca;
}
int Transakcija::getBrojRacunaPosiljalac()const {
    return broj_racuna_posiljalac;
}
int Transakcija::getBrojRacunaPrimalac()const {
    return broj_racuna_primalac;
}
Datum Transakcija::getDatumTransakcija()const {
    return datum_transakcije;
}
std::string Transakcija::getPrimalac()const {
    return Primalac;
}
std::string Transakcija::getPosiljalac()const {
    return Posiljalac;
}
double Transakcija::getProvizija()const {
    return provizija;
}

void Transakcija::setTipValute(TipValute tip_valute_) {
    tip_valute = tip_valute_;
}
void Transakcija::setKolicinaNovca(double kolicina_novca_) {
    kolicina_novca = kolicina_novca_;
}
void Transakcija::setBrojRacunaPosiljalac(int broj) {
    broj_racuna_posiljalac = broj;
}
void Transakcija::setBrojRacunaPrimalac(int broj) {
    broj_racuna_primalac = broj;
}
void Transakcija::setDatumTransakcije(Datum datum_) {
    datum_transakcije = Datum(datum_);
}
void Transakcija::setPrimalac(std::string primalac) {
    Primalac = primalac;
}
void Transakcija::setPosiljalac(std::string posiljalac) {
    Posiljalac = posiljalac;
}
void Transakcija::setProvizija(double provizija_) {
    provizija = provizija_;
}