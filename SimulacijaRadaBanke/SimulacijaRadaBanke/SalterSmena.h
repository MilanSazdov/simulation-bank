#pragma once
#include <iostream>
#include <list>
#include "Osobe.h"

class Salter {

private:

    RadnikZaSalterom radnik_za_salterom;
    int broj_saltera;
    bool zauzet;

public:

    Salter();
    Salter(RadnikZaSalterom radnik_za_salterom, int broj_saltera_, bool zauzet_);
    Salter(const Salter& salter);

    RadnikZaSalterom getRadnikZaSalterom()const;
    int getBrojSaltera()const;
    bool getZauzet()const;

    void setRadnikZaSalterom(RadnikZaSalterom radnik_za_salterom_);
    void setBrojSaltera(int broj_saltera_);
    void setZauzet(bool zauzet_);

    friend std::ostream& operator<<(std::ostream& os, const Salter& salter) {

        os << "Radnik za salterom : " << std::endl;
       // os << salter.radnik_za_salterom << std::endl;
        os << "Broj saltera je : " << salter.broj_saltera << std::endl;
        os << "Zauzet : ";
        if (salter.zauzet) {
            os << "DA" << std::endl;
        }
        else
        {
            os << "NE" << std::endl;
        }

        return os;
    }

};

class Smena{

private:

    std::list<RadnikZaSalterom> lista_radnika;
    std::string vreme_pocetka;
    std::string vreme_pocetka_vikendom;
    std::string vreme_kraja;
    std::string vreme_kraja_vikendom;

public:

    Smena();
    Smena(std::list<RadnikZaSalterom> lista_radnika_, std::string vreme_pocetka_, std::string vreme_pocetka_vikendom_, std::string vreme_kraja_, std::string vreme_kraja_vikendom_);
    Smena(const Smena& smena);

    std::list<RadnikZaSalterom> getListaRadnika()const;
    std::string getVremePocetka()const;
    std::string getVremePocetkaVikendom()const;
    std::string getVremeKraja()const;
    std::string getVremeKrajaVikendom()const;

    void setListaRadnika(std::list<RadnikZaSalterom> lista_radnika_);
    void setVremePocetka(std::string vreme_pocetka_);
    void setVremePocetkaVikendom(std::string vreme_pocetka_vikendom_);
    void setVremeKraja(std::string vreme_kraja_);
    void setVremeKrajaVikendom(std::string vreme_kraja_vikendom_);

    friend std::ostream& operator<<(std::ostream& os, const Smena& smena) {
        os << "Lista radnika : " << std::endl;
        //os << smena.lista_radnika << std::endl;
        os << "Vreme pocetka : " << smena.vreme_pocetka << std::endl;
        os << "Vreme pocetka vikendom : " << smena.vreme_pocetka_vikendom << std::endl;
        os << "Vreme kraja : " << smena.vreme_kraja << std::endl;
        os << "Vreme kraja vikendom : " << smena.vreme_kraja_vikendom << std::endl;

        return os;
    }
};