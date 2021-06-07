#pragma once

#include <iostream>
#include <list>
#include "Datum.h"


class Racun {

protected:

    Datum datum_nastanka_racuna;
    int broj_racuna;
    bool prekoracenje;
    std::list<int> id_transakcija;
    double naknada_za_mesecno_odrzavanje_racuna;
    double naknada_za_podizanje_gotovine_na_bankomatima;
    double max_depozit;
    double max_prekoracenja;
    double max_dodavanja;

public:
    virtual void Deposit(double* kes) = 0; // Dodaj na racun
    virtual void Withdraw(double* kes) = 0; // Skini sa racuna
    virtual void NapraviTransakciju() = 0;

    bool getPrekoracenje()const;
    double getMaxPrekoracenje()const;
    friend std::ostream& operator<<(std::ostream& os, const Racun& racun);
};

class DinarskiRacun : public Racun {

private:
    double stanje_na_racunu_RSD;
    std::list<int> id_transakcija;

public:
    static int id;

    double getStanjeNaRacunuRSD()const;
    void setStanjeNaRacunuRSD(double stanje_na_racunu_RSDD);
    void Deposit(double* kes);
    void Withdraw(double* kes);
    friend std::ostream& operator<<(std::ostream& os, const DinarskiRacun& racun);
};

class DevizniRacun : public Racun {

    double stanje_na_racunu_EVRO;
    std::list<int> lista_transakcija;


public:
    static int id;

    double getStanjeNaRacunuEVRO()const;
    void setStanjeNaRacunuEVRO(double stanje_na_racunu_EVRO_);
    void Deposit(double* kes);
    void Withdraw(double* kes);
    friend std::ostream& operator<<(std::ostream& os, const DevizniRacun& racun);
};
