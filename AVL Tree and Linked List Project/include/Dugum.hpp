/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 
#ifndef DUGUM_HPP
#define DUGUM_HPP



class Dugum {
public:
	Dugum(int veri);
	int veri;
	Dugum* sol;
	Dugum* sag;


};


#endif 