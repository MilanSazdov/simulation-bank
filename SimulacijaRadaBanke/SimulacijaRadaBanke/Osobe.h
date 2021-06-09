#pragma once

#include <iostream>
#include <list>
#include "Datum.h"
#include "Adresa.h"
#include "Racun.h"
#include "Krediti.h"
#include "Kartice.h"
#include "TrezerSef.h"
#include "Banka.h"
#include "SalterSmena.h"

class Osoba {

protected:
    double mesecna_plata;
    Datum datum_rodjenja;
    Adresa adresa_stanovanja;
    std::string ime;
    std::string prezime;
    int broj_godina;

public:

    Datum getDatumRodjenja()const;
    Adresa getAdresaStanovanja()const;
    std::string getIme()const;
    std::string getPrezime()const;
    int getBrojGodina()const;

    void setDatumRodjenja(Datum datumrodjenja);
    void setAdresaStanovanja(Adresa adresastanovanja);
    void setIme(std::string ime);
    void setPrezime(std::string prezime);
    void setBrojGodina(int brojgodina);

    friend std::ostream& operator<<(std::ostream& os, const Osoba& osoba);
};

class Korisnik : public Osoba {
private:
    int id_korisnika;
    double kes; // u RSD
    bool u_filijali;
    bool na_salteru;
    bool u_cekaonici;
    int broj_u_redu;
    Banka* banka;
    DevizniRacun* devizni_racun;
    DinarskiRacun* dinarski_racun;
    DebitnaKartica* debitna_kartica;
    KreditnaKartica* kreditna_kartica;
    Filijala* filijala;
    Salter* salter;
    Sef* sef;
    //Nalog
    //OrocenaStednja
    //NeOrocenaStednja
    //ZahtevZaKredit
public:
    static int ID;
    void OtvoriRacun();
    void Deposit();
    void Withdraw();
    void KupiNesto();
    void IzradiKarticu();
    void ZatvoriRacun();
    void ZatvoriKarticu();
    void NapraviTransakciju();
    void NapraviTransakciju(DinarskiRacun* racun);
    void NapraviTransakciju(DevizniRacun* racun);
    void UzmiNovacIzSefa();
    void PlatiRatuSefa();
    void IznajmiSef();
    void NapustiSef();
    void IdiUFilijalu();
    void IdiNaSalter();
    void IzadjiIzFilijale();
    void IzadjiSaSaltera();
    void IsplatiPlatu();
};

class RadnikZaSalterom : public Osoba {

    bool na_pauzi;
    int broj_saltera_za_kojim_radi;
};

class VlasnikBanke :public Osoba {
private:
    double budzet;
    Banka* banka;
public:
    void IzgradiFilijalu();
    void MenjajMesec();
    void OtkljucajTrezor();
    void ZakljucajTrezor();
    void DodajPareUBankomat();
    void KupiVozilo();
    void KupiTehniku();
};
extern std::list<Korisnik> lista_korisnika;