#include "Datum.h"
#include <iostream>
#include <list>

Datum::Datum() {

    dan = 1;
    mesec = 1;
    godina = 2021;
}

Datum::Datum(int dan_, int mesec_, int godina_) {

    dan = dan_;
    mesec = mesec_;
    godina = godina_;
}

Datum::Datum(const Datum& datum) {

    dan = datum.dan;
    mesec = datum.mesec;
    godina = datum.godina;
}

int Datum::getDan() const {
    return dan;
}

int Datum::getMesec()const {
    return mesec;
}

int Datum::getGodina()const {
    return godina;
}

void Datum::setDan(int dan_) {
    dan = dan_;
}

void Datum::setMesec(int mesec_) {
    mesec = mesec_;
}

void Datum::setGodina(int godina_) {
    godina = godina_;
}

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
    {
        os << "Dan je : " << datum.dan << std::endl;
        os << "Mesec je : " << datum.mesec << std::endl;
        os << "Godina je : " << datum.godina << std::endl;

        return os;
    }
}

Datum datum;