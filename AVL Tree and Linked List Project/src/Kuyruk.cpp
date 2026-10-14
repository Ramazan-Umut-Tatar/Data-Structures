/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#include "Kuyruk.hpp"


Kuyruk::DugumNode::DugumNode(Dugum* d) : dugum(d), sonraki(nullptr) {}


Kuyruk::Kuyruk() : bas(nullptr), son(nullptr) {}


Kuyruk::~Kuyruk() {
    while (!bosMu()) {
        cikar();
    }
}


void Kuyruk::ekle(Dugum* yeniDugum) {
    DugumNode* yeni = new DugumNode(yeniDugum);
    if (son == nullptr) {
        bas = son = yeni;
    } else {
        son->sonraki = yeni;
        son = yeni;
    }
}


Dugum* Kuyruk::cikar() {
    if (bas == nullptr) return nullptr;
    DugumNode* silinecek = bas;
    Dugum* veri = silinecek->dugum;
    bas = bas->sonraki;
    if (bas == nullptr) {
        son = nullptr;
    }
    delete silinecek;
    return veri;
}


bool Kuyruk::bosMu() const {
    return bas == nullptr;
}
