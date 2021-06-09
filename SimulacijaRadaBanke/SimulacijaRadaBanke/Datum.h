#pragma once

#include <iostream>
#include <list>

class Datum {

private:

    int dan;
    int mesec;
    int godina;

public:

    Datum();
    Datum(int dan_, int mesec_, int godina_);
    Datum(const Datum& datum);

    int getDan() const;
    int getMesec()const;
    int getGodina()const;

    void setDan(int dan_);
    void setMesec(int mesec_);
    void setGodina(int godina_);
    
    friend std::ostream& operator<<(std::ostream& os, const Datum& datum);
};

extern Datum datum;
