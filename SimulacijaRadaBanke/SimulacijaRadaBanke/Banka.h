#pragma once

#include <iostream>
#include <list>
#include "Transakcija.h"
#include "Osobe.h"

class Banka{
private:

    std::list<Transakcija> lista_transakcija;
    double kamata_za_transakcije;

public:

    void NapraviTransakciju(DinarskiRacun& racun);

    void NapraviTransakciju(DevizniRacun& racun, Korisnik& korisnik);
};