#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Ekran ciktilarinin renkli olabilmesi icin gerekli fonksiyon.  

enum RENKLER // Renk kodlari
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
};

class KARAKTER {
public:
	char harf;
	int renk;

	KARAKTER() { // Karakter sinifinda olusturulan kurucu fonksiyon

	}
};

class KATAR {
public:
	KATAR() { // Katar sinifinda olusturulan kurucu fonksiyon
		harfSayisi = 0;
	}

	int harfEkle() {

		cout << endl;

		SetConsoleTextAttribute(hConsole, 6);
		cout << "Bir Onceki Harf Sayisi = " << harfSayisi << endl;  //Onceki islemde kac adet harf oldugunu yazdirir.
		SetConsoleTextAttribute(hConsole, 15);

		RENKLER renk = RENKLER((rand() % 6) + 9); // 9-14 arasinda rastgele renk secildi.
		harfler[49] = KARAKTER();
		harfler[harfSayisi].renk = renk;			//Dizi elemanlarinin renk degerleri atanir.
		harfler[harfSayisi].harf = (rand() % 25) + 65;	 //ASCII tablosu kullanilarak rastgele harf secildi.
		harfSayisi++;

		cout << endl;

		SetConsoleTextAttribute(hConsole, 6);
		cout << "Harf Sayisi = " << harfSayisi << endl;   //Ekrana kutu(lar) icinde olan harflerin sayisi yazdirildi.
		SetConsoleTextAttribute(hConsole, 15);

		cout << endl;

		return 0;
	}

	int harfCikar() {
		if (harfSayisi <= 0) {      //Kutuda harf olmadigi zaman cikarma islemi yapilamayacagi yazdirildi.

			cout << endl;

			SetConsoleTextAttribute(hConsole, 6);
			cout << "Bir Onceki Harf Sayisi = " << harfSayisi << endl;	//Onceki islemde kac adet harf oldugunu yazdirir.
			SetConsoleTextAttribute(hConsole, 15);

			cout << endl;

			SetConsoleTextAttribute(hConsole, 4);
			cout << "  ***  Cikarma Yapilamaz  ***  " << endl;
			SetConsoleTextAttribute(hConsole, 15);

			cout << endl;

			return 0;
		}
		else {							//Kutularda harf olmasi durumunda kutudan harf cikarma islemi gerceklesir.
			cout << endl;
			SetConsoleTextAttribute(hConsole, 6);
			cout << "Bir Onceki Harf Sayisi = " << harfSayisi << endl;  //Onceki islemde kac adet harfin oldugu yazdirilir.
			SetConsoleTextAttribute(hConsole, 15);

			harfler[--harfSayisi] = harfler[49];	// Cikarilan harfin degeri sifira atandý.

			cout << endl;

			SetConsoleTextAttribute(hConsole, 6);
			cout << "Harf Sayisi = " << harfSayisi << endl;  //Harf cikarma islemi sonrasinda kac adet harfin oldugu yazdirilir.
			SetConsoleTextAttribute(hConsole, 15);

			cout << endl;
		}
		return 0;
	}

	void yazdir() {
		if (harfSayisi <= 0) {
			cout << endl;           //Kutularda harf olmadigi zaman ekranin bos olmasi saglanir.
		}
		else {
			cout << SOLUSTKOSE;
			// Kutu sayisi harf sayisina  baðlý olduðu icin for döngüsü kullanýldý.
			for (int i = 0; i < harfSayisi; i++) {
				cout << DUZCIZGI << ASAGIAYRAC;
			}
			cout << endl;

			for (int i = 0; i < harfSayisi; i++) {                      //For dongusu ile harfler dizisinin elemanlari kutu iclerine yazdirilir.
				cout << DIKEYCIZGI;
				SetConsoleTextAttribute(hConsole, harfler[i].renk);
				cout << harfler[i].harf;
				SetConsoleTextAttribute(hConsole, 15);
			}

			cout << DIKEYCIZGI << endl << SOLALTKOSE;

			for (int i = 0; i < harfSayisi; i++) {
				cout << DUZCIZGI << YUKARIAYRAC;
			}
			cout << endl;
		}
	}

private:
	int harfSayisi;				      //Dizinin eleman sayilarini tutacak degisken tanimlandi.
	char DUZCIZGI = 205;
	char SOLUSTKOSE = 201;
	char SAGUSTKOSE = 187;
	char DIKEYCIZGI = 186;			  //Kutu olusturmak icin kullanilacak karakterler tanimlandi.
	char ASAGIAYRAC = 203;
	char SOLALTKOSE = 200;
	char SAGALTKOSE = 188;
	char YUKARIAYRAC = 202;
	KARAKTER harfler[50];		     //Karakter sinifindan 50 elemanli bir harfler dizisi olusturuldu.
};

int main()
{
	int secilenSecenek = 1;		//Yapilacak islemin numarasini tutacak degisken tanimlandi.
	int diziElemanSayisi = 0;	//Dizinin eleman sayisini sayacak degisken tanimlandi.
	srand(time(NULL));
	KATAR* dizi = new KATAR();		//Katar sinifindan dizi nesnesi olusturuldu (pointer)

	while (true)
	{
		cout << "Islem Seciniz..." << endl;
		cout << endl;
		cout << "1- Karakter Ekle" << endl;
		cout << "2- Karakter Cikar" << endl;
		cout << "3- Programdan Cikis" << endl;
		cout << "Secilen Islem Numarasi : ";
		cin >> secilenSecenek;		 //Degiskene islem numarasi atandi.

		cout << endl;

		if (diziElemanSayisi < 50)		//Dizi eleman sayisi sarti saglandiginda kod blogu calisir.
		{
			switch (secilenSecenek) {
			case 1:							//Secilen islem numarasinin 1 olmasi durumunda diziye harf eklenir ve ekranda kutu iclerinde yazdirilir.
				dizi->harfEkle();
				dizi->yazdir();
				cout << endl;
				diziElemanSayisi++;
				continue;
			case 2:							//Secilen islem numarasinin 2 olmasi durumunda diziye en son eklenen harf silinir. Geri kalan harf(ler) ekranda kutu iclerinde yazdirilir.
				dizi->harfCikar();
				dizi->yazdir();
				cout << endl;
				diziElemanSayisi--;
				continue;
			case 3:							//Secilen islem numarasinin 3 olmasi durumunda dizi silinir ve uygulamadan cikis yapilir.
				diziElemanSayisi = 0;
				delete dizi;
				return 0;
			default:						//Girilmesi istenen islem numarasinin olmasi gerekenler disinda olmasi durumunda uyari yazdirilir.
				SetConsoleTextAttribute(hConsole, 2);
				cout << "	!!!	Lutfen Menudeki Bir Secenegi Seciniz. !!!	" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << endl;
				continue;
			}
		}
		if (diziElemanSayisi >= 50) //Dizi eleman sayisi(50) asildiginda if blogu calisir.
		{
			switch (secilenSecenek) {
			case 1:							//Secilen islem numarasinin 1 olmasi durumunda diziye harf eklenemez.
				SetConsoleTextAttribute(hConsole, 4);
				cout << "	!!! Harf Sayisi Asildi Karakter Eklenemez !!!	" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << endl;
				continue;
			case 2:						//Secilen islem numarasinin 2 olmasi durumunda diziye en son eklenen harf silinir. Geri kalan harf(ler) ekranda kutu iclerinde yazdirilir.
				dizi->harfCikar();
				dizi->yazdir();
				cout << endl;
				diziElemanSayisi--;
				continue;
			case 3:							//Secilen islem numarasinin 3 olmasi durumunda dizi silinir ve uygulamadan cikis yapilir.
				delete dizi;
				diziElemanSayisi = 0;
				return 0;
			default:						//Girilmesi istenen islem numarasinin olmasi gerekenler disinda olmasi durumunda uyari yazdirilir.
				SetConsoleTextAttribute(hConsole, 2);
				cout << "	!!!	Lutfen Menudeki Bir Secenegi Seciniz. !!!	" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << endl;
				continue;
			}
		}
	}
	return 0;
}