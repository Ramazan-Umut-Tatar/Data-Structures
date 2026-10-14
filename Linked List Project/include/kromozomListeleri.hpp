#ifndef KROMOZOMLISTELERI_HPP
#define KROMOZOMLISTELERI_HPP
#include "kromozom.hpp"
#include <iostream>

class KromozomListeleri{    

public:

    int kromozomSayisi;
    bool isThere = 0;

    Kromozom* ilkKromozom;
    Kromozom* sonKromozom;

    KromozomListeleri();
    ~KromozomListeleri();

    void KromozomEkle(Kromozom*);
    void KromozomOku(string);
    void KromozomlariYazdir();
    void KromozomGetir(int);

    void OtomatikIslemler();
    void Caprazla(int, int);
    void Mutasyon(int, int);
    void EkranaYaz();
    void Karar();
    void dnayaz();

};

#endif