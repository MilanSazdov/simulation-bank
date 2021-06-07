#include <iostream>
#include <list>
#include "TrezerSef.h"
#include "Racun.h"


void Sef::UzmiPareIzSefa(double* kes) {

    if (prazan) {
        std::cout << "Sef je prazan !!!" << std::endl;
        return;
    }

    if (otkljucan == false) {
        std::cout << "Sef je zakljucan !!!" << std::endl;
        return;
    }

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
void Sef::PlatiMesecnoIznajmljivanje(DevizniRacun& devracun) {

}
void Sef::PlatiMesecnoIznajmljivanje(double* kes) {

}