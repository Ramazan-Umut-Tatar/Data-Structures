/*       
* @file                 b241210906  
* @description          txt içindeki ağaçların adreslerini ve değerlerini yazdırır;siler,çizer,aynalar.
* @course               1. Öğretim C grubu
* @assignment           2. ödev
* @date                 25.12.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#include "BagliListe.hpp"
#include "Kuyruk.hpp"
#include "Agac.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int index=0;
int sayfa=0;
int baslangic=0;
int bitis=0;  


Liste::Liste(){

    ilk=0;

}

void Liste::AgacEkle(Agac* agac){

    if (ilk == 0)
    {
        ilk = agac;
    }
    else
    {
        Agac* gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = agac;
        
        
    }
    


}


void Liste::AgacOku(){


ifstream dosya("src/agaclar.txt");
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        
        cout<<agacSayisi<< ".Okunan Satir: " << satir << endl;
         
        
        Agac* yeniAgac = new Agac();

       
        for (char SatirdakiAgac : satir) {
            yeniAgac->ekle(SatirdakiAgac);
        } 
           AgacEkle(yeniAgac);
       
        agacSayisi++;
    }
  
    dosya.close();
}


Liste::~Liste() {
    Agac* gec = ilk;
    while (gec != nullptr) {
        Agac* silinecek = gec;
        gec = gec->sonraki; 
        delete silinecek; 
    }
    ilk = nullptr;
    
}





 Agac* Liste::agacAdres(int index){
  
  Agac* gec;
  gec=ilk;
     
     for(int i=0;i<index;i++){
      
     gec=gec->sonraki;

     }
     return gec;
}





int bosluk=5;
void Liste::cizgiYaz(){
   
    for(int i=0;i<bosluk;i++)
         cout<<" ";
         cout<<"********";

    
}

void Liste::satirCiz(){

    for(int i=baslangic;i<bitis;i++){
        cizgiYaz();
    }
}

void Liste::degerYaz1(int deger){

     for(int i=0;i<bosluk;i++)
          cout<<" ";
       cout<<"*";

    Agac* son4 = agacAdres(deger);
    uintptr_t adresInt = reinterpret_cast<uintptr_t>(son4); 
    uintptr_t son4Basamak = adresInt % 10000;              

       cout << setw(6) << son4Basamak;      
       cout<<"*";
     
}

void Liste::degerYaz2(int deger) {
    for (int i = 0; i < bosluk; i++)
        cout << " ";
    cout << "*";

    Agac* agac = agacAdres(deger); 
    int toplam = agac->hesapla(); 
    cout << setw(6) << toplam; 
    cout << "*";
}


void Liste::degerYaz3(int deger){

     for(int i=0;i<bosluk;i++)
          cout<<" ";
       cout<<"*";

    Agac* son4 = agacAdres(deger+1);
    
    uintptr_t adresInt = reinterpret_cast<uintptr_t>(son4); 
    uintptr_t son4Basamak = adresInt % 10000;              

       cout << setw(6) << son4Basamak;      
       cout<<"*";
     
}

void Liste::ListeYaz(){
    if (ilk == nullptr) return ;
  int maxSayfaSayisi=0;

  if(agacSayisi%10 == 0)
{
    maxSayfaSayisi=agacSayisi/10-1;
   
}   
  else 
{
    maxSayfaSayisi=(agacSayisi/10);
    
}
gozlemci=index%10;
    if(index%10==0 && sayfa!=index/10){
            sayfa++;                        
            gozlemci=index%10;
}
    if(sayfa==maxSayfaSayisi){ 
            baslangic=sayfa*10; 
            bitis=baslangic+((agacSayisi)-baslangic);
            
}
    else{
            baslangic=sayfa*10;   
            bitis=baslangic+10;     
}

    if(index%10==9 && sayfa!=index/10){
            sayfa--;
            gozlemci=index%10;
            
            baslangic=sayfa*10;   
            bitis=baslangic+10;
 }
    if(index<baslangic && index>bitis)
        gozlemci=index;

    satirCiz();
    cout<<endl; 

for(int i=baslangic;i<bitis;i++)
    degerYaz1(i);
    cout<<endl;           
    satirCiz();
    cout<<endl;

for(int i=baslangic;i<bitis;i++)
     degerYaz2(i);
     cout<<endl;         
     satirCiz();      
     cout<<endl;

for(int i=baslangic;i<bitis;i++)
     degerYaz3(i);     
     cout<<endl;
     satirCiz();    


}

void Liste::isaretYaz(int gozlemci){
int boslukMiktari=5;

    if(agacSayisi==0) return;
 
    if(gozlemci== 0) {
        for(int i=0;i<boslukMiktari;i++)
               cout<<" ";
            cout<<"^^^^^^^^"<<endl;
        for(int i=0;i<boslukMiktari;i++)
               cout<<" ";
            cout<<"||||||||";
    }

   else if(gozlemci!=0)
   {
        for(int i=0;i<gozlemci;i++)
        {
            for(int i=0;i<boslukMiktari;i++)
                cout<<" ";
            cout<<"        ";
        } 
         for(int i=0;i<boslukMiktari;i++)
               cout<<" ";
               cout<<"^^^^^^^^"<<endl;

     for(int i=0;i<gozlemci;i++)
        {
            for(int i=0;i<boslukMiktari;i++)
                cout<<" ";
            cout<<"        ";
        }    

        for(int i=0;i<boslukMiktari;i++)
            cout<<" ";
            cout<<"||||||||"; 
}
     
}



void Liste::Ok(){

while(true)
{

  if(index==-1)
    index=0;

  if(index==agacSayisi){
        index=agacSayisi-1;        
}

   system("cls");
   ListeYaz();
   cout<<endl;

   isaretYaz(gozlemci);
   cout<<endl<<endl<<endl;

 agaciCiz(index);

   cout<<"Secim...: ";
   string secim;
   getline(cin, secim);


 

   if(secim=="x")
        break;
    else if(secim== "a")
        index--;
   else if(secim=="d")
       index++;
   else if(secim == "s")
    {
        dugumSil(index);
    }
   else if (secim == "w") {
            if(agacSayisi>=1){
            Agac* agac = agacAdres(index);
            agac->aynaYap();
        }

        }
    else {}
}
}

void Liste::dugumSil(int index) {
    if (ilk == nullptr) { 
        cout << "Liste zaten bos, silme islemi yapilamaz!" << endl;
        return;
    }

    if (index < 0 || index >= agacSayisi) { 
        return;
    }

    Agac* gec = ilk;
    Agac* silinecek = nullptr;

    if (index == 0) { 
        silinecek = ilk;
        ilk = ilk->sonraki;
        delete silinecek;
        agacSayisi--;
        return;
    }

    for (int i = 0; i < index - 1; i++) { 
        gec = gec->sonraki;
    }

    silinecek = gec->sonraki; 
    gec->sonraki = silinecek->sonraki; 

    delete silinecek; 
    agacSayisi--;

   
    if (agacSayisi == 0) {
        ilk = nullptr;
    }
}
void Liste::agaciCiz(int index) {
    cout<<endl<<endl;
    if (ilk == nullptr || index < 0 || index >= agacSayisi) {
     
        return;
    }

    Agac* secilenAgac = agacAdres(index);
    if (secilenAgac->kok == nullptr) {
        cout << "Secilen agac bos!" << endl;
        return;
    }

    Kuyruk kuyruk;
    kuyruk.ekle(secilenAgac->kok);

    int seviye = 0;
    int yukseklik = secilenAgac->yukseklik(secilenAgac->kok);
    int kat = 0;

    
    while (!kuyruk.bosMu() && seviye <= yukseklik) {
        Dugum* siradaki = kuyruk.cikar();
      
        if (kat == 0) {
            cout<<endl;
            for (int i = 0; i < (1 << (yukseklik - seviye)); i++) cout << " ";
        }

        if (siradaki) {
            char donusum = static_cast<char>(siradaki->veri);
            cout << setw(2) << donusum;
            kuyruk.ekle(siradaki->sol);
            kuyruk.ekle(siradaki->sag);
        } else {
            cout << setw(2) << "  ";
            kuyruk.ekle(nullptr);
            kuyruk.ekle(nullptr);
        }

        for (int i = 0; i < (1 << (yukseklik - seviye + 1)); i++) cout << " ";

        kat++;
        if (kat == (1 << seviye)) {
            cout << endl;
            seviye++;
            kat = 0;
        }
    }
}


