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

std::ostream& operator<<(std::ostream& os, const Adresa& adresa) {

	os << "*** ADRESA ***" << std::endl;
	os << "Ulica je : " << adresa.Ulica << std::endl;
	os << "Broj ulice je : " << adresa.broj << std::endl;
	os << "Drzava je : " << adresa.Drzava << std::endl;
	os << "Mesto je : " << adresa.Mesto << std::endl;
	return os;
}