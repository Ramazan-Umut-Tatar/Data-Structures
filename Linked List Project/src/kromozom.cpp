/*       
* @file                 b241210906  
* @description          txt içinde verilen kromozomları carprazlar,mutasyona uğratır,ekrana yazdırır.
* @course               1. Öğretim C grubu
* @assignment           1. ödev
* @date                 27.11.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#include "kromozom.hpp"
Kromozom::Kromozom(){

    this->ilkGen = 0;
    this->sonGen = 0;
    this->sonraki = 0;
    this->onceki = 0;

}

Kromozom::~Kromozom(){

     Gen* gec = ilkGen;
    while (gec != 0) {
        Gen* sil = gec;
        gec = gec->sonraki;
        delete sil; // Dinamik bellek serbest bırakılır
    }
    ilkGen = sonGen = nullptr;

}

void Kromozom::GenEkle(string bilgi){

    Gen* yeniGen = new Gen(bilgi);

    if (ilkGen == 0){
        
        ilkGen = yeniGen;
        sonGen = yeniGen;

    }
    else{

        sonGen->sonraki = yeniGen;
        yeniGen->onceki = sonGen;
        sonGen = yeniGen;

    }
    GenSayisi++;

}

void Kromozom::GenleriYazdir(){

    Gen* gec = ilkGen;

    while (gec != 0) {

        cout << gec->bilgi << " ";
        gec = gec->sonraki;

    }
    cout << endl;

}

string Kromozom::GenGetir(int indeks){

    Gen* gec = ilkGen;
    for (int i = 0; i < indeks; i++)
    {
        gec = gec->sonraki;
    }
    return gec->bilgi;
    
}