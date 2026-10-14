
/*       
* @file                 b241210906  
* @description          txt içinde verilen kromozomları carprazlar,mutasyona uğratır,ekrana yazdırır.
* @course               1. Öğretim C grubu
* @assignment           1. ödev
* @date                 27.11.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#include "gen.hpp"
#include <iostream>

Gen::Gen(string bilgi){

    this->bilgi = bilgi;
    this->onceki = 0;
    this->sonraki = 0;

}

Gen::~Gen(){}