#include<iostream>
#include<list>
#include "Kurs.h"
#include "Korisnik.h"
#include "Banka.h"

VlasnikBanke vlasnik_banke;

void MeniKorisnik() {

}

void Meni(Korisnik* korisnik, VlasnikBanke* vlasnik, RadnikZaSalterom* radnik_za_salterom) {

	int opcija;
	int i;
	int login_korisnika;
	int login_radnik;
	int login_vlasnik;
	bool nasao = false; // da li je nasao odgovarajuceg korisnika
	bool nasao_radnika = false;
	std::list<Korisnik>::iterator it = lista_korisnika.begin();
	std::list<Filijala>::iterator it2 = banka.lista_filijala.begin();

	std::string ime;
	std::string prezime;
	int broj_godina;
	Datum rodjenja;
	std::string ulica;
	std::string mesto;
	std::string drzava;
	int broj_ulica;
	double mesecna_plata;

	bool u_filijali;
	bool na_salteru;
	bool u_cekaonici;
	int broj_u_redu;
	DevizniRacun* devizni_racun;
	DinarskiRacun* dinarski_racun;
	DebitnaKartica* debitna_kartica;
	KreditnaKartica* kreditna_kartica;
	Filijala* filijala;
	Banka* banka1;
	Salter* salter;
	Sef* sef;

	do {

		std::cout << "*** Unesite opciju iz menija ***" << std::endl;
		std::cout << "Unesite 0. za izlaz iz programa : " << std::endl;
		std::cout << "Unesite 1. da se loginujete kao korisnik : " << std::endl;
		std::cout << "Unesite 2. da se loginujete kao radnik na salteru : " << std::endl;
		std::cout << "Unesite 3. da se loginujete kao vlasnik : " << std::endl;
		std::cout << "Unesite 4. da napravite novog korisnika : " << std::endl;
		std::cout << "Unesite 5. da napravite novog radnika za salterom : " << std::endl;
		std::cin >> opcija;

		if (opcija < 0 || opcija > 5) {
			std::cout << "Uneli ste neodgovarajucu vrednost !!!" << std::endl;
		}

		switch (opcija)
		{
		case 1:
			std::cout << "Unesite id korisnika : " << std::endl;
			std::cin >> login_korisnika;
			for (; it != lista_korisnika.end(); it++)
			{
				if (it->getId() == login_korisnika) {
					nasao = true;
					break;
				}
			}

			if (nasao) {
				std::cout << "Uspesno ste se loginovali !!! " << std::endl;
				korisnik = &(*it);
				opcija = 0;
			}

			else
			{
				std::cout << "Loginovanje je neuspesno !!!" << std::endl;
			}

			break;
		case 2:
			std::cout << "Unesite id radnika banke : " << std::endl;
			std::cin >> login_radnik;

			for (; it2 != banka.lista_filijala.end(); it2++)
			{

				if (it2->getSalter()->getRadnikZaSalterom().getId() == login_radnik) {

					nasao_radnika = true;
					break;
				}
			}

			if (nasao_radnika) {
				std::cout << "Uspesno ste se loginovali !!!" << std::endl;
				//radnik_za_salterom = &it2->getSalter()->getRadnikZaSalterom(); CEMENT
				opcija = 0;
			}

			else
			{
				std::cout << "Loginovanje je neuspesno !!!" << std::endl;
			}

			break;
		case 3:

			std::cout << "Uspesno ste se loginovali !!!" << std::endl;
			vlasnik = &vlasnik_banke;
			opcija = 0;

			break;
		case 4:
			//kes = 0;


			std::cout << "Unesite Vase ime : " << std::endl;
			std::cin >> ime;
			std::cout << "Uneste Vase prezime : " << std::endl;
			std::cin >> prezime;

			do {

				std::cout << "Koliko imate godina : " << std::endl;
				std::cin >> broj_godina;
				if (broj_godina < 0 || broj_godina > 100) {
					std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
				}

			} while (broj_godina < 0 || broj_godina > 100);

			std::cout << "Unesite naziv ulice : " << std::endl;
			std::cin >> ulica;
			std::cout << "Unesite mesto : " << std::endl;
			std::cin >> mesto;
			std::cout << "Unesite drzavu : " << std::endl;
			std::cin >> drzava;

			do {
				std::cout << "Unesite broj ulice : " << std::endl;
				std::cin >> broj_ulica;
				if (broj_ulica < 0) {
					std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
				}

			} while (broj_ulica < 0);

			do {

				std::cout << "Unesite vasu mesecnu platu : " << std::endl;
				std::cin >> mesecna_plata;

				if (mesecna_plata < 0) {
					std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
				}

			} while (mesecna_plata < 0);


			break;
		case 5:
			break;
		}

	} while (opcija != 0);
}


void MeniVlasnikBanke() {

}

void MeniRadnikZaSalterom() {

}

int main() {

	vlasnik_banke.banka = &banka;

	Korisnik* korisnik;
	VlasnikBanke* vlasnik;
	RadnikZaSalterom* radnik_za_salterom;



	return 0;
}