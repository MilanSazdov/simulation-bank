#pragma once

#include <iostream>
#include <list>
#include "TrezerSef.h"
#include "SalterSmena.h"
#include "Bankomat.h"

class Filijala {

private:

    Adresa adresa;
    Salter salter;
    Bankomat bankomat;
    Trezor trezor;

public:

    Filijala();
    Filijala(Adresa adresa_, Salter salter_,Bankomat bankomat_, Trezor trezor_);
    Filijala(const Filijala& filijala);

    Adresa* getAdresa();
    Salter* getSalter();
    Bankomat* getBankomat();
    Trezor* getTrezor();

    void setAdresa(Adresa adresa);
    void setSalter(Salter salter);
    void setBankomat(Bankomat bankomat);
    void setTrezor(Trezor trezor);

    friend std::ostream& operator<<(std::ostream& os, const Filijala& filijala);

};


class Banka {


public:

    std::list<DevizniRacun> lista_dev_racuna;
    std::list<DinarskiRacun> lista_din_racuna;
    std::list<Transakcija> lista_transakcija;
    std::list<Filijala> lista_filijala;
    DevizniRacun* NadjiPoBrojuDev(int brojracuna);
    DinarskiRacun* NadjiPoBrojuDin(int brojracuna);
    void NapraviTransakciju(DevizniRacun* racun1, DevizniRacun* racun2, std::string Primalac, std::string Posiljalac);
    void NapraviTransakciju(DinarskiRacun* racun1, DinarskiRacun* racun2, std::string Primalac, std::string Posiljalac);
};

extern Banka banka;