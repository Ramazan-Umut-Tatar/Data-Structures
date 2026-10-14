#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "gen.hpp"

class Kromozom{

public:

    int GenSayisi = 0;

    Gen* ilkGen;
    Gen* sonGen;
    Kromozom* sonraki;
    Kromozom* onceki;

    Kromozom();
    ~Kromozom();

    void GenEkle(string);
    void GenleriYazdir();
    string GenGetir(int);

};

#endif