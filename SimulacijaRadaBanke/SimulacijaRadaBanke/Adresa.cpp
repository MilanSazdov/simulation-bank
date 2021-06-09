#include <iostream>
#include <list>
#include "Adresa.h"

Adresa::Adresa() {

	Ulica = "Banovic Strahinja";
	broj = 5;
	Drzava = "Srbija";
	Mesto = "Novi Sad";
}

Adresa::Adresa(std::string ulica, int broj_, std::string drzava, std::string mesto) {
	
	Ulica = ulica;
	broj = broj_;
	Drzava = drzava;
	Mesto = mesto;
}

Adresa::Adresa(const Adresa& adresa) {
	
	Ulica = adresa.Ulica;
	broj = adresa.broj;
	Drzava = adresa.Drzava;
	Mesto = adresa.Mesto;
}

std::string Adresa::getUlica()const {
	return Ulica;
}

int Adresa::getBroj()const {
	return broj;
}

std::string Adresa::getDrzava() const {
	return Drzava;
}

std::string Adresa::getMesto()const {
	return Mesto;
}

void Adresa::setUlica(std::string ulica) {
	
	Ulica = ulica;
}

void Adresa::setBroj(int broj_) {
	broj = broj_;
}

void Adresa::setDrzava(std::string drzava) {

	Drzava = drzava;
}

void Adresa::setMesto(std::string mesto) {

	Mesto = mesto;
}

void Adresa::UnesiAdresu() {

	std::string ulica;
	std::string mesto;
	std::string drzava;
	int broj_ul;

	std::cout << "Unesite naziv ulice : " << std::endl;
	fflush(stdin);
	std::cin >> ulica;
	fflush(stdin);
	do {
		std::cout << "Unesite broj ulice : " << std::endl;
		std::cin >> broj_ul;
		if (broj_ul <= 0) {
			std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
		}

	} while (broj_ul <= 0);
	std::cout << "Unesite mesto : " << std::endl;
	std::cin >> mesto;
	fflush(stdin);
	std::cout << "Unestie drzavu : " << std::endl;
	fflush(stdin);
	std::cin >> drzava;
	fflush(stdin);

	Ulica = ulica;
	broj = broj_ul;
	Mesto = mesto;
	Drzava = drzava;

}

std::ostream& operator<<(std::ostream& os, const Adresa& adresa) {

	os << "*** ADRESA ***" << std::endl;
	os << "Ulica je : " << adresa.Ulica << std::endl;
	os << "Broj ulice je : " << adresa.broj << std::endl;
	os << "Drzava je : " << adresa.Drzava << std::endl;
	os << "Mesto je : " << adresa.Mesto << std::endl;
	return os;
}

bool operator==(const Adresa& adresa1, const Adresa& adresa2) {

	if (adresa1.broj != adresa2.broj) {
		return false;
	}

	if (adresa1.Ulica != adresa2.Ulica) {
		return false;
	}

	if (adresa1.Drzava != adresa2.Drzava) {
		return false;
	}

	if (adresa1.Mesto != adresa2.Mesto) {
		return false;
	}

	return true;
}