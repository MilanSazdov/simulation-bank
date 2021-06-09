#pragma once
#include <iostream>
#include <list>
#include "Datum.h"
#include "Racun.h"

enum TipKredita { STAMBENI, ZA_AUTO, ZA_DUG, OSTALO };


class Kredit {

private:

    TipKredita tip_kredita;
    double iznos_kredita;
    Datum rok_isplate;
    double mesecna_rata;
    double kamata;
    bool placena_rata_za_mesec;
    double placeno_do_sada;


public:

    static int id;

    //Geteri 
    TipKredita getTipKredita()const;
    double getIznosKredita()const;
    Datum getRokIsplate()const;
    double getMesecnaRata()const;
    double getKamata()const;
    bool getPlacenaRataZaMesec()const;
    double getPlacenoDoSada()const;

    //Seteri

    void setTipKredita(TipKredita tip_kredita_);
    void setIznosKredita(double iznos_kredita_);
    void setRokIsplate(Datum rok_isplate_);
    void setMesecnaRata(double mesecna_rata_);
    void setKamata(double kamata_);
    void setPlacenaRataZaMesec(bool placena_rata_za_mesec_);
    void setPlacenoDoSada(double placeno_do_sada_);

    void PlatiRatu(DinarskiRacun& racun);
    void IsplatiCeoKredit(DinarskiRacun& racun);

    friend std::ostream& operator<<(std::ostream& os, const Kredit& kredit);

};

class ZahtevZaKredit{


};