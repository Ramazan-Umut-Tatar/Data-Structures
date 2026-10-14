/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#ifndef AGAC_HPP
#define AGAC_HPP
#include "Dugum.hpp"

class Agac {
public:

    int toplam = 0;
    int solToplam = 0;
    int sagToplam = 0;
    bool solTaraf = false;


    Agac* sonraki;

    Agac();
    ~Agac();

    bool varmi(int veri);
    void aynaYap(); // Ağacı aynalamayı başlatır.
    void aynaYap(Dugum* dugum); // Belirli bir düğümden itibaren ağacı aynalar.

    void ekle(int veri);
    void ekle(int veri,Dugum* aktifDugum);  

    void sil(int veri);
    void sil(int veri,Dugum* &aktif);
    int yukseklik(Dugum* aktifDugum);
    int enBuyuk(Dugum* aktif);

int hesapla();
int solVeSagTopla(Dugum* dugum);




    void yokEt(Dugum* dugum);

    Dugum* kok;
bool varmi(int veri,Dugum* aktif);
private:
  
};

#endif