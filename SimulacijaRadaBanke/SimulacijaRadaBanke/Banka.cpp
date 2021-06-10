#pragma warning( disable : 4996)
#include <iostream>
#include <list>
#include "Banka.h"
#include "Kurs.h"
#include "Datum.h"



Filijala::Filijala() {

    adresa = Adresa();
    salter = Salter();
    bankomat = Bankomat();
    trezor = Trezor();
}

Filijala::Filijala(Adresa adresa_, Salter salter_,Bankomat bankomat_, Trezor trezor_) {

    adresa = Adresa(adresa_);
    salter = Salter(salter_);
    bankomat = Bankomat(bankomat_);
    trezor = Trezor(trezor_);
}

Filijala::Filijala(const Filijala& filijala) {

    adresa = Adresa(filijala.adresa);
    salter = Salter(filijala.salter);
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

Trezor* Filijala::getTrezor() {
    return &trezor;
}

void Filijala::setAdresa(Adresa adresa_) {
    adresa = Adresa(adresa_);
}

void Filijala::setSalter(Salter salter_) {
    salter = Salter(salter_);
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
            if (kolicina_novca_ <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            }
            if (kolicina_novca_ > racun1->getStanjeNaRacunuEVRO() + racun1->getMaxPrekoracenje()) {
                std::cout << "Nemate dovoljno para!\n";
                return;
            }
        }
        else
        {
            if (kolicina_novca_ <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
            }
            if (kolicina_novca_ > racun1->getStanjeNaRacunuEVRO()) {
                std::cout << "Nemate dovoljno para!\n";
                return;
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
            if (kolicina_novca_ <= 0) {
                printf("Uneli ste pogresnu vrednost!\n");
                continue;
            }
            if (kolicina_novca_ - racun1->getMaxPrekoracenje() > racun1->getStanjeNaRacunuRSD()) {
                std::cout << "Nemate dovoljno para!\n";
                return;
            }
            else
            {
                provizija_ = 0.05 * kolicina_novca_;
                racun1->setStanjeNaRacunuRSD(racun1->getStanjeNaRacunuRSD() - kolicina_novca_);
                racun2->setStanjeNaRacunuRSD(racun2->getStanjeNaRacunuRSD() + kolicina_novca_ - provizija_);
            }
        }
        else {
            if (kolicina_novca_ <= 0) {
                printf("Uneli ste pogresnu vrednost!\n");
                continue;
            }
            if (kolicina_novca_ > racun1->getStanjeNaRacunuRSD()) {
                std::cout << "Nemate dovoljno para!\n";
                return;
            }
            provizija_ = 0.05 * kolicina_novca_;
            racun1->setStanjeNaRacunuRSD(racun1->getStanjeNaRacunuRSD() - kolicina_novca_);
            racun2->setStanjeNaRacunuRSD(racun2->getStanjeNaRacunuRSD() + kolicina_novca_ - provizija_);
        }
    }
    lista_transakcija.push_back(Transakcija(RSD, kolicina_novca_, racun1->getBrojRacuna(), racun2->getBrojRacuna(), datum, Primalac_, Posiljalac_, provizija_));
    racun1->id_transakcija.push_back(Transakcija::ID_transakcije);
}

Banka banka;

void citajTransakcije() {
    FILE* dat = fopen("transakcije.txt", "r");
    if (dat == NULL) {
        printf("Greska pri citanju!\n");
        exit;
    }
    int tip_valute;
    double kolicina_novca;
    int broj_racuna_posiljalac;
    int broj_racuna_primalac;
    int d;
    int m;
    int g;
    std::string Primalac;
    std::string Posiljalac;
    double provizija;
    while (5) {
        fscanf(dat, "%i", &tip_valute);
        fgetc(dat);
        if (feof(dat)) {
            break;
        }
        fscanf(dat, "%lf ", &kolicina_novca);
        fgetc(dat);
        fscanf(dat, "%i", &broj_racuna_posiljalac);
        fgetc(dat);
        fscanf(dat, "%i", &broj_racuna_primalac);
        fgetc(dat);
        fscanf(dat, "%i", &d);
        fgetc(dat);
        fscanf(dat, "%i", &m);
        fgetc(dat);
        fscanf(dat, "%i", &g);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Primalac);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Posiljalac);
        fgetc(dat);
        fscanf(dat, "%lf", &provizija);
        fgetc(dat);
        banka.lista_transakcija.push_back(Transakcija(TipValute(tip_valute), kolicina_novca, broj_racuna_primalac, broj_racuna_posiljalac, Datum(d, m, g), Primalac, Posiljalac, provizija));
    }
}
void IspisiTransakcije() {
    FILE* dat = fopen("transakcije.txt", "w");
    std::list<Transakcija>::iterator it = banka.lista_transakcija.begin();

    for (; it != banka.lista_transakcija.end(); it++) {
        fprintf(dat, "%i", it->getTipValute());
        fputc('\n', dat);
        fprintf(dat, "%lf ", it->getKolicinaNovca());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getBrojRacunaPosiljalac());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getBrojRacunaPrimalac());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getDatumTransakcija().getDan());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getDatumTransakcija().getMesec());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getDatumTransakcija().getGodina());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getPrimalac());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getPosiljalac());
        fputc('\n', dat);
        fprintf(dat, "%lf", it->getProvizija());
        fputc('\n', dat);
    }
}





void CitajFilijale() {
    FILE* dat = fopen("filijale.txt", "r");
    if (dat == NULL) {
        printf("Greska pri citanju!\n");
        exit;
    }
    std::string Ulica;
    int broj;
    std::string Drzava;
    std::string Mesto;

    int broj_saltera;
    bool zauzet;

    double mesecna_plata;
    int d, m, g;
    std::string Ulica1;
    int broj1;
    std::string Drzava1;
    std::string Mesto1;
    std::string ime;
    std::string prezime;
    int broj_godina;
    bool na_pauzi;
    int broj_saltera_za_kojim_radi;
    bool ispravan;
    double pare_u_bankomatu;
    double kamata;

    std::list<Sef> lista_sefova;
    int sifra; // sifra za otkljucavanje
    bool otkljucan;

    int broj_sefa;
    int valuta;
    double kolicina_novca;
    double mesecno_iznajmljivanje;
    bool placeno_mesecno_iznajmljivanje;

    while (4) {
        fscanf(dat, "%[^\n]s", Ulica);
        fgetc(dat);
        if (feof(dat)) {
            break;
        }
        fscanf(dat, "%i", &broj);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Drzava);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Mesto);
        fgetc(dat);
        fscanf(dat, "%i", &broj_saltera);
        fgetc(dat);
        fscanf(dat, "%i", &zauzet);
        fgetc(dat);
        fscanf(dat, "%lf", &mesecna_plata);
        fgetc(dat);
        fscanf(dat, "%i", &d);
        fgetc(dat);
        fscanf(dat, "%i", &m);
        fgetc(dat);
        fscanf(dat, "%i", &g);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Ulica1);
        fgetc(dat);
        fscanf(dat, "%i", &broj1);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Drzava1);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", Mesto1);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", ime);
        fgetc(dat);
        fscanf(dat, "%[^\n]s", prezime);
        fgetc(dat);
        fscanf(dat, "%i", &broj_godina);
        fgetc(dat);
        fscanf(dat, "%i", &na_pauzi);
        fgetc(dat);
        fscanf(dat, "%i", &broj_saltera_za_kojim_radi);
        fgetc(dat);
        fscanf(dat, "%i", &ispravan);
        fgetc(dat);
        fscanf(dat, "%lf", &pare_u_bankomatu);
        fgetc(dat);
        fscanf(dat, "%lf", &kamata);
        fgetc(dat);
        fscanf(dat, "%i", &sifra);
        fgetc(dat);
        fscanf(dat, "%i", &otkljucan);
        fgetc(dat);

        while (5) {
            char pom[40];
            fscanf(dat, "%[^\n]s", pom);
            fgetc(dat);
            if (pom == "!") {
                break;
            }
            broj_sefa = atoi(pom);
            fscanf(dat, "%i", &valuta);
            fgetc(dat);
            fscanf(dat, "%lf", &kolicina_novca);
            fgetc(dat);
            fscanf(dat, "%lf", &mesecno_iznajmljivanje);
            fgetc(dat);
            fscanf(dat, "%i", &placeno_mesecno_iznajmljivanje);
            fgetc(dat);
            lista_sefova.push_back(Sef(broj_sefa, (TipValute)valuta, kolicina_novca, mesecno_iznajmljivanje, placeno_mesecno_iznajmljivanje));
        }
        banka.lista_filijala.push_back(Filijala(Adresa(Ulica, broj, Drzava, Mesto), Salter(RadnikZaSalterom(mesecna_plata, Datum(d, m, g), Adresa(Ulica1, broj1, Drzava1, Mesto1), ime, prezime, broj_godina, na_pauzi), broj_saltera, zauzet), Bankomat(ispravan, NULL, NULL, pare_u_bankomatu, kamata), Trezor(lista_sefova, sifra, otkljucan)));
    }
    fclose(dat);
}
void IspisiFilijale() {
    FILE* dat = fopen("filijale.txt", "w");
    std::list<Filijala>::iterator it = banka.lista_filijala.begin();

    for (; it != banka.lista_filijala.end(); it++) {
        fprintf(dat, "%[^\n]s", it->getAdresa()->getUlica());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getAdresa()->getBroj());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getAdresa()->getDrzava());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getAdresa()->getMesto());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getBrojSaltera());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getZauzet());
        fputc('\n', dat);
        fprintf(dat, "%lf", it->getSalter()->getRadnikZaSalterom().getMesecnaPlata());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getDatumRodjenja().getDan());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getDatumRodjenja().getMesec());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getDatumRodjenja().getGodina());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getSalter()->getRadnikZaSalterom().getAdresaStanovanja().getUlica());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getAdresaStanovanja().getBroj());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getSalter()->getRadnikZaSalterom().getAdresaStanovanja().getDrzava());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getSalter()->getRadnikZaSalterom().getAdresaStanovanja().getMesto());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getSalter()->getRadnikZaSalterom().getIme());
        fputc('\n', dat);
        fprintf(dat, "%[^\n]s", it->getSalter()->getRadnikZaSalterom().getPrezime());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getBrojGodina());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getNaPauzi());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getSalter()->getRadnikZaSalterom().getId());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getBankomat()->getIspravan());
        fputc('\n', dat);
        fprintf(dat, "%lf", it->getBankomat()->getPare_U_Bankomatu());
        fputc('\n', dat);
        fprintf(dat, "%lf", it->getBankomat()->getKamata());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getTrezor()->getSifra());
        fputc('\n', dat);
        fprintf(dat, "%i", it->getTrezor()->getOtkljucan());
        fputc('\n', dat);
        std::list<Sef>::iterator it1 = it->getTrezor()->getListaSefova().begin();
        for (; it1 != it->getTrezor()->getListaSefova().end(); it1++) {
            fprintf(dat, "%[^\n]s", it1->getBrojSefa());
            fputc('\n', dat);
            fprintf(dat, "%i", it1->getValuta());
            fputc('\n', dat);
            fprintf(dat, "%lf", it1->getKolicinaNovca());
            fputc('\n', dat);
            fprintf(dat, "%lf", it1->getMesecnoIznajmljivanje());
            fputc('\n', dat);
            fprintf(dat, "%i", it1->getPlacenoMesecnoIznajmljivanje());
            fputc('\n', dat);
        }
        fputc('!', dat);
        fputc('\n', dat);

    }
}