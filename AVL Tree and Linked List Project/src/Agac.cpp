/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#include "Agac.hpp"
#include "Dugum.hpp"

#include <iostream>
using namespace std;

Agac::Agac() {

    kok = 0; 
    sonraki = 0;

}

bool Agac::varmi(int veri) {
    return varmi(veri, kok);
}

bool Agac::varmi(int aranan, Dugum* aktif) {
    if (aktif == nullptr) {
        return false;
    }
    if (aktif->veri < aranan) {
        return varmi(aranan, aktif->sag);
    } else if (aktif->veri > aranan) {
        return varmi(aranan, aktif->sol);
    } else {
        return true;
    }
}

void Agac::ekle(int veri) {
    if (kok == nullptr) {
        kok = new Dugum(veri);
    } else {
        ekle(veri, kok);
    }
}

void Agac::ekle(int veri, Dugum* aktifDugum) {
    if (veri < aktifDugum->veri) {
        if (aktifDugum->sol == nullptr) {
            aktifDugum->sol = new Dugum(veri);

        } else {
            ekle(veri, aktifDugum->sol);
        }
    } else if (veri > aktifDugum->veri) {
        if (aktifDugum->sag == nullptr) {
            aktifDugum->sag = new Dugum(veri);
        } else {
            ekle(veri, aktifDugum->sag);
        }
    }
}

int Agac::enBuyuk(Dugum* aktif) {
    if (aktif->sag != nullptr) {
        return enBuyuk(aktif->sag);
    }
    return aktif->veri;
}

void Agac::sil(int aranan, Dugum* &aktif) {
    if (aktif == nullptr) return;

    if (aranan < aktif->veri) {
        sil(aranan, aktif->sol);
    } else if (aranan > aktif->veri) {
        sil(aranan, aktif->sag);
    } else {
        if (aktif->sol != nullptr && aktif->sag != nullptr) {
            aktif->veri = enBuyuk(aktif->sol);
            sil(aktif->veri, aktif->sol);
        } else {
            Dugum* silinecek = aktif;
            aktif = (aktif->sol != nullptr) ? aktif->sol : aktif->sag;
            delete silinecek;
        }
    }
}

void Agac::sil(int veri) {
    sil(veri, kok);
}

   void Agac::yokEt(Dugum* dugum) {
    if (dugum == nullptr) return;
    yokEt(dugum->sol);
    yokEt(dugum->sag);
    delete dugum;
}

Agac::~Agac() {
    yokEt(kok);
    
}


//----------------------------------------------------------------------------

int Agac::solVeSagTopla(Dugum* dugum) {
    int toplam=0;
    
    
    if (dugum->sol) {
        toplam =toplam+solVeSagTopla(dugum->sol)+dugum->sol->veri*2;
    }

    
    if (dugum->sag) {
        toplam +=solVeSagTopla(dugum->sag)+dugum->sag->veri;
    }

    return toplam;
}

int Agac::hesapla() {
    return solVeSagTopla(kok)+kok->veri;
}


int Agac::yukseklik(Dugum* aktifDugum){
        if(aktifDugum)
         return 1+max(yukseklik(aktifDugum->sol),yukseklik(aktifDugum->sag));

return -1;
}

void Agac::aynaYap() {
    if (kok == nullptr) return;
    aynaYap(kok);
}

void Agac::aynaYap(Dugum* dugum) {
    if (dugum == nullptr) return;

   
    Dugum* temp = dugum->sol;
    dugum->sol = dugum->sag;
    dugum->sag = temp;

  
    aynaYap(dugum->sol);
    aynaYap(dugum->sag);
}
