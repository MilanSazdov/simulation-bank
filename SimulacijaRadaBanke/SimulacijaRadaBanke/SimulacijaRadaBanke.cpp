// SimulacijaRadaBanke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

#define MAX_DUZINA 50
#define MAX_DUZINAJMBG 13

enum Bilans{POZITIVAN, NEGATIVAN};
enum Pol{MUSKI, ZENSKI};

typedef struct {

    int dan;
    int mesec;
    int godina;

}Datum;


class Osoba {

    protected:

        char ime[MAX_DUZINA];
        char prezime[MAX_DUZINA];
        Pol pol;
        Datum DatumRodjenja;
        char JMBG[MAX_DUZINAJMBG + 1]; /// +1 zbog \0
            
    public:

        Osoba() {
            strcpy(ime, "Branko");
            strcpy(prezime, "Mostic");
            pol = MUSKI;
            DatumRodjenja.dan = 5;
            DatumRodjenja.mesec = 6;
            DatumRodjenja.godina = 1990;
            strcpy(JMBG, "0506990074237");
        }


};

class LicnaKarta : public Osoba{
    
    protected:

        char BrojLicneKarte[MAX_DUZINA];
        Datum DatumIzdavanja;
        Datum DatumIstekaLicneKarte;
        Adresa adresa;

    public:

        LicnaKarta() {

            strcpy(BrojLicneKarte, "955555546");
            DatumIzdavanja.dan = 3;
            DatumIzdavanja.mesec = 4;
            DatumIzdavanja.godina = 2005;
            DatumIstekaLicneKarte.dan = 3;
            DatumIstekaLicneKarte.mesec = 4;
            DatumIstekaLicneKarte.godina = 2015;
            adresa.broj = 16;
            strcpy(adresa.Mesto, "Novi Sad");
            strcpy(adresa.Ulica, "Banovic Strahinja");

        }


};

typedef struct {

    int broj;
    char Mesto[MAX_DUZINA];
    char Ulica[MAX_DUZINA];

}Adresa;




class TekuciRacun : public LicnaKarta{
    
    private:


    public:
        

        


};

class ZiroRacun : public LicnaKarta{};

class DevizniRacun : public 

int main()
{
    std::cout << "Hello World!\n";
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
