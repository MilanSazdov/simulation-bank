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

    friend std::ostream& operator<<(std::ostream& os, const Kartica& kartica) {

        os << "Tip kartice je : " << kartica.tip_kartice << std::endl;
        os << "Broj kartice je : " << kartica.broj_kartice << std::endl;
        os << "Datum izdavanja kartice je : " << kartica.datum_izdavanja << std::endl;
        os << "Datum isteka kartice je : " << kartica.datum_isteka << std::endl;
        os << "CV kartice je : " << kartica.CV << std::endl;
        return os;
    }
};

class DebitnaKartica : public Kartica {

private:

    DinarskiRacun* racun;

public:

    static int id;

    DinarskiRacun* getRacun()const;
    void setRacun(DinarskiRacun* racun);
    void KupiNesto();
    DebitnaKartica();
    DebitnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DinarskiRacun* racun_);
    DebitnaKartica(const DebitnaKartica& debitna_kartica);
    
    friend std::ostream& operator<<(std::ostream& os, const DebitnaKartica& debitna_kartica) {
        os << "*** Debitna kartica : ***" << std::endl;
        os << (const Kartica&)debitna_kartica;
        os << "Dinarski racun koji je povezan sa karticom : " << std::endl;
        os << *(debitna_kartica.racun) << std::endl;

        return os;
    }
};

class KreditnaKartica : public Kartica {

private:

    DevizniRacun* racun;

public:
    static int id;

    DevizniRacun* getRacunDevizni()const;
    void setRacun(DevizniRacun* racun);
    void KupiNesto();
    KreditnaKartica();
    KreditnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DevizniRacun* racun_);
    KreditnaKartica(const KreditnaKartica& kreditna_kartica);

    friend std::ostream& operator<<(std::ostream& os, const KreditnaKartica& kreditna_kartica) {

        os << "*** KREDITNA KARTICA ***" << std::endl;
        os << (const Kartica&)kreditna_kartica << std::endl;
        os << "Devizni racun koji je povezan sa kreditnom karticom : " << std::endl;
        os << *(kreditna_kartica.racun) << std::endl;
        return os;
    }
};