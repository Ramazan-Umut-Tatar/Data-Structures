/*       
* @file                 b241210906  
* @description          txt içinde verilen kromozomları carprazlar,mutasyona uğratır,ekrana yazdırır.
* @course               1. Öğretim C grubu
* @assignment           1. ödev
* @date                 27.11.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#include "kromozomlisteleri.hpp"
#include <iostream>

using namespace std;



int main() {
    KromozomListeleri* kromozomListesi = new KromozomListeleri; 
    kromozomListesi->KromozomOku("src/dna.txt");
    kromozomListesi->Karar();
    
    delete kromozomListesi; 
    return 0;
}