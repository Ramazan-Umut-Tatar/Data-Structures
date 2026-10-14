/*       
* @file                 b241210906  
* @description          txt içinde verilen kromozomları carprazlar,mutasyona uğratır,ekrana yazdırır.
* @course               1. Öğretim C grubu
* @assignment           1. ödev
* @date                 27.11.2024
* @author               Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
*/ 

#include "kromozomListeleri.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

      using namespace std;

void KromozomListeleri::Karar(){
    

    cout << "Yapmak istediginiz islemi giriniz..." << endl;
    cout << "(1)Caprazlama" << endl; 
    cout << "(2)Mutasyon" << endl; 
    cout << "(3)Otomatik islemler" << endl; 
    cout << "(4)Ekrana yaz" << endl; 
    cout << "(5)Cikis" << endl;

    int secim = 0;
    cin >> secim; 

     if (secim == 1) {
        
        //KromozomlariYazdir();

        int secim1 = 0, secim2 = 0;
        cout << "secim1 gir: ";
        cin >> secim1;
        cout << "secim2 gir: ";
        cin >> secim2;


        Caprazla(secim1, secim2);
        dnayaz();
      
       // KromozomlariYazdir();
        cout << kromozomSayisi << endl;
        Karar();

    }
       else if (secim == 2) {
        
       // KromozomlariYazdir();
        
        int secim1 = 0, secim2 = 0;
        cout << "Kromozom gir: ";
        cin >> secim1;
        cout << "Gen gir: ";
        cin >> secim2;

   Kromozom* gec = ilkKromozom;
    int i = 0;
    for (i = 0; i < secim1; i++)
    {
        gec = gec->sonraki;
    }

        if(secim1>(kromozomSayisi-1) || secim1<0 || secim2<0 || secim2>=gec->GenSayisi){
        cout<<"Olmayan gen veya kromozom sayisi girdiniz.";
          return;
        }
    
        Mutasyon(secim1, secim2);
        dnayaz();
        
       // KromozomlariYazdir();
        cout << kromozomSayisi << endl;
        Karar();

    }
    else if (secim == 3) {
 
     OtomatikIslemler();

    }
    else if (secim == 4) {

        EkranaYaz();

    }
    else if (secim == 5) {

        exit(0);

    }
    else {

        cout << "Lütfen gecerli bir islem giriniz..." << endl;

    }

}


KromozomListeleri::KromozomListeleri(){

    ilkKromozom = 0;
    sonKromozom = 0;
    kromozomSayisi = 0;
    
}

KromozomListeleri::~KromozomListeleri() { //Yıkıcı fonksiyon
     Kromozom* gec = ilkKromozom;
    while (gec != 0) {
        Kromozom* sil = gec;
        gec = gec->sonraki;
        delete sil;  
    }
    ilkKromozom = sonKromozom = 0;
}

void KromozomListeleri::KromozomEkle(Kromozom* yeniKromozom){

    if (ilkKromozom == 0){

        ilkKromozom = yeniKromozom;
        sonKromozom = yeniKromozom;

    }
    else{
        
        Kromozom* gec = ilkKromozom;
        sonKromozom->sonraki = yeniKromozom;
        yeniKromozom->onceki = sonKromozom;
        sonKromozom = yeniKromozom;

    }
    kromozomSayisi++;

}

void KromozomListeleri::KromozomOku(string dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya) {
        cerr << "Dosya açilamadi: " << dosyaAdi << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        istringstream ss(satir);
        string yeniGen;

       
        Kromozom* yeniKromozom = new Kromozom(); //Yeni kromozomun oluşturma
        while (ss >> yeniGen) {
            yeniKromozom->GenEkle(yeniGen);  // Gen bilgisi ekleme 
        }

        
        KromozomEkle(yeniKromozom);
    }

    dosya.close();
}



void KromozomListeleri::KromozomlariYazdir() {

    Kromozom* gec = ilkKromozom;
    int indeks = 0;
    
    while (gec != 0) {
        cout << "Kromozom " << indeks++ << ": ";
        gec->GenleriYazdir();
        gec = gec->sonraki;
    }

}

void KromozomListeleri::KromozomGetir(int indeks){

    Kromozom* gec = ilkKromozom;
    int i = 0;
    for (i = 0; i < indeks; i++)
    {
        gec = gec->sonraki;
    }
    cout << i << "inci kromozom: ";
    gec->GenleriYazdir();
    cout << gec->GenSayisi << endl << endl;
}

void KromozomListeleri::Caprazla(int k1, int k2){

    Kromozom* gec1 = ilkKromozom;
    for (int i = 0; i < k1; i++)
    {
        gec1 = gec1->sonraki;
    }//ilk kromozoma erisildi

    Kromozom* gec2 = ilkKromozom;
    for (int i = 0; i < k2; i++)
    {
        gec2 = gec2->sonraki;
    }//ikinci kromozoma erisildi

    if (gec1->GenSayisi / 2 * 2 == gec1->GenSayisi) {
        if (gec2->GenSayisi / 2 * 2 == gec2->GenSayisi) {//ilk kromozom cift, ikinci kromozom cift iken

            Kromozom* yeniKromozom1 = new Kromozom;
            for (int i = 0; i < (gec1->GenSayisi / 2); i++)
            {
                yeniKromozom1->GenEkle(gec1->GenGetir(i));
            }    
            for (int i = (gec2->GenSayisi / 2); i < gec2->GenSayisi; i++)
            {
                yeniKromozom1->GenEkle(gec2->GenGetir(i));
            }
            KromozomEkle(yeniKromozom1);

            Kromozom* yeniKromozom2 = new Kromozom;
            for (int i = 0; i < (gec2->GenSayisi / 2); i++)
            {
                yeniKromozom2->GenEkle(gec2->GenGetir(i));
            }
            for (int i = (gec1->GenSayisi / 2); i < gec1->GenSayisi; i++)
            {
                yeniKromozom2->GenEkle(gec1->GenGetir(i));
            }
            KromozomEkle(yeniKromozom2);

        }
        else if (gec2->GenSayisi / 2 * 2 != gec2->GenSayisi) {//ilk kromozom cift, ikinci kromozom tek ise
            
            Kromozom* yeniKromozom1 = new Kromozom;
            for (int i = 0; i < (gec1->GenSayisi / 2); i++)
            {
                yeniKromozom1->GenEkle(gec1->GenGetir(i));
            }   
            for (int i = (gec2->GenSayisi / 2) + 1; i < gec2->GenSayisi; i++)
            {
                yeniKromozom1->GenEkle(gec2->GenGetir(i));
            }
            KromozomEkle(yeniKromozom1);

            Kromozom* yeniKromozom2 = new Kromozom;
            for (int i = 0; i < (gec2->GenSayisi / 2); i++)
            {
                yeniKromozom2->GenEkle(gec2->GenGetir(i));
            }
            for (int i = (gec1->GenSayisi / 2); i < gec1->GenSayisi; i++)
            {
                yeniKromozom2->GenEkle(gec1->GenGetir(i));
            }
            KromozomEkle(yeniKromozom2);

        }

    }
    else if (gec1->GenSayisi / 2 * 2 != gec1->GenSayisi) {
        
    if (gec2->GenSayisi / 2 * 2 == gec2->GenSayisi) {//ilk kromozom tek, ikinci kromozom cift ise
            
              Kromozom* yeniKromozom1 = new Kromozom;
        for (int i = 0; i < (gec1->GenSayisi / 2); i++){
             yeniKromozom1->GenEkle(gec1->GenGetir(i));
        }   
        for (int i = gec2->GenSayisi / 2; i < gec2->GenSayisi; i++){
            yeniKromozom1->GenEkle(gec2->GenGetir(i));
        }
            KromozomEkle(yeniKromozom1);

        Kromozom* yeniKromozom2 = new Kromozom;
            for (int i = 0; i < (gec2->GenSayisi / 2); i++){
                yeniKromozom2->GenEkle(gec2->GenGetir(i));
            }
            for (int i = (gec1->GenSayisi / 2) + 1; i < gec1->GenSayisi; i++){
                yeniKromozom2->GenEkle(gec1->GenGetir(i));
            }
                                 
                                 
            KromozomEkle(yeniKromozom2);

        }
        else if (gec2->GenSayisi / 2 * 2 != gec2->GenSayisi) {//ilk kromozom tek, ikinci kromozom tek ise
            
            Kromozom* yeniKromozom1 = new Kromozom;
            for (int i = 0; i < (gec1->GenSayisi / 2); i++)
            {
                yeniKromozom1->GenEkle(gec1->GenGetir(i));
            }  
            for (int i = (gec2->GenSayisi / 2) + 1; i < gec2->GenSayisi; i++)
            {
                yeniKromozom1->GenEkle(gec2->GenGetir(i));
            }
            KromozomEkle(yeniKromozom1);

            Kromozom* yeniKromozom2 = new Kromozom;
            for (int i = 0; i < (gec2->GenSayisi / 2); i++)
            {
                yeniKromozom2->GenEkle(gec2->GenGetir(i));
            }  
            for (int i = (gec1->GenSayisi / 2) + 1; i < gec1->GenSayisi; i++)
            {
                yeniKromozom2->GenEkle(gec1->GenGetir(i));
            }
            KromozomEkle(yeniKromozom2);

        }
        
    }
    
}

void KromozomListeleri::Mutasyon(int kromozom, int gen) {
    Kromozom* gec = ilkKromozom;
    
    if(kromozom>(kromozomSayisi-1) || kromozom<0 || gen<0 || gen>=gec->GenSayisi){
        cout<<"Olmayan gen veya kromozom sayisi girdiniz.";
          return;
        }
    for (int i = 0; i < kromozom; i++) {
        gec = gec->sonraki;
    } 
    // Yeni kromozom oluştur ve genleri kopyala
    Kromozom* yeniKromozom = new Kromozom;
    for (int i = 0; i < gen; i++) {
        yeniKromozom->GenEkle(gec->GenGetir(i));
    }

    
    
    yeniKromozom->GenEkle("X");

    for (int i = gen + 1; i < gec->GenSayisi; i++) {
        yeniKromozom->GenEkle(gec->GenGetir(i));
    }

    // Yeni kromozomu eski kromozomun yerine ekleme
    yeniKromozom->onceki = gec->onceki;
    yeniKromozom->sonraki = gec->sonraki;

    // Bağlantıları güncelle
    if (gec->onceki != 0) {
        gec->onceki->sonraki = yeniKromozom;
    } else {
        // Eğer bu ilk kromozomsa, liste başını güncelle
        ilkKromozom = yeniKromozom;
    }

    if (gec->sonraki != 0) {
        gec->sonraki->onceki = yeniKromozom;
    } else {
        // Eğer bu son kromozomsa, liste sonunu güncelle
        sonKromozom = yeniKromozom;
    }

    
    delete gec;
}


void KromozomListeleri::EkranaYaz() {
    Kromozom* gec = ilkKromozom; 
    while (gec != 0) { 
    bool kucukOlan = false;

        
          for (int i = gec->GenSayisi - 1; i >= 0; i--) { // Genleri tara
             if (gec->GenGetir(i) < gec->GenGetir(0)) { // Eğer gen ilk gen ile karşılaştırıldığında daha küçükse
                cout << gec->GenGetir(i) << " "; 
                kucukOlan = true; 
                break; 
            }
     }

        // Eğer küçük gen bulunmadıysa, ilk gen ekrana yazdır
        if (!kucukOlan) {
            cout << gec->GenGetir(0) << " ";
        }
        gec = gec->sonraki;
    }
}


void KromozomListeleri::OtomatikIslemler() {
    fstream islemlerDosyasi("src/islemler.txt", ios::in);
    if (!islemlerDosyasi) {
        cerr << "islemler.txt dosyasi acilamadi!" << endl;
        return;
    }

    string satir;
    while (getline(islemlerDosyasi, satir)) {
        istringstream iss(satir);
        string metod;
        int a, b;

        if (iss >> metod >> a >> b) {
        
        Kromozom* gec= ilkKromozom;
        
        for (int i = 0; i < a; i++)
        {
           gec=gec->sonraki;
        }
        
            if(a>kromozomSayisi || a<0 || b<0 || b>gec->GenSayisi){

                cout<<"!!!---Kromozom sayisindan fazla deger girilemez---!!!";
            return ;
            }

            if (metod == "C") {
                Caprazla(a, b);
            } else if (metod == "M") {
                Mutasyon(a, b);

            } else {
                cerr << "Geçersiz metod: " << metod << endl;
            }
        } 
    }

    islemlerDosyasi.close();

    
   dnayaz();

    cout << "Tum islemler tamamlandi." << endl;
}



 void KromozomListeleri::dnayaz(){

ofstream dnaDosyasi("src/dna.txt", ios::out);
    if (!dnaDosyasi) {
        cerr << "dna.txt dosyasi açilamadi!" << endl;
        return;
    }

    Kromozom* gec = ilkKromozom;
    while (gec != 0) {
        for (int i = 0; i < gec->GenSayisi; i++) {
            dnaDosyasi << gec->GenGetir(i) << " ";
        }
        dnaDosyasi << endl;
        gec = gec->sonraki;
    }

    dnaDosyasi.close();


 }