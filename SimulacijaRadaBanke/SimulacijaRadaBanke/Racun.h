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
    double max_skidanja;
    double max_prekoracenja;
    double max_dodavanja;

public:
    virtual void Deposit(double* kes) = 0; // Dodaj na racun
    virtual void Withdraw(double* kes) = 0; // Skini sa racuna

    Datum getDatumNastankaRacuna()const;

    int getBrojRacuna()const;

    bool getPrekoracenje()const;

    double getMaxPrekoracenje()const;

    std::list<int> getIdTransakcija()const;

    double getNaknadaZaMesecnoOdrzavanjeRacuna() const;

    double getMaxDodavanja()const;

    double getMaxSkidanja()const;

    void setDatumNastankaRacuna(Datum datum);

    void setBrojRacuna(int broj_racuna_);

    void setPrekoracenje(bool prekoracenje_);

    void setMaxPrekoracenje(double max_prekoracenja_);

    void setIdTransakcija(std::list<int> id_transakcija_);

    void setNaknadaZaMesecnoOdrzavanjeRacuna(double naknada_za_mesecno_odrzavanje_racuna_);

    void setMaxDodavanja(double max_dodavanja_);

    void setMaxSkidanja(double max_skidanja_);


    friend std::ostream& operator<<(std::ostream& os, const Racun& racun);
};

class DinarskiRacun : public Racun {

private:
    double stanje_na_racunu_RSD;

public:
    static int id;

    DinarskiRacun();
    DinarskiRacun(Datum datum_izdavanja_racuna,bool prekoracenje_, std::list<int> id_transakcija_, double naknada_za_mesecno_odrzavanje_, double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje);
    DinarskiRacun(const DinarskiRacun& racun);

    double getStanjeNaRacunuRSD()const;
    void setStanjeNaRacunuRSD(double stanje_na_racunu_RSDD);
    void Deposit(double* kes);
    void Withdraw(double* kes);
    friend std::ostream& operator<<(std::ostream& os, const DinarskiRacun& racun);
};

class DevizniRacun : public Racun {

    double stanje_na_racunu_EVRO;

public:
    static int id;

    DevizniRacun();
    DevizniRacun(Datum datum_izdavanja_racuna, bool prekoracenje_, std::list<int> id_transakcija_, double naknada_za_mesecno_odrzavanje_, double max_depozit_, double max_prekoracenje_, double max_dodavanja_, double stanje);
    DevizniRacun(const DevizniRacun& racun);

    double getStanjeNaRacunuEVRO()const;
    void setStanjeNaRacunuEVRO(double stanje_na_racunu_EVRO_);
    void Deposit(double* kes);
    void Withdraw(double* kes);
    friend std::ostream& operator<<(std::ostream& os, const DevizniRacun& racun);
};