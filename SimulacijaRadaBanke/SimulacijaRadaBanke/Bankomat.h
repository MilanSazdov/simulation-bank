#pragma once
#include <iostream>
#include <list>
#include "Racun.h"
#include "Datum.h"
#include "Adresa.h"
#include "Kartice.h"
#include "Kurs.h"

class Bankomat{

private:

	bool ispravan;
	DebitnaKartica* debitna_kartica;
	KreditnaKartica* kreditna_kartica;
	double pare_u_bankomatu;
	double kamata;

	
public:

	Bankomat();
	Bankomat(bool ispravan_, DebitnaKartica* debitna_kartica_, KreditnaKartica* kreditna_kartica_, double pare_u_bankomatu_, double kamata_);
	Bankomat(const Bankomat& bankomat);

	bool getIspravan()const;
	DebitnaKartica* getDebitnaKartica()const;
	KreditnaKartica* getKreditnaKartica()const;
	double getPare_U_Bankomatu()const;
	double getKamata()const;

	void setIspravan(bool ispravan_);
	void setDebitnaKartica(DebitnaKartica* kartica);
	void setKreditnaKartica(KreditnaKartica* kartica);
	void setPare_U_Bankomatu(double pare_u_bankomatu_);
	void setKamata(double kamata_);

	void DodajPareUBankomat();
	void PodigniPareSaBankomata(DebitnaKartica* kartica, double* kes);
	void PodigniPareSaBankomata(KreditnaKartica* kartica, double* kes);

	friend std::ostream& operator<<(std::ostream& os, const Bankomat& bankomat) {

		os << "*** BANKOMAT ***" << std::endl;
		os << "Ispravan : ";
		if (bankomat.ispravan) {
			os << "DA" << std::endl;
		}
		else
		{
			os << "NE" << std::endl;
		}

		os << "Debitna kartica : " << std::endl;
		os << (const DebitnaKartica&)bankomat << std::endl;
		os << "Kreditna kartica : " << std::endl;
		os << (const KreditnaKartica&)bankomat << std::endl;
		os << "Pare u bankomatu : " << bankomat.pare_u_bankomatu << std::endl;
		os << "Kamata : " << bankomat.kamata << std::endl;

		return os;
	}

};