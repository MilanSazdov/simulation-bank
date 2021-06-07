#include <iostream>
#include <list>
#include "Krediti.h"
#include "Racun.h"

void Kredit::PlatiRatu(DinarskiRacun& racun) {

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
void Kredit::IsplatiCeoKredit(DinarskiRacun& racun) {

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
std::ostream& operator<<(std::ostream& os, const Kredit& kredit) {

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