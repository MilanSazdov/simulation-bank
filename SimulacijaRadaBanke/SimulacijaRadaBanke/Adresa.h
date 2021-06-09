#pragma once
#include <iostream>
#include <list>

class Adresa {

private:

    std::string Ulica;
    int broj;
    std::string Drzava;
    std::string Mesto;

public:

    Adresa();
    Adresa(std::string ulica, int broj_, std::string drzava, std::string mesto);
    Adresa(const Adresa& adresa);
    friend std::ostream& operator<<(std::ostream& os, const Adresa& adresa);

    std::string getUlica()const;
    int getBroj()const;
    std::string getDrzava()const;
    std::string getMesto()const;

    void setUlica(std::string ulica);
    void setBroj(int broj_);
    void setDrzava(std::string drzava);
    void setMesto(std::string mesto);
};