#pragma once
#include <iostream>
#include <list>
#include "Datum.h"
#include "Racun.h"

enum TipKredita { STAMBENI, ZA_AUTO, ZA_DUG, OSTALO };


class Kredit {

private:

    // U kredit stavljam id korisnika koji ima kredit, id ziranta;
    int id_ziranta;
    TipKredita tip_kredita;
    double iznos_kredita;
    Datum rok_isplate;
    double mesecna_rata;
    bool kamata;
    double kamata_;
    bool zirant;
    bool placena_rata_za_mesec;
    double placeno_do_sada;


public:

    static int id;
    void PlatiRatu(DinarskiRacun& racun);
    void IsplatiCeoKredit(DinarskiRacun& racun);
    friend std::ostream& operator<<(std::ostream& os, const Kredit& kredit);

};