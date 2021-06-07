#pragma once
#include <iostream>
#include <list>
#include "Racun.h"

enum TipKartice { BRONZANA, SREBRNA, ZLATNA, SUPER };

class Kartica {

protected:


    TipKartice tip_kartice;
    int broj_kartice;
    Datum datum_izdavanja;
    Datum datum_isteka;
    int CV; // broj na poledjini kartice

public:

    virtual void KupiNesto() = 0;

};

class DebitnaKartica : public Kartica {

private:

    DinarskiRacun* racun;

public:

    static int id;
    void KupiNesto();
    

};

class KreditnaKartica : public Kartica {

private:

    static int id;
    DevizniRacun* racun;

public:

    void KupiNesto();
};