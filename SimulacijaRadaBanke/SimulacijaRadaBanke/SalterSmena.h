#pragma once
#include <iostream>
#include <list>
#include "Osobe.h"

class Salter {

    int broj_saltera;
    bool zauzet;
    bool pauza;
};

class Smena {

    std::list<RadnikZaSalterom> lista_radnika;
    char vreme_pocetka[20];
    char vreme_pocetka_vikendom[20];
    char vreme_kraja[20];
    char vreme_kraja_vikendom[20];
};