#pragma once

#include <iostream>
#include <list>
#include "Transakcija.h"
#include "Osobe.h"
#include "TrezerSef.h"
#include "SalterSmena.h"
#include "Bankomat.h"

class Filijala {

private:

    Adresa adresa;
    Salter salter;
    Smena smena;
    Bankomat bankomat;
    Trezor trezor;

public:

    Filijala();
    Filijala(Adresa adresa_, Salter salter_, Smena smena_, Bankomat bankomat_, Trezor trezor_);
    Filijala(const Filijala& filijala);

    Adresa getAdresa();
    Salter* getSalter();
    Smena* getSmena();
    Bankomat* getBankomat();
    Trezor* getTrezor();

    void setAdresa(Adresa adresa_);
    void setSalter(Salter salter_);
    void setSmena(Smena smena_);
    void setBankomat(Bankomat bankomat_);
    void setTrezor(Trezor trezor_);

    friend std::ostream& operator<<(std::ostream& os, const Filijala& filijala);

};


class Banka {


public:
    std::list<DevizniRacun> lista_dev_racuna;
    std::list<DinarskiRacun> lista_din_racuna;
    std::list<Transakcija> lista_transakcija;
    std::list<Filijala> lista_filijala;
    DevizniRacun* NadjiPoBrojuDev(int broj_racuna);
    DinarskiRacun* NadjiPoBrojuDin(int brojracuna);
    void NapraviTransakciju(DevizniRacun* racun1, DevizniRacun* racun2, std::string Primalac, std::string Posiljalac);
    void NapraviTransakciju(DinarskiRacun* racun1, DinarskiRacun* racun2, std::string Primalac, std::string Posiljalac_);
};