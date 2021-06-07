#include "Datum.h"
#include <iostream>
#include <list>

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
    {
        os << "Dan je : " << datum.dan << std::endl;
        os << "Mesec je : " << datum.mesec << std::endl;
        os << "Godina je : " << datum.godina << std::endl;

        return os;
    }
}