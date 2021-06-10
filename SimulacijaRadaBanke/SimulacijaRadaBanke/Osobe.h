#pragma once

#include <iostream>
#include <list>
#include "Datum.h"
#include "Adresa.h"

class Osoba {

protected:

    double mesecna_plata;
    Datum datum_rodjenja;
    Adresa adresa_stanovanja;
    std::string ime;
    std::string prezime;
    int broj_godina;

public:

    double getMesecnaPlata()const;
    Datum getDatumRodjenja()const;
    Adresa getAdresaStanovanja()const;
    std::string getIme()const;
    std::string getPrezime()const;
    int getBrojGodina()const;

    void setDatumRodjenja(Datum datumrodjenja);
    void setAdresaStanovanja(Adresa adresastanovanja);
    void setIme(std::string ime);
    void setPrezime(std::string prezime);
    void setBrojGodina(int brojgodina);

    friend std::ostream& operator<<(std::ostream& os, const Osoba& osoba);
};