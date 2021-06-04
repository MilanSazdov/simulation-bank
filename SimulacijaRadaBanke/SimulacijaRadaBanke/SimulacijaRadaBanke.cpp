// Simulacija Rada Banke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

enum TipKredita { STAMBENI, ZA_AUTO, ZA_DUG, OSTALO };
enum TipKartice { BRONZANA, SREBRNA, ZLATNA, SUPER };
enum TipValute { EVRO, DOLAR, FRANAK, MARKA, KUNA, LEJI, RSD };


class Datum {

    int dan;
    int mesec;
    int godina;

public:


    friend std::ostream& operator<<(std::ostream& os, const Datum& datum) {
        os << "Dan je : " << datum.dan << std::endl;
        os << "Mesec je : " << datum.mesec << std::endl;
        os << "Godina je : " << datum.godina << std::endl;

        return os;
    }
};

class Adresa {

    char Ulica[40];
    int broj;
    char Drzava[40];
    char Mesto[40];
};

class Osoba {

protected:
    Datum datum_rodjenja;
    Adresa adresa_stanovanja;
    char ime[40];
    char prezime[40];
    int broj_godina;
};

class Korisnik : public Osoba {

    double kes; // u RSD
    bool u_filijali;
    bool na_salteru;
    bool u_cekaonici;
    bool za_salterom;
    int broj_u_redu;
    //DevizniRacun;
    //DinarskiRacun;
    //ListaTranzakcija
    //Nalog
    //OrocenaStednja
    //NeOrocenaStednja
    //Nalog
    //ZahtevZaKredit
    //ListaKredita
    //ListaSefova
};

class Kurs {

private:

    //KUPOVNE CENE ISPOD
    double dolar; // 0.85
    double franak; // 0.93
    double marka; // 0.54
    double kuna;  // 0.15
    double leji;  // 0.22
    double rsd;   // 0.0090
    //PRODAJNE CENE ISPOD
    double dolar_prodajna; // 0.82
    double franak_prodajna; // 0.91
    double marka_prodajna; // 0.51
    double kuna_prodajna; // 0.13
    double leji_prodajna; // 0.20
    double rsd_prodajna; // 0.0085

public:

    Kurs() {

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

    Kurs(double dolar_, double franak_, double marka_, double kuna_, double leji_, double rsd_, double dolar_p, double franak_p, double marka_p, double kuna_p, double leji_p, double rsd_p) {

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

    Kurs(Kurs& kurs) {

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


    double getDolar() const {
        return dolar;
    }

    double getFranak()const {
        return franak;
    }

    double getMarka()const {
        return marka;
    }

    double getKuna()const {
        return kuna;
    }

    double getLeji()const {
        return leji;
    }

    double getRSD()const {
        return rsd;
    }

    double getDolarProdajna()const {
        return dolar_prodajna;
    }

    double getFranakProdajna()const {
        return franak_prodajna;
    }

    double getMarkaProdajna()const {
        return marka_prodajna;
    }

    double getKunaProdajna()const {
        return kuna_prodajna;
    }

    double getLejiProdajna()const {
        return leji_prodajna;
    }

    double getRSDPRODAJNA()const {
        return rsd_prodajna;
    }

    void setDolar(double dolar_) {
        dolar = dolar_;
    }

    void setFranak(double franak_) {
        franak = franak_;
    }

    void setMarka(double marka_) {
        marka = marka_;
    }

    void setKuna(double kuna_) {
        kuna = kuna_;
    }

    void setLeji(double leji_) {
        leji = leji_;
    }

    void setRSD(double rsd_) {
        rsd = rsd_;
    }

    void setDolarProdajna(double dolar_) {
        dolar_prodajna = dolar_;
    }

    void setFranakProdajna(double franak_) {
        franak_prodajna = franak_;
    }

    void setMarkaProdajna(double marka_) {
        marka_prodajna = marka_;
    }

    void setKunaProdajna(double kuna_) {
        kuna_prodajna = kuna_;
    }

    void setLejiProdajna(double leji_) {
        leji_prodajna = leji_;
    }

    void setRSDPRODAJNA(double rsd_) {
        rsd_prodajna = rsd_;
    }

    void PromeniKurs() {

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

    friend std::ostream& operator<<(std::ostream& os, const Kurs& kurs) {

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
};

//GLOBALNA PROMENLJIVA
Kurs kurs;

class Transakcija {

private:

    TipValute tip_valute; // tip_valute = valuta_original
    double kolicina_novca;
    int broj_kartice;
    Datum datum_transakcije;
    bool uspeh_transakcije;
    std::string Primalac;
    std::string Posiljalac;
    double provizija; // provizija koju banka uzima

public:
    static int ID_transakcije; // Na nivou banke

    Transakcija() {

    }

    // Odbij tansakciju i odobri transakciju
};

//Apstraktna class 
class Racun {

protected:

    Datum datum_nastanka_racuna;
    int broj_racuna;
    bool prekoracenje;
    std::list<int> id_transakcija;
    double naknada_za_mesecno_odrzavanje_racuna;
    double naknada_za_podizanje_gotovine_na_bankomatima;
    double max_depozit;
    double max_prekoracenja;
    double max_dodavanja;

public:

    bool getPrekoracenje()const {
        return prekoracenje;
    }

    double getMaxPrekoracenje()const {
        return max_prekoracenja;
    }


    virtual void Deposit(double* kes) = 0; // Dodaj na racun
    virtual void Withdraw(double* kes) = 0; // Skini sa racuna
    virtual void NapraviTransakciju() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Racun& racun) {

        os << "Datum nastanka racuna : " << std::endl;
        os << racun.datum_nastanka_racuna << std::endl;
        os << "Broj racuna : " << racun.broj_racuna << std::endl;
        os << "Dozvoljeni minus / prekoracenje : ";
        if (racun.prekoracenje) {
            os << "DA" << std::endl;
            os << "MAX prekoracenje : " << racun.max_prekoracenja << std::endl;
        }
        else
        {
            os << "NE" << std::endl;
        }

        os << "Naknada za mesecno odrzavanje : " << racun.naknada_za_mesecno_odrzavanje_racuna << std::endl;
        os << "Naknada za podizanje gotovine na bankomatima : " << racun.naknada_za_podizanje_gotovine_na_bankomatima << std::endl;
        os << "MAX Depozit : " << racun.max_depozit << std::endl;
        os << "Lista transakcija : " << std::endl;
        // os << racun.lista_tranzakcija << std::endl;
        os << "MAX novca za dodavanje : " << racun.max_dodavanja << std::endl;

        return os;
    }
};

class DinarskiRacun : public Racun {

private:

    double stanje_na_racunu_RSD;
    std::list<int> id_transakcija;


public:
    static int id;

    double getStanjeNaRacunuRSD()const {
        return stanje_na_racunu_RSD;
    }

    void setStanjeNaRacunuRSD(double stanje_na_racunu_RSDD) {
        stanje_na_racunu_RSD = stanje_na_racunu_RSDD;
    }

    void Deposit(double* kes) {

        double novac;

        if (*kes == 0) {
            std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
            return;
        }

        while (5)
        {

            std::cout << "Unesite svotu novca u RSD koju hocete da dodate na racun : " << std::endl;
            std::cin >> novac;
            if (novac > max_dodavanja || novac <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
                continue;
            }
            if (*kes - novac < 0) {
                std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
                continue;
            }

            break;
        }

        *kes -= novac;
        stanje_na_racunu_RSD += novac;
    }

    void Withdraw(double* kes) {

        if (prekoracenje) {
            if (stanje_na_racunu_RSD == -max_prekoracenja) {
                std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
                return;
            }
        }
        else
        {
            if (stanje_na_racunu_RSD == 0) {
                std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
                return;
            }
        }

        double novac;

        while (5)
        {
            std::cout << "Koliko para hocete da skinete sa racuna : " << std::endl;
            std::cin >> novac;
            if (novac <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
                continue;
            }

            if (prekoracenje) {
                if (stanje_na_racunu_RSD - novac < -max_prekoracenja) {
                    std::cout << "Ne mozete toliko para podici sa racuna !!!" << std::endl;
                    continue;
                }
            }

            break;
        }

        *kes += novac;
        stanje_na_racunu_RSD -= novac;
    }

    friend std::ostream& operator<<(std::ostream& os, const DinarskiRacun& racun) {

        os << "*** DINARSKI RACUN *** " << std::endl;
        os << (const Racun&)racun << std::endl;
        os << "Stanje na racunu RSD : " << racun.stanje_na_racunu_RSD << std::endl;

        return os;
    }
};

int DinarskiRacun::id = -1;

class DevizniRacun : public Racun {

    double stanje_na_racunu_EVRO;
    std::list<TipValute> lista_valuta; // NE SME BITI PONAVLJANJA, TREBA PROVERA ZA TO
    std::list<int> lista_transakcija;


public:
    static int id;

    double getStanjeNaRacunuEVRO()const {
        return stanje_na_racunu_EVRO;
    }

    void setStanjeNaRacunuEVRO(double stanje_na_racunu_EVRO_) {
        stanje_na_racunu_EVRO = stanje_na_racunu_EVRO_;
    }

    void Deposit(double* kes) {

        *kes = *kes * kurs.getRSDPRODAJNA(); // prebacaj u evre
        double novac;

        if (*kes == 0) {
            std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
            return;
        }

        while (5)
        {

            std::cout << "Unesite svotu novca u RSD koju hocete da dodate na racun : " << std::endl;
            std::cin >> novac;
            if (novac > max_dodavanja || novac <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
                continue;
            }
            novac = novac * kurs.getRSDPRODAJNA();
            if (*kes - novac < 0) {
                std::cout << "Nemate dovoljno para u kesu !!! " << std::endl;
                continue;
            }

            break;
        }

        *kes -= novac;
        *kes = *kes / kurs.getRSD(); // vracenje u dinare
        stanje_na_racunu_EVRO += novac;
    }

    void Withdraw(double* kes) {

        if (prekoracenje) {
            if (stanje_na_racunu_EVRO == -max_prekoracenja) {
                std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
                return;
            }
        }
        else
        {
            if (stanje_na_racunu_EVRO == 0) {
                std::cout << "Nemate dovoljno para na racunu !!! " << std::endl;
                return;
            }
        }

        double novac;

        while (5)
        {
            std::cout << "Koliko para hocete da skinete sa racuna : " << std::endl;
            std::cin >> novac;
            if (novac <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
                continue;
            }

            novac = novac * kurs.getRSDPRODAJNA(); // prebacivanje u evro

            if (prekoracenje) {
                if (stanje_na_racunu_EVRO - novac < -max_prekoracenja) {
                    std::cout << "Ne mozete toliko para podici sa racuna !!!" << std::endl;
                    continue;
                }
            }

            break;
        }

        stanje_na_racunu_EVRO -= novac; // skidam u evrima
        novac = novac / kurs.getRSD(); // vracam u dinare
        *kes += novac; // dodajem u dinarima

    }


    friend std::ostream& operator<<(std::ostream& os, const DevizniRacun& racun) {

        os << "*** DINARSKI RACUN *** " << std::endl;
        os << (const Racun&)racun << std::endl;
        os << "Stanje na racunu EVRO : " << racun.stanje_na_racunu_EVRO << std::endl;
        os << "*** Lista valuta koje podrzava:  ***" << std::endl;
        std::list<TipValute> ::const_iterator ip = racun.lista_valuta.begin();

        for (; ip != racun.lista_valuta.end(); ip++) {

            switch (*ip)
            {
            case 0:
                os << "EVRO" << std::endl;
                break;
            case 1:
                os << "Dolar" << std::endl;
                break;
            case 2:
                os << "Franak" << std::endl;
                break;
            case 3:
                os << "Marka" << std::endl;
                break;
            case 4:
                os << "Kuna" << std::endl;
                break;
            case 5:
                os << "Lej" << std::endl;
                break;
            case 6:
                os << "Dinar" << std::endl;
                break;
            }
        }

        return os;
    }
};

int DevizniRacun::id = -1;

class Kredit {

private:

    // U kredit stavljam id korisnika koji ima kredit, id ziranta;
    int id_ziranta;
    TipKredita tip_kredita;
    double iznos_kredita;
    Datum rok_isplate;
    double mesecna_rata;
    bool kamata;
    double kamata;
    bool zirant;
    bool placena_rata_za_mesec;
    double placeno_do_sada;


public:

    static int id;

    void PlatiRatu(DinarskiRacun& racun) {

        if (placena_rata_za_mesec == true) {
            std::cout << "Vec ste platili ratu za ovaj mesec !!! " << std::endl;
            return;
        }

        if (racun.getPrekoracenje()) {
            if (racun.getStanjeNaRacunuRSD() + racun.getMaxPrekoracenje() < mesecna_rata) {
                std::cout << "Nemate dovoljno para na racunu da platite ratu kredita !!!" << std::endl;
                return;
            }

            racun.setStanjeNaRacunuRSD(racun.getStanjeNaRacunuRSD() - mesecna_rata);
        }

        else
        {
            if (racun.getStanjeNaRacunuRSD() < mesecna_rata) {
                std::cout << "Nemate dovoljno para na racunu da platite ratu kredita !!!" << std::endl;
                return;
            }

            racun.setStanjeNaRacunuRSD(racun.getStanjeNaRacunuRSD() - mesecna_rata);
        }

        placena_rata_za_mesec = true;
    }

    // KOD KORISNIKA TREBA OVA FUNKCIJA
    void IsplatiCeoKredit(DinarskiRacun& racun) {

        if (racun.getPrekoracenje()) {
            if (racun.getMaxPrekoracenje() + racun.getStanjeNaRacunuRSD() < iznos_kredita - placeno_do_sada) {
                std::cout << "Nemate dovoljno novca na racunu da isplatite ceo kredit !!!" << std::endl;
                return;
            }
        }
        else
        {
            if (racun.getStanjeNaRacunuRSD() < iznos_kredita - placeno_do_sada) {
                std::cout << "Nemate dovoljno novca na racunu da isplatite ceo kredit !!!" << std::endl;
                return;
            }
        }

        racun.setStanjeNaRacunuRSD(racun.getStanjeNaRacunuRSD() - (iznos_kredita - placeno_do_sada));
        placeno_do_sada = iznos_kredita;
        iznos_kredita = 0;


        // Sad ga treba izbrisati iz datoteke
    }

    friend std::ostream& operator<<(std::ostream& os, const Kredit& kredit) {

        os << "Tip kredita : " << kredit.tip_kredita << std::endl;
        os << "Valuta kredita : " << std::endl;
        os << "Ukupan iznos kredita : " << kredit.iznos_kredita << std::endl;
        os << "Mesecna rata kredita : " << kredit.mesecna_rata << std::endl;
        os << "Rok isplate kredita : " << std::endl << kredit.rok_isplate << std::endl;
        os << "Zirant : ";
        if (kredit.zirant) {
            os << "DA" << std::endl;
            // std::cout << zirant_osoba << std::endl;
        }
        else
        {
            os << "NE" << std::endl;
        }
        os << "Da li je placena rata za tekuci mesec : ";
        if (kredit.placena_rata_za_mesec) {
            os << "DA" << std::endl;
        }
        else
        {
            os << "NE" << std::endl;
        }

        os << "Ukupno placeno do sada : " << kredit.placeno_do_sada << std::endl;


        return os;
    }

};

class ZahtevZaKredit {


};

class Kartica {

protected:


    TipKartice tip_kartice;
    int broj_kartice;
    Datum datum_izdavanja;
    Datum datum_isteka;
    int CV; // broj na poledjini kartice

public:

    virtual void KupiNesto() = 0;

};

class DebitnaKartica : public Kartica {

private:

    DinarskiRacun* racun;

public:

    static int id;

    void KupiNesto() {

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

};

class KreditnaKartica : public Kartica {

private:

    static int id;
    DevizniRacun* racun;

public:

    void KupiNesto() {

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
                // pom = pom * kurs.getDolar();
                break;
            case 2:
                // pom = pom * kurs.getFranak();
                break;
            case 3:
                // pom = pom * kurs.getMarka();
                break;
            case 4:
                //  pom = pom * kurs.getKuna();
                break;
            case 5:
                //  pom = pom * kurs.getLeji();
                break;
            case 6:
                //  pom = pom * kurs.getRSD();
                break;
            }

            if (pom <= 0) {
                std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
                continue;
            }

            //Prekoracenje treba pretvoriti u EVRO po kusu 
            if (racun->getPrekoracenje()) {
                /*   if (racun->getStanjeNaRacunuEVRO() * kurs.getRSD_PRODAJNA < pom) {
                        std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                        continue;
                    }*/
            }/*
            else
            {
               if (racun.getStanjeNaRacunuEVRO() < pom) {
                    std::cout << "Nemate dovoljno novca na kartici !!! " << std::endl;
                    continue;
                }
            }*/

            break;

        } while (5);


        // racun.setStanjeNaRacunuEVRO(racun.getStanjeNaRacunuEVRO() - pom);
    }
};

class Sef {

private:

    int broj_sefa;
    bool prazan;
    bool slobodan;
    bool otkljucan;
    TipValute valuta;
    double kolicina_novca;
    double mesecno_iznajmljivanje;
    bool placeno_mesecno_iznajmljivanje;

public:

    static int id;

    void UzmiPareIzSefa(double* kes) {

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

    bool PlatiMesecnoIznajmljivanje(DinarskiRacun& racun) {

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

    void PlatiMesecnoIznajmljivanje(DevizniRacun& devracun) {

    }

    void PlatiMesecnoIznajmljivanje(double* kes) {

    }
};

class Trezor {

private:

    std::list<Sef> lista_sefova;
    int sifra; // sifra za otkljucavanje
    bool otkljucan;

public:

    static double ukupno_novca;

    // Otkljucaj Trezor
    // Zakljucaj Trezor
};



class RadnikZaSalterom : public Osoba {

    bool na_pauzi;
    float plata;//u dinarima
    int broj_saltera_za_kojim_radi;
};

class Salter {

    int broj_saltera;
    bool zauzet;
    bool pauza;
};

class Smena {

    std::list<RadnikZaSalterom> lista_radnika;
    char vreme_pocetka[20];
    char vreme_pocetka_vikendom[20];
    char vreme_kraja[20];
    char vreme_kraja_vikendom[20];
};

class Banka {

private:

    std::list<Transakcija> lista_transakcija;
    double kamata_za_transakcije;

public:

    void NapraviTransakciju(DinarskiRacun& racun) {


    }

    void NapraviTransakciju(DevizniRacun& racun, Korisnik& korisnik) {

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
};


int main()
{

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
