#include "Korisnik.h";


Korisnik::Korisnik() {

    ID++;
    mesecna_plata = 0;
    datum_rodjenja = Datum(datum);
    adresa_stanovanja = Adresa();
    ime = "Predrag";
    prezime = "Vlah";
    broj_godina = 1;
    kes = 0;
    u_filijali = false;
    na_salteru = false;
    devizni_racun = NULL;
    dinarski_racun = NULL;
    debitna_kartica = NULL;
    kreditna_kartica = NULL;
    filijala = NULL;
    this->banka = NULL;
    sef = NULL;
    zahtev_za_kredit = NULL;
    id_korisnika = ID;
}

Korisnik::Korisnik(double mesecna_plata_, Datum datum_rodjenja_, Adresa adresa_stanovanja_, std::string ime_, std::string prezime_, int broj_godina_, double kes_, bool u_filijali_, bool na_salteru_, DevizniRacun* devizni_racun_, DinarskiRacun* dinarski_racun_, DebitnaKartica* debitna_kartica_, KreditnaKartica* kreditna_kartica_,Filijala* filijala_, Banka* banka_, Sef* sef_, ZahtevZaKredit* zahtev_za_kredit_) {

    ID++;
    mesecna_plata = mesecna_plata_;
    datum_rodjenja = Datum(datum_rodjenja_);
    adresa_stanovanja = Adresa(adresa_stanovanja_);
    ime = ime_;
    prezime = prezime_;
    broj_godina = broj_godina_;
    kes = kes_;
    u_filijali = u_filijali_;
    na_salteru = na_salteru_;
    devizni_racun = devizni_racun_;
    dinarski_racun = dinarski_racun_;
    debitna_kartica = debitna_kartica_;
    kreditna_kartica = kreditna_kartica_;
    filijala = filijala_;
    this->banka = banka_;
    sef = sef_;
    zahtev_za_kredit = zahtev_za_kredit_;
    id_korisnika = ID;
}

Korisnik::Korisnik(const Korisnik& korisnik) {

    mesecna_plata = korisnik.mesecna_plata;
    datum_rodjenja = Datum(korisnik.datum_rodjenja);
    adresa_stanovanja = Adresa(korisnik.adresa_stanovanja);
    ime = korisnik.ime;
    prezime = korisnik.prezime;
    broj_godina = korisnik.broj_godina;
    kes = korisnik.kes;
    u_filijali = korisnik.u_filijali;
    na_salteru = korisnik.na_salteru;
    devizni_racun = korisnik.devizni_racun;
    dinarski_racun = korisnik.dinarski_racun;
    debitna_kartica = korisnik.debitna_kartica;
    kreditna_kartica = korisnik.kreditna_kartica;
    filijala = korisnik.filijala;
    this->banka = korisnik.banka;
    sef = korisnik.sef;
    zahtev_za_kredit = korisnik.zahtev_za_kredit;

}

int Korisnik::getId()const {
    
    return id_korisnika;
}

double Korisnik::getKes()const {
    
    return kes;
}

bool Korisnik::getUFilijali()const {
    
    return u_filijali;
}

bool Korisnik::getNaSalteru()const {
    
    return na_salteru;
}

DevizniRacun* Korisnik::getDevizniRacun() {
    
    return devizni_racun;
}

DinarskiRacun* Korisnik::getDinarskiRacun() {
    
    return dinarski_racun;
}

DebitnaKartica* Korisnik::getDebitnaKartica() {

    return debitna_kartica;
}

KreditnaKartica* Korisnik::getKreditnaKartica() {
    
    return kreditna_kartica;
}

Filijala* Korisnik::getFilijala() {
    return filijala;
}

Banka* Korisnik::getBanka() {
    
    return this->banka;
}

Salter* Korisnik::getSalter() {
    
    return salter;
}

Sef* Korisnik::getSef() {

    return sef;
}

void Korisnik::setId(int id_) {

    id_korisnika = id_;
}

void Korisnik::setKes(double kes_) {
    
    kes = kes_;
}

void Korisnik::setUFilijali(bool u_filijali_) {
    
    u_filijali = u_filijali_;
}

void Korisnik::setNaSalteru(bool na_salteru_) {
    
    na_salteru = na_salteru_;
}

void Korisnik::setDevizniRacun(DevizniRacun* racun) {
    
    devizni_racun = racun;
}

void Korisnik::setDinarskiRacun(DinarskiRacun* racun) {
    
    dinarski_racun = racun;
}

void Korisnik::setDebitnaKartica(DebitnaKartica* kartica) {

    debitna_kartica = kartica;
}

void Korisnik::setKreditnaKartica(KreditnaKartica* kartica) {
    
    kreditna_kartica = kartica;
}

void Korisnik::setFilijala(Filijala* filijala_) {
    
    filijala = filijala_;
}

void Korisnik::setBanka(Banka* banka_) {
    
    this->banka = banka_;
}

void Korisnik::setSef(Sef* sef_) {

    sef = sef_;
}

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
                    return;
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
    if (broj_godina < 18) {
        std::cout << "Ne mozete kreirati karticu pre 18-te godine!\n";
        return;
    }
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
                int tip_kartice;
                int broj_kartice;
                Datum datum_izdavanja;
                Datum datum_isteka;
                int CV;
                while (5) {
                    printf("Unesite tip kartice: BRONZANA-0, SREBRNA-1, ZLATNA-2, SUPER-3 \n");
                    std::cin >> tip_kartice;
                    if (tip_kartice < 0 || tip_kartice > 3) {
                        printf("Uneli ste pogresan broj!!!\n");
                        continue;
                    }
                    break;
                }

                srand(time(0));
                broj_kartice = (rand() * rand() * rand() / rand()) % 100000;
                if (broj_kartice < 0) {
                    broj_kartice *= -1;
                }
                datum_izdavanja = Datum(datum); //datum je globalna promenjljiva;
                datum_isteka = Datum(datum.getDan(), datum.getMesec(), datum.getGodina() + 10); //datum je globalna promenjljiva;
                CV = rand() % 1000;
                kreditna_kartica = new KreditnaKartica((TipKartice)tip_kartice, broj_kartice, datum_izdavanja, datum_isteka, CV, devizni_racun);
                std::cout << "Vas broj kartice je: " << broj_kartice << " ,a CV je " << CV << std::endl;
            }

            else if (i == 2) {
                int tip_kartice;
                int broj_kartice;
                Datum datum_izdavanja;
                Datum datum_isteka;
                int CV;
                while (5) {
                    printf("Unesite tip kartice: BRONZANA-0, SREBRNA-1, ZLATNA-2, SUPER-3 \n");
                    std::cin >> tip_kartice;
                    if (tip_kartice < 0 || tip_kartice > 3) {
                        printf("Uneli ste pogresan broj!!!\n");
                        continue;
                    }
                    break;
                }

                srand(time(0));
                broj_kartice = (rand() * rand() * rand() / rand()) % 100000;
                if (broj_kartice < 0) {
                    broj_kartice *= -1;
                }
                datum_izdavanja = Datum(datum);
                datum_isteka = Datum(datum.getDan(), datum.getMesec(), datum.getGodina() + 10); //datum je globalna promenjljiva;
                CV = rand() % 1000;
                debitna_kartica = new DebitnaKartica((TipKartice)tip_kartice, broj_kartice, datum_izdavanja, datum_isteka, CV, dinarski_racun);
                std::cout << "Vas broj kartice je: " << broj_kartice << " ,a CV je " << CV << std::endl;

            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
            return;
        }
    }
    else if (kreditna_kartica == NULL) {
        int tip_kartice;
        int broj_kartice;
        Datum datum_izdavanja;
        Datum datum_isteka;
        int CV;
        while (5) {
            printf("Unesite tip kartice: BRONZANA-0, SREBRNA-1, ZLATNA-2, SUPER-3 \n");
            std::cin >> tip_kartice;
            if (tip_kartice < 0 || tip_kartice > 3) {
                printf("Uneli ste pogresan broj!!!\n");
                continue;
            }
            break;
        }

        srand(time(0));
        broj_kartice = (rand() * rand() * rand() / rand()) % 100000;
        if (broj_kartice < 0) {
            broj_kartice *= -1;
        }
        datum_izdavanja = Datum(datum); //datum je globalna promenjljiva;
        datum_isteka = Datum(datum.getDan(), datum.getMesec(), datum.getGodina() + 10); //datum je globalna promenjljiva;
        CV = rand() % 1000;
        kreditna_kartica = new KreditnaKartica((TipKartice)tip_kartice, broj_kartice, datum_izdavanja, datum_isteka, CV, devizni_racun);
        std::cout << "Vas broj kartice je: " << broj_kartice << " ,a CV je " << CV << std::endl;
        return;
    }
    else if (debitna_kartica == NULL) {
        int tip_kartice;
        int broj_kartice;
        Datum datum_izdavanja;
        Datum datum_isteka;
        int CV;
        while (5) {
            printf("Unesite tip kartice: BRONZANA-0, SREBRNA-1, ZLATNA-2, SUPER-3 \n");
            std::cin >> tip_kartice;
            if (tip_kartice < 0 || tip_kartice > 3) {
                printf("Uneli ste pogresan broj!!!\n");
                continue;
            }
            break;
        }

        srand(time(0));
        broj_kartice = (rand() * rand() * rand() / rand()) % 100000;
        if (broj_kartice < 0) {
            broj_kartice *= -1;
        }
        datum_izdavanja = Datum(datum);
        datum_isteka = Datum(datum.getDan(), datum.getMesec(), datum.getGodina() + 10); //datum je globalna promenjljiva;
        CV = rand() % 1000;
        debitna_kartica = new DebitnaKartica((TipKartice)tip_kartice, broj_kartice, datum_izdavanja, datum_isteka, CV, dinarski_racun);
        std::cout << "Vas broj kartice je: " << broj_kartice << " ,a CV je " << CV << std::endl;
        return;
    }
    else {
        printf("Vec imate obe kartice!\n");
        return;
    }
}
void Korisnik::OtvoriRacun() {
    if (broj_godina < 18) {
        std::cout << "Ne mozete otvoriti racun pre 18-te godine!\n";
        return;
    }
    if (na_salteru == 0) {
        std::cout << "Niste na salteru!\n";
        return;
    }

    if (devizni_racun != NULL && dinarski_racun != NULL) {
        printf("Vec imate oba racuna!\n");
        return;
    }
    else if (devizni_racun != NULL) {

        banka->lista_din_racuna.push_back(DinarskiRacun());
        std::list<DinarskiRacun>::iterator it = banka->lista_din_racuna.end();
        it--;
        dinarski_racun = &*it;
        std::cout << "Vas broj dinarskog racuna je: " << dinarski_racun->getBrojRacuna() << std::endl;
    }
    else if (dinarski_racun != NULL) {
        banka->lista_dev_racuna.push_back(DevizniRacun());
        std::list<DevizniRacun>::iterator it = banka->lista_dev_racuna.end();
        it--;
        devizni_racun = &*it;
        std::cout << "Vas broj deviznog racuna je: " << devizni_racun->getBrojRacuna() << std::endl;
    }
    else {
        while (5) {
            std::cout << "Koju racun hocete da otvorite ? (1-dinarski 2-devizni)\n";
            int i;
            std::cin >> i;
            if (i == 1) {
                banka->lista_din_racuna.push_back(DinarskiRacun());

                std::list<DinarskiRacun>::iterator it = banka->lista_din_racuna.end();
                it--;
                dinarski_racun = &*it;
                std::cout << "Vas broj dinarskog racuna je: " << dinarski_racun->getBrojRacuna() << std::endl;
            }
            else if (i == 2) {
                banka->lista_dev_racuna.push_back(DevizniRacun());
                std::list<DevizniRacun>::iterator it = banka->lista_dev_racuna.end();
                it--;
                devizni_racun = &*it;
                std::cout << "Vas broj deviznog racuna je: " << devizni_racun->getBrojRacuna() << std::endl;
            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
            return;
        }
    }



}
void Korisnik::ZatvoriRacun() {
    if (na_salteru == 0) {
        std::cout << "Niste na salteru!\n";
        return;
    }
    if (devizni_racun != NULL && dinarski_racun != NULL) {
        while (5) {
            std::cout << "Koji racun hocete da zatvorite ? (1-dinarski 2-devizni)\n";
            int i;
            std::cin >> i;
            if (i == 1) {
                std::list<DinarskiRacun>::iterator it = banka->lista_din_racuna.begin();
                for (; it != banka->lista_din_racuna.end(); it++) {
                    if (it->getBrojRacuna() == dinarski_racun->getBrojRacuna()) {
                        banka->lista_din_racuna.erase(it);
                        dinarski_racun = NULL;
                        return;
                    }
                }
            }
            else if (i == 2) {
                std::list<DevizniRacun>::iterator it = banka->lista_dev_racuna.begin();
                for (; it != banka->lista_dev_racuna.end(); it++) {
                    if (it->getBrojRacuna() == devizni_racun->getBrojRacuna()) {
                        banka->lista_dev_racuna.erase(it);
                        devizni_racun = NULL;
                        return;
                    }
                }
            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
            return;
        }
    }
    else if (devizni_racun != NULL) {
        std::list<DevizniRacun>::iterator it = banka->lista_dev_racuna.begin();
        for (; it != banka->lista_dev_racuna.end(); it++) {
            if (it->getBrojRacuna() == devizni_racun->getBrojRacuna()) {
                banka->lista_dev_racuna.erase(it);
                devizni_racun = NULL;
                return;
            }
        }
    }
    else if (dinarski_racun != NULL) {
        std::list<DinarskiRacun>::iterator it = banka->lista_din_racuna.begin();
        for (; it != banka->lista_din_racuna.end(); it++) {
            if (it->getBrojRacuna() == dinarski_racun->getBrojRacuna()) {
                banka->lista_din_racuna.erase(it);
                dinarski_racun = NULL;
                return;
            }
        }
    }
    else {
        printf("Nemate ni jedan racun!\n");
        return;
    }
}
void Korisnik::ZatvoriKarticu() {
    if (na_salteru == 0) {
        std::cout << "Niste na salteru!\n";
        return;
    }
    if (kreditna_kartica != NULL && debitna_kartica != NULL) {
        while (5) {
            std::cout << "Koju karticu hocete da zatvorite ? (1-kreditna 2-debitna)\n";
            int i;
            std::cin >> i;
            if (i == 1) {
                free(kreditna_kartica);
                kreditna_kartica = NULL;
            }
            else if (i == 2) {
                free(debitna_kartica);
                debitna_kartica = NULL;
            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
            return;
        }
    }
    else if (kreditna_kartica != NULL) {
        free(kreditna_kartica);
        kreditna_kartica = NULL;
        return;
    }
    else if (debitna_kartica != NULL) {
        free(debitna_kartica);
        debitna_kartica = NULL;
        return;
    }
    else {
        printf("Nemate ni jednu karticu!\n");
        return;
    }
}
void Korisnik::NapraviTransakciju(DevizniRacun* racun) {



    std::string Primalac_;


    int broj_racuna;
    std::cout << "Unesite kome saljete novac: " << std::endl;
    std::cin >> Primalac_;
    DevizniRacun* pom;
    while (5) {
        std::cout << "Unesite broj racuna na koji saljete novac: " << std::endl;
        std::cin >> broj_racuna;
        pom = banka->NadjiPoBrojuDev(broj_racuna);
        if (pom == NULL || pom == devizni_racun) {
            printf("Uneli ste neodgovarajuci broj racuna!\n");
            continue;
        }
        break;
    }
    banka->NapraviTransakciju(devizni_racun, pom, Primalac_, ime);

}
void Korisnik::NapraviTransakciju(DinarskiRacun* racun) {



    std::string Primalac_;


    int broj_racuna;
    std::cout << "Unesite kome saljete novac: " << std::endl;
    std::cin >> Primalac_;
    DinarskiRacun* pom;
    while (5) {
        std::cout << "Unesite broj racuna na koji saljete novac: " << std::endl;
        std::cin >> broj_racuna;
        pom = banka->NadjiPoBrojuDin(broj_racuna);
        if (pom == NULL || pom == dinarski_racun) {
            printf("Uneli ste neodgovarajuci broj racuna!\n");
            continue;
        }
        break;
    }
    banka->NapraviTransakciju(dinarski_racun, pom, Primalac_, ime);

}
void Korisnik::NapraviTransakciju() {
    if (na_salteru == 0) {
        printf("Niste na salteru!\n");
        return;
    }
    if (devizni_racun != NULL && dinarski_racun != NULL) {
        while (5) {
            std::cout << "Koji racun hocete da koristite ? (1-dinarski 2-devizni)\n";
            int i;
            std::cin >> i;
            if (i == 1) {
                NapraviTransakciju(dinarski_racun);
            }
            else if (i == 2) {
                NapraviTransakciju(devizni_racun);
            }
            else {
                std::cout << "Uneli ste pogresan broj!\n";
                continue;
            }
            return;
        }
    }
    else if (devizni_racun != NULL) {
        NapraviTransakciju(devizni_racun);
        return;
    }
    else if (dinarski_racun != NULL) {
        NapraviTransakciju(dinarski_racun);
        return;
    }
    else {
        printf("Nemate ni jedan racun!\n");
        return;
    }
}
void Korisnik::UzmiNovacIzSefa() {
    if (na_salteru == 0) {
        printf("Niste na salteru!\n");
        return;
    }
    sef->UzmiPareIzSefa(&kes);
}
void Korisnik::PlatiRatuSefa() {
    int pom;
    int pom2;
    printf("Unesite kako placate Ratu (1-kes 2-dinarski racun 3-devizni racun)");
    std::cin >> pom;
    if (pom == 1) {
        sef->PlatiMesecnoIznajmljivanje(&kes);
    }
    else if (pom == 2) {
        sef->PlatiMesecnoIznajmljivanje(*dinarski_racun);
    }
    else if (pom == 3) {
        sef->PlatiMesecnoIznajmljivanje(*devizni_racun);
    }
    else {
        printf("Uneli ste pogresan broj!\n");
    }
}
void Korisnik::IznajmiSef() {
    if (na_salteru == 0) {
        printf("Niste na salteru!\n");
        return;
    }
    sef = new Sef();
}
void Korisnik::NapustiSef() {
    if (na_salteru == 0) {
        printf("Niste na salteru!\n");
        return;
    }
    free(sef);
    sef == NULL;
}
void Korisnik::IdiUFilijalu() {
    if (u_filijali) {
        printf("Vec ste u filijali!\n");
        return;
    }
    printf("Unesite adresu filijale: ");
    Adresa adresa;
    adresa.UnesiAdresu();
    std::list<Filijala>::iterator it = banka->lista_filijala.begin();
    for (; it != banka->lista_filijala.end(); it++) {
        if (*(it->getAdresa()) == adresa) {
            u_filijali = 1;
            filijala = &(*it);
            return;
        }
    }
    printf("Uneli ste pogresnu adresu!\n");
    return;
}
void izjednaci(Salter* s1, Salter* s2) {
    s1 = s2;
}
void Korisnik::IdiNaSalter() {
    if (u_filijali == 0) {
        printf("Niste u filijali!\n");
        return;
    }
    if (na_salteru == 1) {
        printf("Vec ste na salteru!\n");
    }
    if (filijala->getSalter()->getZauzet() == 1) {
        printf("Salter je zauzet!\n");
        return;
    }
    na_salteru = true;
    filijala->getSalter()->setZauzet(1);
    salter = (Salter*)filijala->getSalter();

}
void Korisnik::IzadjiIzFilijale() {
    if (u_filijali == 0) {
        printf("Niste u filijali!\n");
        return;
    }
    u_filijali = 0;
    filijala = NULL;
}
void Korisnik::IzadjiSaSaltera() {
    if (na_salteru == 0) {
        printf("Niste na salteru!\n");
        return;
    }
    na_salteru = 0;
    salter = NULL;
}
void Korisnik::IsplatiPlatu() {
    kes += mesecna_plata;
}

std::list<Korisnik> lista_korisnika;




void VlasnikBanke::IzgradiFilijalu() {
    if (budzet < 100000) {
        printf("Nemate dovoljno pare!\n");
        return;
    }
    budzet -= 100000;
    banka->lista_filijala.push_back(Filijala());
    std::list<Filijala>::iterator it = banka->lista_filijala.end();
    it--;
    it->getAdresa()->UnesiAdresu();
}
/*
void VlasnikBanke::MenjajMesec() {
    datum.setMesec(datum.getMesec() + 1);
    if (datum.getMesec() == 13) {
        datum.setMesec(1);
        datum.setGodina(datum.getGodina() + 1);
    }
    std::list<Korisnik>::iterator it = lista_korisnika.begin();
    for (; it != lista_korisnika.end(); it++) {
        it->IsplatiPlatu();
        if (it->getKredit()->getPlacenaRataZaMesec() == 1) {
            it->getKredit()->setPlacenaRataZaMesec(0);
        }
        else {
            it->PlatiRatuKredita();
        }
        if (it->getSef()->getPlacenaRataZaMesec() == 1) {
            it->getSef()->setPlacenaRataZaMesec(0);
        }
        else {
            it->PlatiRatuSefa();
        }
    }
}*/


void VlasnikBanke::OtkljucajTrezor() {
    printf("Unesite adresu filijale: ");
    Adresa adresa;
    adresa.UnesiAdresu();
    std::list<Filijala>::iterator it = banka->lista_filijala.begin();
    for (; it != banka->lista_filijala.end(); it++) {
        if (*(it->getAdresa()) == adresa) {
            it->getTrezor()->setOtkljucan(1);
            return;
        }
    }
    printf("Uneli ste pogresnu adresu!\n");
    return;
}
void VlasnikBanke::ZakljucajTrezor() {
    printf("Unesite adresu filijale: ");
    Adresa adresa;
    adresa.UnesiAdresu();
    std::list<Filijala>::iterator it = banka->lista_filijala.begin();
    for (; it != banka->lista_filijala.end(); it++) {
        if (*(it->getAdresa()) == adresa) {
            it->getTrezor()->setOtkljucan(0);
            return;
        }
    }
    printf("Uneli ste pogresnu adresu!\n");
    return;
}
void VlasnikBanke::DodajPareUBankomat() {
    Adresa adresa;
    adresa.UnesiAdresu();
    std::list<Filijala>::iterator it = banka->lista_filijala.begin();
    for (; it != banka->lista_filijala.end(); it++) {
        if (*(it->getAdresa()) == adresa) {
            int novac;
            while (5) {
                printf("Unesite koliko dinara zelite da dodate u bankomat: \n");

                std::cin >> novac;
                if (novac <= 0 || novac > budzet) {
                    printf("Uneli ste pogresan broj!\n");
                }
                break;
            }
            budzet -= novac;
            it->getBankomat()->setPare_U_Bankomatu(it->getBankomat()->getPare_U_Bankomatu() + novac);
            return;
        }
    }
}
void VlasnikBanke::KupiVozilo() {

}
void VlasnikBanke::KupiTehniku() {

}