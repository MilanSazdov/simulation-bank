#include <iostream>
#include <list>
#include "Kurs.h"

Kurs::Kurs() {

    dolar = 0.85;
    franak = 0.93;
    marka = 0.54;
    kuna = 0.15;
    leji = 0.22;
    rsd = 0.0090;
    dolar_prodajna = 0.82;
    franak_prodajna = 0.91;
    marka_prodajna = 0.51;
    kuna_prodajna = 0.13;
    leji_prodajna = 0.20;
    rsd_prodajna = 0.0085;
}
Kurs::Kurs(double dolar_, double franak_, double marka_, double kuna_, double leji_, double rsd_, double dolar_p, double franak_p, double marka_p, double kuna_p, double leji_p, double rsd_p) {

    dolar = dolar_;
    franak = franak_;
    marka = marka_;
    kuna = kuna_;
    leji = leji_;
    rsd = rsd_;
    dolar_prodajna = dolar_p;
    franak_prodajna = franak_p;
    marka_prodajna = marka_p;
    kuna_prodajna = kuna_p;
    leji_prodajna = leji_p;
    rsd_prodajna = rsd_p;
}
Kurs::Kurs(Kurs& kurs) {

    dolar = kurs.dolar;
    franak = kurs.franak;
    marka = kurs.marka;
    kuna = kurs.kuna;
    leji = kurs.leji;
    rsd = kurs.rsd;
    dolar_prodajna = kurs.dolar_prodajna;
    franak_prodajna = kurs.franak_prodajna;
    marka_prodajna = kurs.marka_prodajna;
    kuna_prodajna = kurs.kuna_prodajna;
    leji_prodajna = kurs.leji_prodajna;
    rsd_prodajna = kurs.rsd_prodajna;
}
double Kurs::getDolar() const {
    return dolar;
}
double Kurs::getFranak()const {
    return franak;
}
double Kurs::getMarka()const {
    return marka;
}
double Kurs::getKuna()const {
    return kuna;
}
double Kurs::getLeji()const {
    return leji;
}
double Kurs::getRSD()const {
    return rsd;
}
double Kurs::getDolarProdajna()const {
    return dolar_prodajna;
}
double Kurs::getFranakProdajna()const {
    return franak_prodajna;
}
double Kurs::getMarkaProdajna()const {
    return marka_prodajna;
}
double Kurs::getKunaProdajna()const {
    return kuna_prodajna;
}
double Kurs::getLejiProdajna()const {
    return leji_prodajna;
}
double Kurs::getRSDPRODAJNA()const {
    return rsd_prodajna;
}
void Kurs::setDolar(double dolar_) {
    dolar = dolar_;
}
void Kurs::setFranak(double franak_) {
    franak = franak_;
}
void Kurs::setMarka(double marka_) {
    marka = marka_;
}
void Kurs::setKuna(double kuna_) {
    kuna = kuna_;
}
void Kurs::setLeji(double leji_) {
    leji = leji_;
}
void Kurs::setRSD(double rsd_) {
    rsd = rsd_;
}
void Kurs::setDolarProdajna(double dolar_) {
    dolar_prodajna = dolar_;
}
void Kurs::setFranakProdajna(double franak_) {
    franak_prodajna = franak_;
}
void Kurs::setMarkaProdajna(double marka_) {
    marka_prodajna = marka_;
}
void Kurs::setKunaProdajna(double kuna_) {
    kuna_prodajna = kuna_;
}
void Kurs::setLejiProdajna(double leji_) {
    leji_prodajna = leji_;
}
void Kurs::setRSDPRODAJNA(double rsd_) {
    rsd_prodajna = rsd_;
}
void Kurs::PromeniKurs() {

    int opcija;
    int opcija2;
    int opcija3;
    double iznos;

ponovo:

    do {
        std::cout << "Unesite valutu koju zelite da izmenite u kursu : " << std::endl;
        std::cout << "Unesite 1. za Dolar : " << std::endl;
        std::cout << "Unesite 2. za Franak : " << std::endl;
        std::cout << "Unesite 3. za Marku : " << std::endl;
        std::cout << "Unesite 4. za Kunu : " << std::endl;
        std::cout << "Unesite 5. za Leje : " << std::endl;
        std::cout << "Unesite 6. za RSD : " << std::endl;

        std::cin >> opcija;

        if (opcija < 1 || opcija > 6) {
            std::cout << "Uneli ste neodgovarajucu vrednost !!!" << std::endl;
        }

    } while (opcija < 1 || opcija > 6);

    do {
        std::cout << "Da li zelite da menjate kupovnu  ili prodajnu cenu ? " << std::endl;
        std::cout << "Unesite 1. za kupovnu : " << std::endl;
        std::cout << "Unesite 2. za prodajnu : " << std::endl;
        std::cin >> opcija2;

        if (opcija2 < 1 || opcija2 > 2) {
            std::cout << "Uneli ste neogovarajucu vrednost !!!" << std::endl;
        }

    } while (opcija2 < 1 || opcija2 > 2);

    do {
        std::cout << "Unesite novu vrednost(za kurs te valute) : " << std::endl;
        std::cin >> iznos;
        if (iznos < 0) {
            std::cout << "Uneli ste neogovarajucu vrednost !!!" << std::endl;
        }
    } while (iznos < 0);

    if (opcija2 == 1) {
        switch (opcija)
        {
        case 1:
            dolar = iznos;
            break;
        case 2:
            franak = iznos;
            break;
        case 3:
            marka = iznos;
            break;
        case 4:
            kuna = iznos;
            break;
        case 5:
            leji = iznos;
            break;
        case 6:
            rsd = iznos;
            break;
        }
    }

    if (opcija2 == 2) {
        switch (opcija)
        {
        case 1:
            dolar_prodajna = iznos;
            break;
        case 2:
            franak_prodajna = iznos;
            break;
        case 3:
            marka_prodajna = iznos;
            break;
        case 4:
            kuna_prodajna = iznos;
            break;
        case 5:
            leji_prodajna = iznos;
            break;
        case 6:
            rsd_prodajna = iznos;
            break;
        }
    }

    do {
        std::cout << "Da li zelite jos nesto da promenite ? " << std::endl;
        std::cout << "Unesite 1. za DA" << std::endl;
        std::cout << "Unesite 2. za NE" << std::endl;
        std::cin >> opcija3;
        if (opcija3 < 1 || opcija3 > 2) {
            std::cout << "Uneli ste neogovarajucu vrednost !!!" << std::endl;
        }

    } while (opcija3 < 1 || opcija3 > 2);

    if (opcija3 == 1) {
        goto ponovo;
    }
}
std::ostream& operator<<(std::ostream& os, const Kurs& kurs){

 os << "***** KUPOVNE CENE VALUTA *****" << std::endl;
 os << "1 Dolar = " << kurs.dolar << "Evra " << std::endl;
 os << "1 Franak = " << kurs.franak << "Evra " << std::endl;
 os << "1 Marka = " << kurs.marka << "Evra " << std::endl;
 os << "1 Kuna = " << kurs.kuna << "Evra " << std::endl;
 os << "1 Lej = " << kurs.leji << "Evra " << std::endl;
 os << "1 Dinar = " << kurs.rsd << "Evra " << std::endl;
 os << "***** PRODAJNE CENE VALUTA *****" << std::endl;
 os << "1 Dolar = " << kurs.dolar_prodajna << "Evra " << std::endl;
 os << "1 Franak = " << kurs.franak_prodajna << "Evra " << std::endl;
 os << "1 Marka = " << kurs.marka_prodajna << "Evra " << std::endl;
 os << "1 Kuna = " << kurs.kuna_prodajna << "Evra " << std::endl;
 os << "1 Lej = " << kurs.leji_prodajna << "Evra " << std::endl;
 os << "1 Dinar = " << kurs.rsd_prodajna << "Evra " << std::endl;

 return os;
    }

Kurs kurs;