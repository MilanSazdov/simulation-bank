#pragma once

#include <iostream>
#include <list>

class Datum {

    int dan;
    int mesec;
    int godina;

public:

    
    friend std::ostream& operator<<(std::ostream& os, const Datum& datum);
};