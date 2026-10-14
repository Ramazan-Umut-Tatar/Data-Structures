/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#include "BagliListe.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

    Liste *liste=new Liste;
    liste->AgacOku();
   
     liste->ListeYaz();
     liste->Ok();

    delete liste;
return 0;
}