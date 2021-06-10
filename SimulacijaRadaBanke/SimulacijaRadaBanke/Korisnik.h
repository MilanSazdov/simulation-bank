#pragma once
#include "Osobe.h"
#include "Racun.h"
#include "Krediti.h"
#include "Kartice.h"
#include "TrezerSef.h"
#include "Banka.h"
#include "Transakcija.h"
#include "Kurs.h"


class Korisnik : public Osoba {

private:

    int id_korisnika;
    double kes; // u RSD
    bool u_filijali;
    bool na_salteru;
    DevizniRacun* devizni_racun;
    DinarskiRacun* dinarski_racun;
    DebitnaKartica* debitna_kartica;
    KreditnaKartica* kreditna_kartica;
    Filijala* filijala;
    Banka* banka;
    Salter* salter;
    Sef* sef;
    ZahtevZaKredit* zahtev_za_kredit;

public:
    static int ID;

    Korisnik();
    Korisnik(double mesecna_plata_, Datum datum_rodjenja_, Adresa adresa_stanovanja_, std::string ime_, std::string prezime_, int broj_godina_, double kes_, bool u_filijali_, bool na_salteru_, DevizniRacun* devizni_racun_, DinarskiRacun* dinarski_racun_, DebitnaKartica* debitna_kartica_, KreditnaKartica* kreditna_kartica_,Filijala* filijala_, Banka* banka_, Sef* sef_, ZahtevZaKredit* zahtev_za_kredit_);
    Korisnik(const Korisnik& korisnik);

    int getId()const;
    double getKes()const;
    bool getUFilijali()const;
    bool getNaSalteru()const;
    DevizniRacun* getDevizniRacun();
    DinarskiRacun* getDinarskiRacun();
    DebitnaKartica* getDebitnaKartica();
    KreditnaKartica* getKreditnaKartica();
    Filijala* getFilijala();
    Banka* getBanka();
    Salter* getSalter();
    Sef* getSef();

    void setId(int id_);
    void setKes(double kes_);
    void setUFilijali(bool u_filijali_);
    void setNaSalteru(bool na_salteru_);
    void setDevizniRacun(DevizniRacun* racun);
    void setDinarskiRacun(DinarskiRacun* racun);
    void setDebitnaKartica(DebitnaKartica* kartica);
    void setKreditnaKartica(KreditnaKartica* kartica);
    void setFilijala(Filijala* filijala_);
    void setBanka(Banka* banka_);
    void setSef(Sef* sef_);

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



class VlasnikBanke :public Osoba {
private:
    double budzet;
    
public:

    Banka* banka;

    void IzgradiFilijalu();
    void MenjajMesec();
    void OtkljucajTrezor();
    void ZakljucajTrezor();
    void DodajPareUBankomat();
    void KupiVozilo();
    void KupiTehniku();
};
extern std::list<Korisnik> lista_korisnika;