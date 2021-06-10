#include <iostream>
#include <list>
#include "Osobe.h"
#include "Transakcija.h"
#include "Kurs.h"

double Osoba::getMesecnaPlata()const {
    return mesecna_plata;
}

Datum Osoba::getDatumRodjenja() const {

    return datum_rodjenja;
}
Adresa Osoba::getAdresaStanovanja()const {
    return adresa_stanovanja;
}
std::string Osoba::getIme()const {
    return ime;
}
std::string Osoba::getPrezime()const {
    return prezime;
}
int Osoba::getBrojGodina()const {
    return broj_godina;
}

void Osoba::setDatumRodjenja(Datum datumrodjenja) {
    datum_rodjenja = Datum(datumrodjenja);
}
void Osoba::setAdresaStanovanja(Adresa adresastanovanja) {
    adresa_stanovanja = Adresa(adresastanovanja);
}
void Osoba::setIme(std::string ime) {
    ime = ime;
}
void Osoba::setPrezime(std::string prezime) {
    prezime = prezime;
}
void Osoba::setBrojGodina(int brojgodina) {
    broj_godina = brojgodina;
}

std::ostream& operator<<(std::ostream& os, const Osoba& osoba) {

    os << "Datum rodjenja je : " << std::endl;
    os << osoba.datum_rodjenja << std::endl;
    os << "Adresa je : " << std::endl;
    os << osoba.adresa_stanovanja << std::endl;
    os << "Ime je : " << osoba.ime << std::endl;
    os << "Prezime je : " << osoba.prezime << std::endl;
    os << "Broj godina : " << osoba.broj_godina << std::endl;

    return os;
}
