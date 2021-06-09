#include <iostream>
#include <list>
#include "Banka.h"
#include "Kurs.h"
#include "Datum.h"

Filijala::Filijala() {

    adresa = Adresa();
    salter = Salter();
    smena = Smena();
    bankomat = Bankomat();
    trezor = Trezor();
}

Filijala::Filijala(Adresa adresa_, Salter salter_, Smena smena_, Bankomat bankomat_, Trezor trezor_) {

    adresa = Adresa(adresa_);
    salter = Salter(salter_);
    smena = Smena(smena_);
    bankomat = Bankomat(bankomat_);
    trezor = Trezor(trezor_);
}

Filijala::Filijala(const Filijala& filijala) {

    adresa = Adresa(filijala.adresa);
    salter = Salter(filijala.salter);
    smena = Smena(filijala.smena);
    bankomat = Bankomat(filijala.bankomat);
    trezor = Trezor(filijala.trezor);
}

Adresa* Filijala::getAdresa() {
    return &adresa;
}
Salter* Filijala::getSalter() {
    return &salter;
}
Bankomat* Filijala::getBankomat() {
    return &bankomat;
}

Smena* Filijala::getSmena() {
    return &smena;
}

Trezor* Filijala::getTrezor() {
    return &trezor;
}

void Filijala::setAdresa(Adresa adresa_) {
    adresa = Adresa(adresa_);
}

void Filijala::setSalter(Salter salter_) {
    salter = Salter(salter_);
}

void Filijala::setSmena(Smena smena_) {
    smena = Smena(smena_);
}

void Filijala::setBankomat(Bankomat bankomat_) {
    bankomat = Bankomat(bankomat_);
}

void Filijala::setTrezor(Trezor trezor_) {
    trezor = Trezor(trezor_);
}

std::ostream& operator<<(std::ostream& os, const Filijala& filijala) {

    os << "Adresa : " << std::endl;
    os << filijala.adresa << std::endl;
    os << "Smena : " << std::endl;
    os << filijala.smena << std::endl;
    os << "Salter : " << std::endl;
    os << filijala.salter << std::endl;
    os << "Bankomat : " << std::endl;
    os << filijala.bankomat << std::endl;
    os << "Trezor : " << std::endl;
    os << filijala.trezor << std::endl;

    return os;
}


DevizniRacun* Banka::NadjiPoBrojuDev(int broj_racuna) {
    std::list<DevizniRacun>::iterator it = lista_dev_racuna.begin();
    for (; it != lista_dev_racuna.end(); it++) {
        if (it->getBrojRacuna() == broj_racuna) {
            return &(*it);
        }
    }
    return NULL;
}
DinarskiRacun* Banka::NadjiPoBrojuDin(int broj_racuna) {
    std::list<DinarskiRacun>::iterator it = lista_din_racuna.begin();
    for (; it != lista_din_racuna.end(); it++) {
        if (it->getBrojRacuna() == broj_racuna) {
            return &(*it);
        }

    }
}
void Banka::NapraviTransakciju(DevizniRacun* racun1, DevizniRacun* racun2, std::string Primalac_, std::string Posiljalac_) {
    int valuta_; // Da moze da unese broj za valutu
    TipValute valuta_original;
    double kolicina_novca_;
    int broj_kartice_;
    Datum datum_transakcije_ = Datum(datum);
    double provizija_; // provizija koju banka uzima


    do {
        std::cout << "Unesite valutu u kojoj hocete da izvrsite transakciju: " << std::endl;
        std::cout << "Unesite 0. za EVRO : " << std::endl;
        std::cout << "Unesite 1. za Dolar : " << std::endl;
        std::cout << "Unesite 2. za Franak : " << std::endl;
        std::cout << "Unesite 3. za Marku : " << std::endl;
        std::cout << "Unesite 4. za Kunu : " << std::endl;
        std::cout << "Unesite 5. za Leje : " << std::endl;
        std::cout << "Unesite 6. za RSD : " << std::endl;
        std::cin >> valuta_;

        if (valuta_ < 0 || valuta_ > 6) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
        }


    } while (valuta_ < 0 || valuta_ > 6);

    switch (valuta_) {
    case 0:
        valuta_original = EVRO;
        break;
    case 1:
        valuta_original = DOLAR;
        break;
    case 2:
        valuta_original = FRANAK;
        break;
    case 3:
        valuta_original = MARKA;
        break;
    case 4:
        valuta_original = KUNA;
        break;
    case 5:
        valuta_original = LEJI;
        break;
    case 6:
        valuta_original = RSD;
        break;
    default:
        std::cout << "Doslo je do greske !!!" << std::endl;
        return;
        break;
    }
    do {
        std::cout << "Unesite kolicinu novca koji hocete da posaljete : " << std::endl;

        std::cin >> kolicina_novca_;

        switch (valuta_original)
        {
        case EVRO:
            break;
        case DOLAR:
            kolicina_novca_ = kolicina_novca_ * kurs.getDolar();
            break;
        case FRANAK:
            kolicina_novca_ = kolicina_novca_ * kurs.getFranak();
            break;
        case MARKA:
            kolicina_novca_ = kolicina_novca_ * kurs.getMarka();
            break;
        case KUNA:
            kolicina_novca_ = kolicina_novca_ * kurs.getKuna();
            break;
        case LEJI:
            kolicina_novca_ = kolicina_novca_ * kurs.getLeji();
            break;
        case RSD:
            kolicina_novca_ = kolicina_novca_ * kurs.getRSD();
            break;
        }
        provizija_ = 0.05 * kolicina_novca_;
        kolicina_novca_ -= provizija_;

        if (racun1->getPrekoracenje()) {
            if (kolicina_novca_ <= 0 || kolicina_novca_ > racun1->getStanjeNaRacunuEVRO() + racun1->getMaxPrekoracenje()) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            }
        }
        else
        {
            if (kolicina_novca_ <= 0 || kolicina_novca_ > racun1->getStanjeNaRacunuEVRO()) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            }
        }
    } while (kolicina_novca_ <= 0);
    racun1->setStanjeNaRacunuEVRO(racun1->getStanjeNaRacunuEVRO() - (kolicina_novca_ + provizija_));
    racun2->setStanjeNaRacunuEVRO(racun2->getStanjeNaRacunuEVRO() + kolicina_novca_);

    lista_transakcija.push_back(Transakcija((TipValute)valuta_, kolicina_novca_ + provizija_, racun1->getBrojRacuna(), racun2->getBrojRacuna(), datum, Primalac_, Posiljalac_, provizija_));
}
void Banka::NapraviTransakciju(DinarskiRacun* racun1, DinarskiRacun* racun2, std::string Primalac_, std::string Posiljalac_) {
    TipValute valuta_original;
    double kolicina_novca_;
    int broj_kartice_;
    Datum datum_transakcije_ = Datum(datum);
    double provizija_; // provizija koju banka uzima
    while (5) {
        std::cout << "Unesite kolicinu novca koji hocete da posaljete : " << std::endl;
        std::cin >> kolicina_novca_;
        if (racun1->getPrekoracenje()) {
            if (kolicina_novca_ <= 0 || kolicina_novca_ - racun1->getMaxPrekoracenje() > racun1->getStanjeNaRacunuRSD()) {
                printf("Uneli ste pogresnu vrednost!\n");
                continue;
            }
            else
            {
                provizija_ = 0.05 * kolicina_novca_;
                racun1->setStanjeNaRacunuRSD(racun1->getStanjeNaRacunuRSD() - kolicina_novca_);
                racun2->setStanjeNaRacunuRSD(racun2->getStanjeNaRacunuRSD() + kolicina_novca_ - provizija_);
            }
        }
        else {
            if (kolicina_novca_ <= 0 || kolicina_novca_ > racun1->getStanjeNaRacunuRSD()) {
                printf("Uneli ste pogresnu vrednost!\n");
                continue;
            }
            provizija_ = 0.05 * kolicina_novca_;
            racun1->setStanjeNaRacunuRSD(racun1->getStanjeNaRacunuRSD() - kolicina_novca_);
            racun2->setStanjeNaRacunuRSD(racun2->getStanjeNaRacunuRSD() + kolicina_novca_ - provizija_);
        }
    }
    lista_transakcija.push_back(Transakcija(RSD, kolicina_novca_, racun1->getBrojRacuna(), racun2->getBrojRacuna(), datum, Primalac_, Posiljalac_, provizija_));
    racun1->id_transakcija.push_back(Transakcija::ID_transakcije);
}