#include <iostream>
#include <list>
#include "Krediti.h"
#include "Racun.h"


//Geteri 
TipKredita Kredit::getTipKredita()const {
    return tip_kredita;
}

double Kredit::getIznosKredita()const {
    return iznos_kredita;
}
Datum Kredit::getRokIsplate()const {
    return rok_isplate;
}
double Kredit::getMesecnaRata()const {
    return mesecna_rata;
}
double Kredit::getKamata()const {
    return kamata;
}
bool Kredit::getPlacenaRataZaMesec()const {
    return placena_rata_za_mesec;
}
double Kredit::getPlacenoDoSada()const {
    return placeno_do_sada;
}

//Seteri

void Kredit::setTipKredita(TipKredita tip_kredita_) {
    tip_kredita = tip_kredita_;
}
void Kredit::setIznosKredita(double iznos_kredita_) {
    iznos_kredita = iznos_kredita_;
}
void Kredit::setRokIsplate(Datum rok_isplate_) {
    rok_isplate = rok_isplate_;
}
void Kredit::setMesecnaRata(double mesecna_rata_) {
    mesecna_rata = mesecna_rata_;
}
void Kredit::setKamata(double kamata_) {
    kamata = kamata_;
}
void Kredit::setPlacenaRataZaMesec(bool placena_rata_za_mesec_) {
    placena_rata_za_mesec = placena_rata_za_mesec_;

}
void Kredit::setPlacenoDoSada(double placeno_do_sada_) {
    placeno_do_sada = placeno_do_sada_;
}

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