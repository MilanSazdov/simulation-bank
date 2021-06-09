#pragma once

#include <iostream>
#include <list>
#include "Datum.h"

enum TipValute { EVRO, DOLAR, FRANAK, MARKA, KUNA, LEJI, RSD };

class Transakcija {

private:

    TipValute tip_valute; // tip_valute = valuta_original
    double kolicina_novca;
    int broj_kartice;
    Datum datum_transakcije;
    bool uspeh_transakcije;
    std::string Primalac;
    std::string Posiljalac;
    double provizija; // provizija koju banka uzima

public:
    static int ID_transakcije; // Na nivou banke
    // Odbij tansakciju i odobri transakciju
};
