#pragma once
#include <iostream>
#include <list>

class Kurs {

private:

    //KUPOVNE CENE ISPOD
    double dolar; // 0.85
    double franak; // 0.93
    double marka; // 0.54
    double kuna;  // 0.15
    double leji;  // 0.22
    double rsd;   // 0.0090
    //PRODAJNE CENE ISPOD
    double dolar_prodajna; // 0.82
    double franak_prodajna; // 0.91
    double marka_prodajna; // 0.51
    double kuna_prodajna; // 0.13
    double leji_prodajna; // 0.20
    double rsd_prodajna; // 0.0085

public:

    Kurs();
    Kurs(double dolar_, double franak_, double marka_, double kuna_, double leji_, double rsd_, double dolar_p, double franak_p, double marka_p, double kuna_p, double leji_p, double rsd_p);
    Kurs(Kurs& kurs);
    double getDolar() const;
    double getFranak()const;
    double getMarka()const;
    double getKuna()const;
    double getLeji()const;
    double getRSD()const;
    double getDolarProdajna()const;
    double getFranakProdajna()const;
    double getMarkaProdajna()const;
    double getKunaProdajna()const;
    double getLejiProdajna()const;
    double getRSDPRODAJNA()const;
    void setDolar(double dolar_);
    void setFranak(double franak_);
    void setMarka(double marka_);
    void setKuna(double kuna_);
    void setLeji(double leji_);
    void setRSD(double rsd_);
    void setDolarProdajna(double dolar_);
    void setFranakProdajna(double franak_);
    void setMarkaProdajna(double marka_);
    void setKunaProdajna(double kuna_);
    void setLejiProdajna(double leji_);
    void setRSDPRODAJNA(double rsd_);
    void PromeniKurs();
    friend std::ostream& operator<<(std::ostream& os, const Kurs& kurs);
};
