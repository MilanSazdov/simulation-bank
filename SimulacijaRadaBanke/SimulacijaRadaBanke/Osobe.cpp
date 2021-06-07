#include <iostream>
#include <list>
#include "Osobe.h"

void Korisnik::Deposit() {
if (na_salteru == 0) {
    std::cout << "Niste na salteru!\n";
    return;
}
double novac = 0;
int koji = 0;
if (devizni_racun == NULL && dinarski_racun == NULL) {
    std::cout << "Nemate ni jedan racun!\n";
    return;
}
else if (devizni_racun == NULL) {
    dinarski_racun->Deposit(&kes);
}
else if (dinarski_racun == NULL) {
    devizni_racun->Deposit(&kes);
}
else {
    while (5) {
        std::cout << "Na koji racun hocete da dodate pare? (1 za devizni 2 za dinarski)\n";
        std::cin >> koji;
        if (koji == 1) {
            devizni_racun->Deposit(&kes);
        }
        else if (koji == 2) {
            dinarski_racun->Deposit(&kes);
        }
        else {
            printf("Uneli ste pogresan broj!\n");
            continue;
        }
        break;
    }
}
    }
void Korisnik::Withdraw() {
    if (na_salteru == 0) {
        std::cout << "Niste na salteru!\n";
        return;
    }
    double novac = 0;
    int koji = 0;
    if (devizni_racun == NULL && dinarski_racun == NULL) {
        std::cout << "Nemate ni jedan racun!\n";
        return;
    }
    else if (devizni_racun == NULL) {
        dinarski_racun->Withdraw(&kes);
    }
    else if (dinarski_racun == NULL) {
        devizni_racun->Withdraw(&kes);
    }
    else {
        while (5) {
            std::cout << "Sa kog racuna zelite da podignete pare? (1 za devizni 2 za dinarski)\n";
            std::cin >> koji;
            if (koji == 1) {
                devizni_racun->Withdraw(&kes);
            }
            else if (koji == 2) {
                dinarski_racun->Withdraw(&kes);
            }
            else {
                printf("Uneli ste pogresan broj!\n");
                continue;
            }
            break;
        }
    }
}
void Korisnik::KupiNesto() {
    double novac = 0;
    int koji = 0;
    while (5) {
        std::cout << "Kako placate? (1-kes 2-karticom)\n";
        std::cin >> koji;
        if (koji == 1) {
            while (5) {
                std::cout << "Unesite iznos proizvoda u RSD: ";
                std::cin >> novac;
                if (novac > kes) {
                    std::cout << "Nemate dovoljno para!\n";
                    continue;
                }
                break;
            }
        }
        else if (koji == 2) {

        }
        else {
            continue;
        }
        break;
    }
    if (debitna_kartica == NULL && kreditna_kartica == NULL) {
        std::cout << "Nemate ni jednu karticu!\n";
        return;
    }
    else if (debitna_kartica == NULL) {
        kreditna_kartica->KupiNesto();
    }
    else if (kreditna_kartica == NULL) {
        debitna_kartica->KupiNesto();
    }
    else {
        while (5) {
            std::cout << "Koju karticu zelite da iskoristite? (1 za kreditnu 2 za debitnu)\n";
            std::cin >> koji;
            if (koji == 1) {
                kreditna_kartica->KupiNesto();
            }
            else if (koji == 2) {
                debitna_kartica->KupiNesto();
            }
            else {
                printf("Uneli ste pogresan broj!\n");
                continue;
            }
            break;
        }
    }

}
void Korisnik::IzradiKarticu() {
    if (na_salteru == 0) {
        std::cout << "Niste na salteru!\n";
        return;
    }
    if (kreditna_kartica == NULL && debitna_kartica == NULL) {
        while (5) {
            std::cout << "Koju karticu hocete da izradite(1-kreditnu 2-debitnu)\n";
            int i;
            std::cin >> i;
            if (i == 1) {
                //kreditna_kartica.setRacun(devizni_racun); ILI KONSTRUKTOR SA PARAMETRIMA
            }
            else if (i == 2) {
                //debitna_kartica.setRacun(dinarski_racun); ILI KONSTRUKTOR SA PARAMETRIMA
            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
        }
    }
    else if (kreditna_kartica == NULL) {
        //debitna_kartica.setRacun(dinarski_racun); ILI KONSTRUKTOR SA PARAMETRIMA
    }
    else if (debitna_kartica == NULL) {
        //kreditna_kartica.setRacun(devizni_racun); ILI KONSTRUKTOR SA PARAMETRIMA
    }
    else {
        printf("Vec imate obe kartice!\n");
        return;
    }
}