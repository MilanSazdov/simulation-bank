#pragma once

#include <iostream>
#include <list>
#include "Datum.h"
#include "Adresa.h"
#include "Racun.h"
#include "Krediti.h"
#include "Kartice.h"
#include "TrezerSef.h"

class Osoba {
protected:
    Datum datum_rodjenja;
    Adresa adresa_stanovanja;
    char ime[40];
    char prezime[40];
    int broj_godina;
};

class Korisnik : public Osoba {
private:
    int id_korisnika;
    double kes; // u RSD
    bool u_filijali;
    bool na_salteru;
    bool u_cekaonici;
    bool za_salterom;
    int broj_u_redu;
    DevizniRacun* devizni_racun;
    DinarskiRacun* dinarski_racun;
    DebitnaKartica* debitna_kartica;
    KreditnaKartica* kreditna_kartica;
    std::list<Kredit>::iterator lista_kredita;
    std::list<Sef>::iterator lista_sefova;
    //Nalog
    //OrocenaStednja
    //NeOrocenaStednja
    //ZahtevZaKredit
public:
    void OtvoriRacun();
    void Deposit();
    void Withdraw();
    void KupiNesto();
    void IzradiKarticu();
};

class RadnikZaSalterom : public Osoba {

    bool na_pauzi;
    float plata;//u dinarima
    int broj_saltera_za_kojim_radi;
};