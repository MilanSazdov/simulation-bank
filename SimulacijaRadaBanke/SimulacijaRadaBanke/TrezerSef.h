#pragma once

#include <iostream>
#include <list>
#include "TrezerSef.h"
#include "Racun.h"


enum TipValute { EVRO, DOLAR, FRANAK, MARKA, KUNA, LEJI, RSD };
class Sef {

private:

    int broj_sefa;
    bool prazan;
    bool slobodan;
    bool otkljucan;
    TipValute valuta;
    double kolicina_novca;
    double mesecno_iznajmljivanje;
    bool placeno_mesecno_iznajmljivanje;

public:

    static int id;

    void UzmiPareIzSefa(double* kes);

    bool PlatiMesecnoIznajmljivanje(DinarskiRacun& racun);

    void PlatiMesecnoIznajmljivanje(DevizniRacun& devracun);

    void PlatiMesecnoIznajmljivanje(double* kes);
};

class Trezor {

private:

    std::list<Sef> lista_sefova;
    int sifra; // sifra za otkljucavanje
    bool otkljucan;

public:

    static double ukupno_novca;

    // Otkljucaj Trezor
    // Zakljucaj Trezor
};