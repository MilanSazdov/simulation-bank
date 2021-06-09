#include <iostream>
#include <list>
#include "Banka.h"
#include "Kurs.h"



void Banka::NapraviTransakciju(DevizniRacun& racun, Korisnik& korisnik) {

int valuta_; // Da moze da unese broj za valutu
TipValute valuta_original;
double kolicina_novca_;
int broj_kartice_;
Datum datum_transakcije_;
bool uspeh_transakcije_;
std::string Primalac_;
std::string Posiljalac_;
double provizija_; // provizija koju banka uzima

Transakcija::ID_transakcije++;

std::cout << "Unesite kome saljete novac: " << std::endl;
//TREBA PROVERA DA LI TAJ KORISNIK POSTOJI
std::cin >> Primalac_;

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

switch (valuta_)
{
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

    provizija_ = kamata_za_transakcije * kolicina_novca_;

    kolicina_novca_ -= provizija_;

    if (racun.getPrekoracenje()) {
        if (kolicina_novca_ <= 0 || kolicina_novca_ > racun.getStanjeNaRacunuEVRO() + racun.getMaxPrekoracenje()) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
        }
    }
    else
    {
        if (kolicina_novca_ <= 0 || kolicina_novca_ > racun.getStanjeNaRacunuEVRO()) {
            std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
        }
    }
} while (kolicina_novca_ <= 0);

racun.setStanjeNaRacunuEVRO(racun.getStanjeNaRacunuEVRO() - (kolicina_novca_ + provizija_));

// korisnik.DevizniRacun.setStanjeNaRacunuEVRO(korisnik.getStanjeNaRacunuEVRO + kolicina_novca_ );

    }