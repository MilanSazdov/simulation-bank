#pragma once

#include <iostream>
#include <list>
#include "Datum.h"

enum TipValute { EVRO, DOLAR, FRANAK, MARKA, KUNA, LEJI, RSD };

class Transakcija {

private:

    TipValute tip_valute; // tip_valute = valuta_original
    double kolicina_novca;
    int broj_racuna_posiljalac;
    int broj_racuna_primalac;
    Datum datum_transakcije;
    std::string Primalac;
    std::string Posiljalac;
    double provizija; // provizija koju banka uzima

public:
    static int ID_transakcije;

    //GETERI
    TipValute getTipValute()const;
    double getKolicinaNovca()const;
    int getBrojRacunaPosiljalac()const;
    int getBrojRacunaPrimalac()const;
    Datum getDatumTransakcija()const;
    std::string getPrimalac()const;
    std::string getPosiljalac()const;
    double getProvizija()const;

    //SETERI

    void setTipValute(TipValute tip_valute_);
    void setKolicinaNovca(double kolicina_novca_);
    void setBrojRacunaPosiljalac(int broj);
    void setBrojRacunaPrimalac(int broj);
    void setDatumTransakcije(Datum datum_);
    void setPrimalac(std::string primalac);
    void setPosiljalac(std::string posiljalac);
    void setProvizija(double provizija_);
    
    Transakcija();
    Transakcija(TipValute tip_valute_, double kolicina_novca_, int broj_racuna_primalac_, int broj_racuna_posiljalac, Datum datum_transakcije_, std::string Primalac_, std::string Posiljalac_, double provizija_);
    Transakcija(const Transakcija& transakcija);
};
