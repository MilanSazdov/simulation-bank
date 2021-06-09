#pragma once

#include <iostream>
#include <list>
#include "TrezerSef.h"
#include "Racun.h"
#include "Transakcija.h"




class Sef {

private:

    int broj_sefa;
    TipValute valuta;
    double kolicina_novca;
    double mesecno_iznajmljivanje;
    bool placeno_mesecno_iznajmljivanje;

public:

    static int id;

    void UzmiPareIzSefa(double* kes);

    bool PlatiMesecnoIznajmljivanje(DinarskiRacun& racun);

    bool PlatiMesecnoIznajmljivanje(DevizniRacun& devracun);

    bool PlatiMesecnoIznajmljivanje(double* kes);

    Sef();
    Sef(int broj_sefa_, TipValute valuta_, double kolicina_novca_, double mesecno_iznajmljivanje_, bool placeno_mesecno_iznajmljivanje_);
    Sef(Sef& sef);

    int getBrojSefa()const;
    TipValute getValuta()const;
    double getKolicinaNovca()const;
    double getMesecnoIznajmljivanje()const;
    bool getPlacenoMesecnoIznajmljivanje()const;
    void setBrojSefa(int broj_sefa_);
    void setValuta(TipValute valuta_);
    void setKolicinaNovca(double kolicina_novca_);
    void setMesecnoIznajmljivanje(double mesecno_iznajmljivanje_);
    void setPlacenoMesecnoIznajmljivanje(bool placeno_mesecno_iznajmljivanje_);

    friend std::ostream& operator<<(std::ostream& os, const Sef& sef) {

        os << "*** SEF ***" << std::endl;
        os << "Broj sefa je : " << sef.broj_sefa << std::endl;
        os << "Tip valute u sefu je : " << sef.valuta << std::endl;
        os << "Kolicina novca u sefu je : " << sef.kolicina_novca << std::endl;
        os << "Mesecno iznajmljivanje je : " << sef.mesecno_iznajmljivanje << std::endl;
        os << "Da li je placeno mesecno iznajmljivanje ? : ";
        if (sef.placeno_mesecno_iznajmljivanje == true) {
            os << "DA" << std::endl;
        }
        else
        {
            os << "NE" << std::endl;
        }

        return os;
    }
};

class Trezor {

private:

    std::list<Sef> lista_sefova;
    int sifra; // sifra za otkljucavanje
    bool otkljucan;

public:
    
    Trezor();
    Trezor(std::list<Sef> lista_sefova_, int sifra_, bool otkljucan_);
    Trezor(const Trezor& trezor);

    std::list<Sef> getListaSefova()const;
    int getSifra()const;
    bool getOtkljucan()const;

    void setListaSefova(std::list<Sef> lista_sefova_);
    void setSifra(int sifra_);
    void setOtkljucan(bool otkljucan_);

    friend std::ostream& operator<<(std::ostream& os, const Trezor& trezor);
    
};