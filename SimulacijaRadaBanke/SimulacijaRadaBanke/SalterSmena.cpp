#include <iostream>
#include <list>
#include "SalterSmena.h"

int RadnikZaSalterom::ID = -1;

RadnikZaSalterom::RadnikZaSalterom(const RadnikZaSalterom& radnik_za_salterom) {

	na_pauzi = radnik_za_salterom.na_pauzi;
	id = radnik_za_salterom.id;

}

RadnikZaSalterom::RadnikZaSalterom() {
	
	ID++;
	na_pauzi = false;
	id = ID;
}

RadnikZaSalterom::RadnikZaSalterom(double mesecna_plata_, Datum datum_rodjenja_, Adresa adresa_stanovanja_, std::string ime_, std::string prezime_, int broj_godina_,bool na_pauzi_) {

	mesecna_plata = mesecna_plata_;
	datum_rodjenja = Datum(datum_rodjenja_);
	adresa_stanovanja = Adresa(adresa_stanovanja_);
	ime = ime_;
	prezime = prezime_;
	broj_godina = broj_godina_;
	ID++;
	na_pauzi = na_pauzi_;
	id = ID;
}

bool RadnikZaSalterom::getNaPauzi()const {

	return na_pauzi;
}
int RadnikZaSalterom::getId()const {
		
	return id;
}

void RadnikZaSalterom::setNaPauzi(bool na_pauzi_) {
	
	na_pauzi = na_pauzi_;
}

void RadnikZaSalterom::setId(int id_) {

	id = id_;
}

std::ostream& operator<<(std::ostream& os, const RadnikZaSalterom& radnik_za_salterom) {

	os << (const Osoba&)radnik_za_salterom;
	os << "Na pauzi : " << std::endl;
	if (radnik_za_salterom.na_pauzi) {
		os << "DA" << std::endl;
	}
	else
	{
		os << "NE" << std::endl;
	}

	os << "Id : " << radnik_za_salterom.id << std::endl;

	return os;
}

Salter::Salter() {

	radnik_za_salterom = RadnikZaSalterom();
	broj_saltera = 1;
	zauzet = false;
}

Salter::Salter(RadnikZaSalterom radnik_za_salterom_, int broj_saltera_, bool zauzet_) {

	radnik_za_salterom = RadnikZaSalterom(radnik_za_salterom);
	broj_saltera = broj_saltera_;
	zauzet = zauzet_;
}

Salter::Salter(const Salter& salter) {

	radnik_za_salterom = RadnikZaSalterom(salter.radnik_za_salterom);
	broj_saltera = salter.broj_saltera;
	zauzet = salter.zauzet;
}

RadnikZaSalterom Salter::getRadnikZaSalterom() {
	return radnik_za_salterom;
}

int Salter::getBrojSaltera()const {
	return broj_saltera;
}

bool Salter::getZauzet()const {
	return zauzet;
}

void Salter::setRadnikZaSalterom(RadnikZaSalterom radnik_za_salterom_) {
	radnik_za_salterom = radnik_za_salterom_;
}

void Salter::setBrojSaltera(int broj_saltera_) {
	broj_saltera = broj_saltera_;
}

void Salter::setZauzet(bool zauzet_) {
	zauzet = zauzet_;
}


Smena::Smena() {

	vreme_pocetka = "7:00h";
	vreme_pocetka_vikendom = "10:00h";
	vreme_kraja = "17:00h";
	vreme_kraja_vikendom = "15:00h";
}

Smena::Smena(std::list<RadnikZaSalterom> lista_radnika_, std::string vreme_pocetka_, std::string vreme_pocetka_vikendom_, std::string vreme_kraja_, std::string vreme_kraja_vikendom_) {

	lista_radnika = lista_radnika_;
	vreme_pocetka = vreme_pocetka_;
	vreme_pocetka_vikendom = vreme_pocetka_vikendom_;
	vreme_kraja = vreme_kraja_;
	vreme_kraja_vikendom = vreme_kraja_vikendom_;
}

Smena::Smena(const Smena& smena) {

	lista_radnika = smena.lista_radnika;
	vreme_pocetka = smena.vreme_pocetka;
	vreme_pocetka_vikendom = smena.vreme_pocetka_vikendom;
	vreme_kraja = smena.vreme_kraja;
	vreme_kraja_vikendom = smena.vreme_kraja_vikendom;
}

std::list<RadnikZaSalterom> Smena::getListaRadnika()const {

	return lista_radnika;
}

std::string Smena::getVremePocetka()const {

	return vreme_pocetka;
}

std::string Smena::getVremePocetkaVikendom()const {
	return vreme_pocetka_vikendom;
}

std::string Smena::getVremeKraja()const {
	return vreme_kraja;
}

std::string Smena::getVremeKrajaVikendom()const {
	return vreme_kraja_vikendom;
}

void Smena::setListaRadnika(std::list<RadnikZaSalterom> lista_radnika_) {
	lista_radnika = lista_radnika_;
}
void Smena::setVremePocetka(std::string vreme_pocetka_) {
	vreme_pocetka = vreme_pocetka_;
}
void Smena::setVremePocetkaVikendom(std::string vreme_pocetka_vikendom_) {
	vreme_pocetka_vikendom = vreme_pocetka_vikendom_;
}
void Smena::setVremeKraja(std::string vreme_kraja_) {
	vreme_kraja = vreme_kraja_;
}
void Smena::setVremeKrajaVikendom(std::string vreme_kraja_vikendom_) {
	vreme_kraja_vikendom = vreme_kraja_vikendom_;
}