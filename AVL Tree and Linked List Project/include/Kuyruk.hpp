/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include "Dugum.hpp"

class Kuyruk {
private:
    struct DugumNode {
        Dugum* dugum;
        DugumNode* sonraki;
        DugumNode(Dugum* d);
    };

    DugumNode* bas;
    DugumNode* son;

public:
    Kuyruk();
    ~Kuyruk();

    void ekle(Dugum* yeniDugum);
    Dugum* cikar();
    bool bosMu() const;
};

#endif
