/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP
#include "Agac.hpp"

class Liste{
public:
   Agac* aktif=0;
    int gozlemci=0;
    Agac* ilk;
    int agacSayisi=0;
    Agac* agacAdres(int index);
    Agac* erisim;
    void cizgiYaz();
     void satirCiz();
     void degerYaz1(int deger);
     void degerYaz2(int deger);
     void isaretYaz(int);
    void degerYaz3(int deger);
    void ListeYaz();
    void Ok();
     void AgacOku();
     void dugumSil(int index);
     void agaciCiz(int index);
   
   void AgacEkle(Agac*);
  
    
   Liste();
   ~Liste();

};


#endif 