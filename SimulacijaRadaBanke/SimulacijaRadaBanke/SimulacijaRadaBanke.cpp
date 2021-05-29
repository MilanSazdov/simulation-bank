// Simulacija Rada Banke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

enum TipKredita{STAMBENI, ZA_AUTO, ZA_DUG, OSTALO};
enum TipKartice{BRONZANA, SREBRNA, ZLATNA, SUPER};

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

class Transakcija {

private:

    int broj_transakcije;
    int ID_transakcije;
    //Valuta valuta
    double kolicina_novca;
    int broj_kartice;
    Datum datum_transakcije;
    bool uspeh_transakcije;
    std::string Primalac;
    std::string Posiljalac;
    double provizija; // provizija koju banka uzima

public:

    // NEMA FUNKCIJA
};

//Apstraktna class 
class Racun {

protected:

    Datum datum_nastanka_racuna;
    int broj_racuna;
    bool prekoracenje;
    std::list<Transakcija> lista_tranzakcija;
    double naknada_za_mesecno_odrzavanje_racuna;
    double naknada_za_podizanje_gotovine_na_bankomatima;
    double max_depozit;
    double max_prekoracenja;
    double max_dodavanja;
    
public:

    bool getPrekoracenje()const {
        return prekoracenje;
    }

    double getMaxPrekoracenje()const{
        return max_prekoracenja;
    }

   
    virtual void Deposit(double* kes) = 0;
    virtual void Withdraw(double* kes) = 0;
    virtual void ZatvoriRacun(double* kes) = 0;

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

    void NapraviTransakciju() {
        
        int broj_transakcije_;
        int ID_transakcije_;
        //Valuta valuta
        double kolicina_novca_;
        int broj_kartice_;
        Datum datum_transakcije_;
        bool uspeh_transakcije_;
        std::string Primalac_;
        std::string Posiljalac_;
        double provizija_; // provizija koju banka uzima
        
    }
};

class DinarskiRacun : public Racun{

private: 

    double stanje_na_racunu_RSD;

public:

    double getStanjeNaRacunuRSD()const{
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

    void Withdraw(double* kes){
        
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
                if (stanje_na_racunu_RSD - novac <  -max_prekoracenja) {
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

class DevizniRacun : public Racun {

   // std::list<Valuta> lista_valuta;
    double stanje_na_racunu_EVRO;

public:

    void Deposit(double* kes){

        // *kes =po kursu u evro
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

            if (prekoracenje) {
                if (stanje_na_racunu_EVRO - novac < -max_prekoracenja) {
                    std::cout << "Ne mozete toliko para podici sa racuna !!!" << std::endl;
                    continue;
                }
            }

            break;
        }

        *kes += novac;
        stanje_na_racunu_EVRO -= novac;
    }

    friend std::ostream& operator<<(std::ostream& os, const DevizniRacun& racun) {

        os << "*** DINARSKI RACUN *** " << std::endl;
        os << (const Racun&)racun << std::endl;
        os << "Stanje na racunu EVRO : " << racun.stanje_na_racunu_EVRO << std::endl;
        os << "Lista valuta : " << std::endl;
       /* std::list<Valuta> ::const_iterator ip = lista_valuta.begin();
       
       for (; ip != lista_valuta.end(); ip++) {
            os << *ip << std::endl;
        }*/

        return os;
    }
};

class Kredit{
    
private:

    // U kredit stavljam id korisnika koji ima kredit, id ziranta;
    TipKredita tip_kredita;
    // Valuta valuta;
    double iznos_kredita;
    Datum rok_isplate;
    double mesecna_rata;
    // Kamata kamata
    bool zirant;
    //Korisnik zirant_osoba;
    bool placena_rata_za_mesec;
    double placeno_do_sada;
    

public:

    void PlatiRatu(DinarskiRacun& racun) {
        
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

    friend std::ostream& operator<<(std::ostream& os, const Kredit& kredit) {

        os<< "Tip kredita : " << kredit.tip_kredita << std::endl;
        os << "Valuta kredita : " << std::endl;
        os << "Ukupan iznos kredita : " << kredit.iznos_kredita << std::endl;
        os << "Mesecna rata kredita : " << kredit.mesecna_rata << std::endl;
        os << "Rok isplate kredita : " <<std::endl << kredit.rok_isplate << std::endl;
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

class Kartica {

protected:

    int broj_kartice;
    Datum datum_izdavanja;
    Datum datum_isteka;
    int CV; // broj na poledjini kartice
};

class DebitnaKartica : public Kartica{
    
    DinarskiRacun racun;
   
};

class KreditnaKartica : public Kartica{

    DevizniRacun racun;    
};

class Sef {

    int broj_sefa;
    //Valuta valuta
    double kolicina_novca;
    double mesecno_iznajmljivanje;
};

class Trezor {

    std::list<Sef> lista_sefova;
    static double ukupno_novca;
    int sifra; // sifra za otkljucavanje

};

class Korisnik : public Osoba {

    double kes; // u RSD
    bool u_filijali;
    bool na_salteru;
    bool u_cekaonici;
    bool za_salterom;
    int broj_u_redu;
    //DevizniRacun
    //DinarskiRacun
    //ListaTranzakcija
    //Nalog
    //OrocenaStednja
    //NeOrocenaStednja
    //Nalog
    //ZahtevZaKredit
    //ListaKredita
    //ListaSefova
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



int main()
{
    DinarskiRacun r;
    std::cout << r;
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
