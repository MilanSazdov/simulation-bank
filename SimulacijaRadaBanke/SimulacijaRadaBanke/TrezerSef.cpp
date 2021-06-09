#include <iostream>
#include <list>
#include "TrezerSef.h"
#include "Racun.h"


Sef::Sef() {

    broj_sefa = 1;
    valuta = RSD;
    kolicina_novca = 2000;
    mesecno_iznajmljivanje = 500;
    placeno_mesecno_iznajmljivanje = true;
}

Sef::Sef(int broj_sefa_, TipValute valuta_, double kolicina_novca_, double mesecno_iznajmljivanje_, bool placeno_mesecno_iznajmljivanje_) {

    broj_sefa = broj_sefa_;
    valuta = valuta_;
    kolicina_novca = kolicina_novca_;
    mesecno_iznajmljivanje = mesecno_iznajmljivanje_;
    placeno_mesecno_iznajmljivanje = placeno_mesecno_iznajmljivanje_;
}

Sef::Sef(Sef& sef) {

    broj_sefa = sef.broj_sefa;
    valuta = sef.valuta;
    kolicina_novca = sef.kolicina_novca;
    mesecno_iznajmljivanje = sef.mesecno_iznajmljivanje;
    placeno_mesecno_iznajmljivanje = sef.placeno_mesecno_iznajmljivanje;
}

void Sef::UzmiPareIzSefa(double* kes) {

    if (kolicina_novca == 0) {
        std::cout << "Nemate para u sefu !!!" << std::endl;
        return;
    }

    *kes += kolicina_novca;
}
bool Sef::PlatiMesecnoIznajmljivanje(DinarskiRacun& racun) {

    if (placeno_mesecno_iznajmljivanje == true) {
        std::cout << "Mesecno iznajmljivanje za sef je vec placeno !!! " << std::endl;
        return true;
    }

    if (racun.getPrekoracenje()) {
        if (racun.getMaxPrekoracenje() + racun.getStanjeNaRacunuRSD() < mesecno_iznajmljivanje) {
            std::cout << "Nemate dovoljno novca da platite mesecno iznajmljivanje sefa !!!" << std::endl;
            return false;
        }
    }
    else
    {
        if (racun.getStanjeNaRacunuRSD() < mesecno_iznajmljivanje) {
            std::cout << "Nemate dovoljno novca da platite mesecno iznajmljivanje sefa !!! " << std::endl;
            return false;
        }
    }

    racun.setStanjeNaRacunuRSD(racun.getStanjeNaRacunuRSD() - mesecno_iznajmljivanje);
    placeno_mesecno_iznajmljivanje = true;
    return true;
}

bool Sef::PlatiMesecnoIznajmljivanje(DevizniRacun& devracun) {

    if (placeno_mesecno_iznajmljivanje == true) {
        std::cout << "Mesecno iznajmljivanje za sef je vec placeno !!! " << std::endl;
        return true;
    }

    if (devracun.getPrekoracenje()) {
        if (devracun.getMaxPrekoracenje() + devracun.getStanjeNaRacunuEVRO() < mesecno_iznajmljivanje) {
            std::cout << "Nemate dovoljno novca da platite mesecno iznajmljivanje sefa !!!" << std::endl;
            return false;
        }
    }
    else
    {
        if (devracun.getStanjeNaRacunuEVRO() < mesecno_iznajmljivanje) {
            std::cout << "Nemate dovoljno novca da platite mesecno iznajmljivanje sefa !!! " << std::endl;
            return false;
        }
    }

    devracun.setStanjeNaRacunuEVRO(devracun.getStanjeNaRacunuEVRO() - mesecno_iznajmljivanje);
    placeno_mesecno_iznajmljivanje = true;
    return true;
}

bool Sef::PlatiMesecnoIznajmljivanje(double* kes) {

    if (placeno_mesecno_iznajmljivanje == true) {
        std::cout << "Mesecno iznajmljivanje za sef je vec placeno !!! " << std::endl;
        return true;
    }

    if (*kes < mesecno_iznajmljivanje) {
        std::cout << "Nemate dovoljno novca da platite mesecno iznajmljivanje !!!" << std::endl;
        return false;
    }

    return true;
}

int Sef::getBrojSefa()const {
    return broj_sefa;
}

TipValute Sef::getValuta()const {
    return valuta;
}

double Sef::getKolicinaNovca()const {
    return kolicina_novca;
}

double Sef::getMesecnoIznajmljivanje()const {
    return mesecno_iznajmljivanje;
}

bool Sef::getPlacenoMesecnoIznajmljivanje()const {
    return placeno_mesecno_iznajmljivanje;
}

void Sef::setBrojSefa(int broj_sefa_) {
    broj_sefa = broj_sefa_;
}

void Sef::setValuta(TipValute valuta_) {
    valuta = valuta_;
}

void Sef::setKolicinaNovca(double kolicina_novca_) {
    kolicina_novca = kolicina_novca_;
}

void Sef::setMesecnoIznajmljivanje(double mesecno_iznajmljivanje_) {
    mesecno_iznajmljivanje = mesecno_iznajmljivanje_;
}

void Sef::setPlacenoMesecnoIznajmljivanje(bool placeno_mesecno_iznajmljivanje_) {
    placeno_mesecno_iznajmljivanje = placeno_mesecno_iznajmljivanje_;
}

Trezor::Trezor() {

    sifra = 1;
    otkljucan = false;
}

Trezor::Trezor(std::list<Sef> lista_sefova_, int sifra_, bool otkljucan_) {
    
    lista_sefova = lista_sefova_;
    sifra = sifra_;
    otkljucan = otkljucan_;
}

Trezor::Trezor(const Trezor& trezor) {

    lista_sefova = trezor.lista_sefova;
    sifra = trezor.sifra;
    otkljucan = trezor.otkljucan;
}

std::list<Sef> Trezor::getListaSefova()const {
    return lista_sefova;
}
int Trezor::getSifra()const {
    return sifra;
}
bool Trezor::getOtkljucan()const {
    return otkljucan;
}

void Trezor::setListaSefova(std::list<Sef> lista_sefova_) {
    lista_sefova = lista_sefova_;
}
void Trezor::setSifra(int sifra_) {
    sifra = sifra_;
}
void Trezor::setOtkljucan(bool otkljucan_) {
    otkljucan = otkljucan_;
}

std::ostream& operator<<(std::ostream& os, const Trezor& trezor) {
    os << "Lista sefova : " << std::endl;
    std::list<Sef>::const_iterator it = trezor.lista_sefova.begin();
    
    for (; it != trezor.lista_sefova.end(); it++) {
        os << *it << std::endl;
    }

    os << "Sifra je : " << trezor.sifra << std::endl;
    os << "Otkljucan : ";
    if (trezor.otkljucan) {
        os << "DA" << std::endl;
    }
    else
    {
        os << "NE" << std::endl;
    }

    return os;
}