#include <iostream>
#include <list>
#include "Kartice.h"
#include "Kurs.h"


TipKartice Kartica::getTipKartice()const {
    return tip_kartice;
}

int Kartica::getBrojKartice()const {
    return broj_kartice;
}

Datum Kartica::getDatumIzdavanja()const {
    return datum_izdavanja;
}

Datum Kartica::getDatumIsteka()const {
    return datum_isteka;
}

int Kartica::getCV()const {
    return CV;
}

void Kartica::setTipKartice(TipKartice tip_kartice_) {
    tip_kartice = tip_kartice_;
}

void Kartica::setBrojKartice(int broj_kartice_) {
    broj_kartice = broj_kartice_;
}

void Kartica::setDatumIzdavanja(Datum datum_izdavanja_) {
    datum_izdavanja = datum_izdavanja_;
}

void Kartica::setDatumIsteka(Datum datum_isteka_) {
    datum_isteka = datum_isteka;
}

void Kartica::setCV(int CV_) {
    CV = CV_;
}

DebitnaKartica::DebitnaKartica() {

    tip_kartice = SUPER;
    broj_kartice = 1;
    datum_izdavanja.setDan(1);
    datum_izdavanja.setMesec(1);
    datum_izdavanja.setGodina(2021);
    datum_isteka.setDan(1);
    datum_isteka.setMesec(1);
    datum_isteka.setGodina(2031);
    CV = 1;
    DinarskiRacun(*racun);
}

DebitnaKartica::DebitnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DinarskiRacun* racun_) {

    tip_kartice = tip_kartice_;
    broj_kartice = broj_kartice_;
    datum_izdavanja = datum_izdavanja_;
    datum_isteka = datum_isteka_;
    CV = CV_;
    *racun = *racun_;
}

DebitnaKartica::DebitnaKartica(const DebitnaKartica& debitna_kartica) {

    tip_kartice = debitna_kartica.tip_kartice;
    broj_kartice = debitna_kartica.broj_kartice;
    datum_izdavanja = debitna_kartica.datum_izdavanja;
    datum_isteka = debitna_kartica.datum_isteka;
    CV = debitna_kartica.CV;
    racun = debitna_kartica.racun; // Da li treba zvezdica, zato sto je pokazivac ?
}

void DebitnaKartica::KupiNesto() {

    double pom;
    do
    {
        std::cout << "Unesite cenu proizvoda koji hocete da kupite : " << std::endl;
        std::cin >> pom;
        if (pom <= 0) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }

        if (racun->getPrekoracenje()) {
            if (racun->getMaxPrekoracenje() + racun->getStanjeNaRacunuRSD() < pom) {
                std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                continue;
            }
        }
        else
        {
            if (racun->getStanjeNaRacunuRSD() < pom) {
                std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                continue;
            }
        }

        break;

    } while (5);

    racun->setStanjeNaRacunuRSD(racun->getStanjeNaRacunuRSD() - pom);
}

KreditnaKartica::KreditnaKartica() {

    tip_kartice = ZLATNA;
    broj_kartice = 1;
    datum_izdavanja.setDan(1);
    datum_izdavanja.setMesec(1);
    datum_izdavanja.setGodina(2021);
    datum_isteka.setDan(1);
    datum_isteka.setMesec(1);
    datum_isteka.setGodina(2031);
    CV = 1;
    racun = NULL;
}

KreditnaKartica::KreditnaKartica(TipKartice tip_kartice_, int broj_kartice_, Datum datum_izdavanja_, Datum datum_isteka_, int CV_, DevizniRacun* racun_) {

    tip_kartice = tip_kartice_;
    broj_kartice = broj_kartice_;
    datum_izdavanja = datum_izdavanja_;
    datum_isteka = datum_isteka_;
    CV = CV_;
    racun = racun_;
}

KreditnaKartica::KreditnaKartica(const KreditnaKartica& kreditna_kartica) {

    tip_kartice = kreditna_kartica.tip_kartice;
    broj_kartice = kreditna_kartica.broj_kartice;
    datum_izdavanja = kreditna_kartica.datum_izdavanja;
    datum_isteka = kreditna_kartica.datum_isteka;
    CV = kreditna_kartica.CV;
    racun = kreditna_kartica.racun;
}


void KreditnaKartica::KupiNesto() {

    double pom;
    int valuta;


    do
    {
        do {
            std::cout << "Unesite valutu u kojoj je proizvod : " << std::endl;
            std::cout << "Unesite 0. za EVRO : " << std::endl;
            std::cout << "Unesite 1. za Dolar : " << std::endl;
            std::cout << "Unesite 2. za Franak : " << std::endl;
            std::cout << "Unesite 3. za Marku : " << std::endl;
            std::cout << "Unesite 4. za Kunu : " << std::endl;
            std::cout << "Unesite 5. za Leje : " << std::endl;
            std::cout << "Unesite 6. za RSD : " << std::endl;
            std::cin >> valuta;

            if (valuta < 0 || valuta > 6) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            }

        } while (valuta < 0 || valuta > 6);

        std::cout << "Unesite cenu proizvoda koji hocete da kupite : " << std::endl;
        std::cin >> pom;

        switch (valuta)
        {
        case 0:
            break;
        case 1:
            pom = pom * kurs.getDolar();
            break;
        case 2:
            pom = pom * kurs.getFranak();
            break;
        case 3:
            pom = pom * kurs.getMarka();
            break;
        case 4:
            pom = pom * kurs.getKuna();
            break;
        case 5:
            pom = pom * kurs.getLeji();
            break;
        case 6:
            pom = pom * kurs.getRSD();
            break;
        }

        if (pom <= 0) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            continue;
        }

        if (racun->getPrekoracenje()) {
            if (racun->getStanjeNaRacunuEVRO() + racun->getMaxPrekoracenje() < pom) {
                std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                continue;
            }
        }
        else
        {
            if (racun->getStanjeNaRacunuEVRO() < pom) {
                std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                continue;
            }
        }

        break;

    } while (5);

    
    racun->setStanjeNaRacunuEVRO(racun->getStanjeNaRacunuEVRO() - pom);
}