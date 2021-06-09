#include <iostream>
#include <list>
#include "Bankomat.h"


Bankomat::Bankomat() {
	
	ispravan = true;
	debitna_kartica = NULL;
	kreditna_kartica = NULL;
	pare_u_bankomatu = 200000;
	kamata = 0.05;
}

Bankomat::Bankomat(bool ispravan_, DebitnaKartica* debitna_kartica_, KreditnaKartica* kreditna_kartica_, double pare_u_bankomatu_, double kamata_) {

	ispravan = ispravan_;
	debitna_kartica = debitna_kartica_;
	kreditna_kartica = kreditna_kartica_;
	pare_u_bankomatu = pare_u_bankomatu_;
	kamata = kamata_;
}

Bankomat::Bankomat(const Bankomat& bankomat) {

	ispravan = bankomat.ispravan;
	debitna_kartica = bankomat.debitna_kartica;
	kreditna_kartica = bankomat.kreditna_kartica;
	pare_u_bankomatu = bankomat.pare_u_bankomatu;
	kamata = bankomat.kamata;
}

bool Bankomat::getIspravan()const {
	return ispravan;
}
DebitnaKartica* Bankomat::getDebitnaKartica()const {
	return debitna_kartica;
}

KreditnaKartica* Bankomat::getKreditnaKartica()const {
	return kreditna_kartica;
}

double Bankomat::getPare_U_Bankomatu()const {
	return pare_u_bankomatu;
}
double Bankomat::getKamata()const {
	return kamata;
}

void Bankomat::setIspravan(bool ispravan_) {
	ispravan = ispravan_;
}
void Bankomat::setDebitnaKartica(DebitnaKartica* kartica) {

	debitna_kartica = kartica;
}

void Bankomat::setKreditnaKartica(KreditnaKartica* kartica) {
	kreditna_kartica = kartica;
}

void Bankomat::setPare_U_Bankomatu(double pare_u_bankomatu_) {
	pare_u_bankomatu = pare_u_bankomatu_;
}
void Bankomat::setKamata(double kamata_) {
	kamata = kamata_;
}

void Bankomat::DodajPareUBankomat() {
		
	double pare;

	do {

		std::cout << "Koliko para hocete da dodate u bankomat : " << std::endl;
		std::cin >> pare;
		if (pare <= 0) {
			std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
		}

	} while (pare <= 0);

	pare_u_bankomatu += pare;
}

void Bankomat::PodigniPareSaBankomata(DebitnaKartica* kartica, double* kes) {

	double novac;
	int pin;

	//Ako uzimam neki broj n onda sa racuna se skida n * (1 + kamata) 

	do {
		std::cout << "Unesite koliko para hocete da uzmete sa bankomata : " << std::endl;
		std::cin >> novac;
		if (novac < 0) {
			std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
			continue;
		}
		break;

	} while (5);

	int i = 3;
	while (i--)
	{
		std::cout << "Unesite PIN(CV vase kartice) : " << std::endl;
		std::cin >> pin;
		if (kartica->getCV() != pin) {
			std::cout << "Netacan PIN, broj preostalih pokusaja : " << i-1 << std::endl;
			continue;
		}

		break;
	}

	if (i == 0) {

		std::cout << "Neuspesno skidanje " << std::endl;
		return;
	}

	if (kartica->getRacun()->getPrekoracenje()) {

		if ((novac * (1 + kamata)) > kartica->getRacun()->getStanjeNaRacunuRSD() + kartica->getRacun()->getMaxPrekoracenje()) {
			std::cout << "Neuspesno skidanje " << std::endl;
			return;
		}

	}

	else
	{
		if ((novac * (1 + kamata)) > kartica->getRacun()->getStanjeNaRacunuRSD()) {
			std::cout << "Neuspesno skidanje " << std::endl;
			return;
		}
	}
	
	kartica->getRacun()->setStanjeNaRacunuRSD(kartica->getRacun()->getStanjeNaRacunuRSD() - (novac * (1 + kamata)));
	*kes += novac;
	pare_u_bankomatu -= novac;

}

void Bankomat::PodigniPareSaBankomata(KreditnaKartica* kartica, double* kes) {

	double novac;
	int pin;

	//Ako uzimam neki broj n onda sa racuna se skida n * (1 + kamata) 
	// Ovde se mora paziti i na kurs jer pretvaram sve u dinare

	do {
		std::cout << "Unesite koliko para hocete da uzmete sa bankomata u EVRO: " << std::endl;
		std::cin >> novac;
		if (novac < 0) {
			std::cout << "Uneli ste neodgovarajuci broj !!!" << std::endl;
			continue;
		}
		break;

	} while (5);

	int i = 3;
	while (i--)
	{
		std::cout << "Unesite PIN(CV vase kartice) : " << std::endl;
		std::cin >> pin;
		if (kartica->getCV() != pin) {
			std::cout << "Netacan PIN, broj preostalih pokusaja : " << i - 1 << std::endl;
			continue;
		}

		break;
	}

	if (i == 0) {

		std::cout << "Neuspesno skidanje " << std::endl;
		return;
	}

	if (kartica->getRacunDevizni()->getPrekoracenje()) {

		if ((novac * (1 + kamata)) > kartica->getRacunDevizni()->getStanjeNaRacunuEVRO() + kartica->getRacunDevizni()->getMaxPrekoracenje()) {
			std::cout << "Neuspesno skidanje " << std::endl;
			return;
		}

	}

	else
	{
		if ((novac * (1 + kamata)) > kartica->getRacunDevizni()->getStanjeNaRacunuEVRO()) {
			std::cout << "Neuspesno skidanje " << std::endl;
			return;
		}
	}

	kartica->getRacunDevizni()->setStanjeNaRacunuEVRO(kartica->getRacunDevizni()->getStanjeNaRacunuEVRO() - (novac * (1 + kamata)));
	novac = novac / kurs.getRSD(); // Pretvaram evre u dinare
	*kes += novac; // u dinarima jer je kes u dinarima
	pare_u_bankomatu -= novac; // oduzima iz bankomata u dinarima

}
