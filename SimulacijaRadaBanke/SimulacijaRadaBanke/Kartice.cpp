#include <iostream>
#include <list>
#include "Kartice.h"
#include "Kurs.h"

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

        //Prekoracenje treba pretvoriti u EVRO po kusu 
        if (racun->getPrekoracenje()) {
            if (racun->getStanjeNaRacunuEVRO() * kurs.getRSD_PRODAJNA < pom) {
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