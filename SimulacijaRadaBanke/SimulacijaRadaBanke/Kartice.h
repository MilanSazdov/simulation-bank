#pragma once
#include <iostream>
#include <list>
#include "Racun.h"

enum TipKartice { BRONZANA, SREBRNA, ZLATNA, SUPER };

class Kartica {

protected:


    TipKartice tip_kartice;
    int broj_kartice;
    Datum datum_izdavanja;
    Datum datum_isteka;
    int CV; // broj na poledjini kartice

public:

    virtual void KupiNesto() = 0;

    TipKartice getTipKartice()const;
    int getBrojKartice()const;
    Datum getDatumIzdavanja()const;
    Datum getDatumIsteka()const;
    int getCV()const;

    void setTipKartice(TipKartice tip_kartice_);
    void setBrojKartice(int broj_kartice_);
    void setDatumIzdavanja(Datum datum_izdavanja_);
    void setDatumIsteka(Datum datum_isteka_);
    void setCV(int CV_);
};

class DebitnaKartica : public Kartica {

private:

    DinarskiRacun* racun;

public:

    static int id;
    void KupiNesto();
    DebitnaKartica();
    DebitnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DinarskiRacun* racun_);
    DebitnaKartica(const DebitnaKartica& debitna_kartica);
    
};

class KreditnaKartica : public Kartica {

private:

    DevizniRacun* racun;

public:
    static int id;
    void KupiNesto();
    KreditnaKartica();
    KreditnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DevizniRacun* racun_);
    KreditnaKartica(const KreditnaKartica& kreditna_kartica);
};