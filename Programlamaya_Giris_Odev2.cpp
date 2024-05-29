/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 2. ÖDEV
**				ÖĞRENCİ ADI...............: EREN KARTAL
**				ÖĞRENCİ NUMARASI.: B231210065
**				DERS GRUBU…………: A GRUBU 1. ÖĞRETİM
****************************************************************************/

//Kripto Para Birimi olarak Leb İsmi Kullanılmıştır "leb"
//1 ay sabit 30 gün ve 1 yıl sabit 360 gün olarak kabul edilmiştir

#include<iostream>
#include<iomanip>		//setw() komutu kullanımı amacıyla eklenmiştir.
#include <conio.h>		//_getch() komutu kullanımı amacıyla eklenmiştir.

using namespace std;

int gun = 0;
int ay = 0;
int yil = 0;
int sayac1 = 0;			//1 gün ilerileme genel sayaç

class Hesap				//Hesap sınıfı
{

private:				//Dışarıdan doğrudan erişilemeyen değişkenler

	float lebGenel;
	float lebOzel;
	float bakiyeDurumu;
	float alMiktarTLToplam;
	float satMiktarTLToplam;
	float karDurumu;

public:

	int id;				//Bu değişken dışarıdan girileceği için public yapılıp erişime açılmıştır.

	Hesap()				//Her nesne için ilk değerlerin girildiği yapıcı fonksyon

	{
		lebGenel = 1;
		lebOzel = 1;
		bakiyeDurumu = 0;
		id = 0;
		alMiktarTLToplam = 0;
		satMiktarTLToplam = 0;
		karDurumu = 0;
	}

	void alGenel()		//Genel Hesaplar için alım yapma fonksiyonu
	{
		float alMiktarTL = 0;
		cout << "Kaç TL değerinde leb almak istersiniz ? " << endl;
		cin >> alMiktarTL;
		alMiktarTLToplam += alMiktarTL;
		bakiyeDurumu += alMiktarTL / lebGenel;
		cout << "Anlık Leb Durumu:  " << bakiyeDurumu << " Leb" << endl;
	}

	void alOzel()		//Özel Hesaplar için alım yapma fonksiyonu
	{
		float alMiktarTL = 0;
		cout << "Kaç TL değerinde leb almak istersiniz ? " << endl;
		cin >> alMiktarTL;
		alMiktarTLToplam += alMiktarTL;
		bakiyeDurumu += alMiktarTL / lebOzel;
		cout << "Anlık Leb Durumu:  " << bakiyeDurumu << " Leb" << endl;
	}

	void satGenel()		//Genel Hesaplar için satım yapma fonksiyonu
	{
		float satMiktarTL = 0;
		cout << "Kaç TL değerinde leb çekmek istersiniz ? " << endl;
		cin >> satMiktarTL;
		satMiktarTLToplam += satMiktarTL;
		bakiyeDurumu -= satMiktarTL / lebGenel;
		cout << "Anlık Leb Durumu:  " << bakiyeDurumu << " Leb" << endl;

	}

	void satOzel()		//Özel Hesaplar için satım yapma fonksiyonu
	{
		float satMiktarTL = 0;
		cout << "Kaç TL değerinde leb çekmek istersiniz ? " << endl;
		cin >> satMiktarTL;
		satMiktarTLToplam += satMiktarTL;
		bakiyeDurumu -= satMiktarTL / lebOzel;
		cout << "Anlık Leb Durumu:  " << bakiyeDurumu << " Leb" << endl;

	}

	void bakiyeGenel()	//Genel Hesaplar için ID ve Bakiye görüntüleme fonksiyonu
	{
		cout << "Hesap ID: " << id << endl;
		cout << "Bakiye Durumu: " << bakiyeDurumu << " Leb / " << bakiyeDurumu * lebGenel << " TL" << endl;

	}

	void bakiyeOzel()	//Özel Hesaplar için ID ve Bakiye görüntüleme fonksiyonu
	{
		cout << "Hesap ID: " << id << endl;
		cout << "Bakiye Durumu: " << bakiyeDurumu << " Leb / " << bakiyeDurumu * lebOzel << " TL" << endl;

	}

	void karYazdirGenel()	//Genel Hesaplar için kar/zarar yazdırma fonksiyonu
	{
		karDurumu = bakiyeDurumu * lebGenel - alMiktarTLToplam + satMiktarTLToplam;
		cout << "Kar/Zarar Durumu: " << karDurumu << " TL" << endl;
	}

	void karYazdirOzel()	//Özel Hesaplar için kar/zarar yazdırma fonksiyonu
	{
		karDurumu = bakiyeDurumu * lebOzel - alMiktarTLToplam + satMiktarTLToplam;
		cout << "Kar/Zarar Durumu: " << karDurumu << " TL" << endl;
	}

	void genelHesapLebArtisSonrakiGun()		//Genel Hesaplar için güne göre leb uyarlanması
	{

		if (sayac1 % 15 == 0)
		{
			lebGenel -= lebGenel * 5 / 100;		//15 Günde bir % 5 düşüş
		}

		else
		{
			lebGenel += lebGenel * 1 / 100;		//Günlük % 1 artış 
		}

	}

	void ozelHesapLebArtisSonrakiGun()		//Özel Hesaplar için güne göre leb uyarlanması
	{
		srand(time(0));
		int gun1, gun2, gun3 = 0;
		gun1 = rand() % 30 + 1;
		gun2 = rand() % 30 + 1;
		gun3 = rand() % 30 + 1;

		if (gun == gun1)
		{
			lebOzel -= lebOzel * 10 / 100;		//Her bir aylık süreçte rasgele 3 günde, günlük %10 düşüş 
		}

		else if (gun == gun2)
		{
			lebOzel -= lebOzel * 10 / 100;		//Her bir aylık süreçte rasgele 3 günde, günlük %10 düşüş 
		}

		else if (gun == gun3)
		{
			lebOzel -= lebOzel * 10 / 100;		//Her bir aylık süreçte rasgele 3 günde, günlük %10 düşüş 
		}

		else
		{
			lebOzel += lebOzel * 5 / 100;		//Günlük %5 artış 
		}
	}

	void genelLebDurumu()					//Genel Hesaplar için Leb/TL yazdırma
	{
		cout << "1 Leb = " << lebGenel << " TL" << endl;
	}

	void ozelLebDurumu()					//Özel Hesaplar için Leb/TL yazdırma
	{
		cout << "1 Leb = " << lebOzel << " TL" << endl;
	}
};

Hesap genelHesaplar[100];					//Genel Hesaplar için 100 elemanlı bir dizi tanımlanmıştır.
Hesap ozelHesaplar[100];					//Özel Hesaplar için 100 elemanlı bir dizi tanımlanmıştır.

int main()
{

	setlocale(LC_ALL, "Turkish");			//Türkçe dil desteği
	system("Color 30");						//Konsol ekranı renk ayarlanması

	//Kullanıcıdan tarih girdisi alma

	cout << setw(50) << " HOŞ GELDİNİZ" << endl << endl;
	cout << setw(50) << " Lütfen başlangıç tarihini gün/ay/yıl olarak giriniz:" << endl;
	cout << setw(40) << " (1-30 arası) Gün: ";
	cin >> gun;
	cout << setw(40) << " (1-12 arası) Ay: ";
	cin >> ay;
	cout << setw(40) << "Yıl: ";
	cin >> yil;

	char tamamMidevamMi = 0;	//Bir işlemden sonra yeniden işlem yapabilmemizi sağlayan değişken 
	char dogruSecim = 0;		//Menü seçiminin başarılı/başarısız olduğunu bildirdiğimiz değişken
	int secim;					//Menü seçimi yapmamızı sağlayan değişken

	//Genel ve Özel Hesap sayısını tutan değişkenlerin tanımlanması.
	int genelHesapSayisi = 0;
	int ozelHesapSayisi = 0;

	int i = 1;	//Genel Hesap açmak için kullanılan değişken
	int j = 1;	//Özel Hesap açmak için kullanılan değişken
	int c = 1;	//Döngüler ve yazdırma işlemleri için kullanılan değişken



	do					//sonraki işleme geçmeye yarayan döngü
	{
		do				//ana menü seçimi
		{

			system("CLS");		//Konsol ekranı temizleme

			//Menü yazdırma

			cout << setw(10) << gun << "/" << ay << "/" << yil << setw(40) << " M E N Ü" << endl << endl;
			cout << setw(40) << "1-" << "Genel Hesap Aç" << endl;
			cout << setw(40) << "2-" << "Özel Hesap Aç" << endl;
			cout << setw(40) << "3-" << "Ekle" << endl;
			cout << setw(40) << "4-" << "Çek" << endl;
			cout << setw(40) << "5-" << "Tarih" << endl;
			cout << setw(40) << "6-" << "Listele" << endl;
			cout << setw(40) << "7-" << "Çıkış" << endl << endl;

			cout << setw(50) << "Seçiminiz ?" << endl;
			cin >> secim;	//Seçim 

			tamamMidevamMi = 0;

			switch (secim)
			{
				//Genel Hesap Açma
			case 1:

				dogruSecim = 'd';
				system("CLS");

				cout << setw(50) << "Genel hesap açılıyor..." << endl << endl;
				genelHesaplar[i];
				genelHesapSayisi++;
				cout << "Hesap id giriniz: (ID Rakamlardan Oluşmalı)" << endl;
				cin >> genelHesaplar[i].id;
				genelHesaplar[i].alGenel();
				i++;

				cout << setw(50) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();		//_getch() fonksiyonu ile kullanıcıdan bir tuşa basmasını istedik ve (void) sayesinde dönen değeri kullanmayacağımızı bildirdik.
				tamamMidevamMi = 't';

				break;

				//Özel Hesap Açma

			case 2:

				dogruSecim = 'd';
				system("CLS");

				cout << setw(50) << "Özel hesap açılıyor..." << endl << endl;
				ozelHesaplar[j];
				ozelHesapSayisi++;
				cout << "Hesap id giriniz: (ID Rakamlardan Oluşmalı)" << endl;
				cin >> ozelHesaplar[j].id;
				ozelHesaplar[j].alOzel();
				j++;

				cout << setw(50) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';

				break;

				//Alım yapma

			case 3:

				dogruSecim = 'd';
				system("CLS");

				int iddeneme;

				cout << setw(50) << "Hesap türü seçiniz: " << endl << endl;
				cout << setw(40) << "1-" << "Genel Hesap " << endl;
				cout << setw(40) << "2-" << "Özel Hesap " << endl;

				cin >> secim;
				switch (secim)

				{
					// Genel Hesaba Alım Yapma

				case 1:


					cout << "Hesap ID giriniz: " << endl; cin >> iddeneme;
					for (c = 1; c <= genelHesapSayisi; c++)
					{
						if (iddeneme == genelHesaplar[c].id)		//ID doğrulama
						{
							cout << "ID Doğrulandı, Giriş Başarılı" << endl;
							genelHesaplar[c].alGenel();

							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
						else
						{
							cout << "Geçersiz id, lütfen tekrar deneyiniz." << endl;
							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
					}
					break;

					// Özel Hesaba Alım Yapma

				case 2:

					cout << "Hesap ID giriniz: " << endl; cin >> iddeneme;
					for (c = 1; c <= ozelHesapSayisi; c++)		//ID doğrulama
					{
						if (iddeneme == ozelHesaplar[c].id)
						{
							cout << "ID Doğrulandı, Giriş Başarılı" << endl;
							ozelHesaplar[c].alOzel();

							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}

						else
						{
							cout << "Geçersiz id, lütfen tekrar deneyiniz." << endl;
							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
					}
					break;

				default:

					cout << setw(50) << "HATA" << endl << setw(60) << "Tekrar denemek için bir tuşa basınız" << endl;
					(void)_getch();
					tamamMidevamMi = 't';
					break;
				}


				break;

				// Hesaptan Satış Yapma

			case 4:

				dogruSecim = 'd';
				system("CLS");

				cout << setw(50) << "Hesap türü seçiniz: " << endl << endl;
				cout << setw(40) << "1-" << "Genel Hesap " << endl;
				cout << setw(40) << "2-" << "Özel Hesap " << endl;
				cin >> secim;
				switch (secim)

				{
					//Genel Hesaptan Satış Yapma

				case 1:

					cout << "Hesap ID giriniz: " << endl; cin >> iddeneme;
					for (c = 1; c <= genelHesapSayisi; c++)
					{
						if (iddeneme == genelHesaplar[c].id)		//ID doğrulama
						{
							cout << "ID Doğrulandı, Giriş Başarılı" << endl;
							genelHesaplar[c].satGenel();



							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
						else
						{
							cout << "Geçersiz id, lütfen tekrar deneyiniz." << endl;
							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
					}
					break;

					//Özel Hesaptan Satış Yapma

				case 2:

					cout << "Hesap ID giriniz: " << endl; cin >> iddeneme;
					for (c = 1; c <= ozelHesapSayisi; c++)
					{
						if (iddeneme == ozelHesaplar[c].id)		//ID doğrulama
						{
							cout << "ID Doğrulandı, Giriş Başarılı" << endl << endl;
							ozelHesaplar[c].satOzel();

							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
						else
						{
							cout << "Geçersiz id, lütfen tekrar deneyiniz." << endl;
							cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
							(void)_getch();
							tamamMidevamMi = 't';
						}
					}
					break;

				default:

					cout << setw(50) << "HATA" << endl << setw(60) << "Tekrar denemek için bir tuşa basınız" << endl;
					(void)_getch();
					tamamMidevamMi = 't';
					break;
				}

				break;

				//Tarih Değiştirme

			case 5:
				dogruSecim = 'd';
				system("CLS");
				cout << setw(40) << gun << "/" << ay << "/" << yil << endl << endl;
				cout << setw(40) << "1-" << "Sonraki güne geç" << endl;
				cout << setw(40) << "2-" << "Belirli bir güne git" << endl << endl;
				int secimGun;

				cout << setw(50) << "Seçiminiz ?" << endl;
				cin >> secimGun;

				switch (secimGun)
				{
					//Sonraki gün

				case 1:
					cout << "Sonraki güne geçiliyor...";
					gun++;
					if (gun > 30)
					{
						gun = 1;
						ay++;
					}

					if (ay > 12)
					{
						ay = 1;
						yil++;
					}
					sayac1++;

					//artış-azalış
					for (int c = 1; c <= genelHesapSayisi; c++)
					{
						genelHesaplar[c].genelHesapLebArtisSonrakiGun();
					}

					for (int c = 1; c <= ozelHesapSayisi; c++)
					{
						ozelHesaplar[c].ozelHesapLebArtisSonrakiGun();
					}

					tamamMidevamMi = 't';
					break;

					//Belirli bir gün

				case 2:

					cout << "Kaç gün ilerlemek istersiniz ?";
					int kacGun;
					cin >> kacGun;
					if (kacGun > 30)
					{
						gun += kacGun % 30;
						ay += kacGun / 30;
					}
					else
					{
						gun += kacGun;
					}

					if (ay > 12)
					{
						yil += ay / 12;
						ay %= 12;

					}

					sayac1 += kacGun;

					//artış-azalış

					for (int c = 1; c <= genelHesapSayisi; c++)
					{
						genelHesaplar[c].genelHesapLebArtisSonrakiGun();
					}

					for (int c = 1; c <= ozelHesapSayisi; c++)
					{
						ozelHesaplar[c].ozelHesapLebArtisSonrakiGun();
					}

					tamamMidevamMi = 't';

					break;

				default:
					cout << setw(50) << "HATA" << endl << setw(60) << "Lütfen tekrar deneyiniz" << endl;
				}

				//Listeleme

			case 6:

				dogruSecim = 'd';
				system("CLS");

				cout << setw(50) << "Genel Hesaplar: " << endl << endl;
				for (int c = 1; c <= genelHesapSayisi; c++)
				{
					cout << "Genel Hesap " << c << "\n"; genelHesaplar[c].bakiyeGenel(); cout << endl; genelHesaplar[c].karYazdirGenel();
				}

				cout << endl;

				genelHesaplar[1].genelLebDurumu();


				cout << setw(50) << "Özel Hesaplar: " << endl << endl;
				for (int c = 1; c <= ozelHesapSayisi; c++)
				{
					cout << "Özel Hesap " << c << "\n"; ozelHesaplar[c].bakiyeOzel(); cout << endl; ozelHesaplar[c].karYazdirOzel();
				}

				cout << endl;

				ozelHesaplar[1].ozelLebDurumu();

				cout << setw(60) << "Devam etmek için bir tuşa basınız" << endl;
				(void)_getch();
				tamamMidevamMi = 't';
				break;

				//Çıkış

			case 7:

				dogruSecim = 'd';
				cout << setw(50) << "Çıkış yapılıyor..." << endl;

				break;

			default:

				cout << setw(50) << "HATA" << endl << setw(60) << "Tekrar denemek için bir tuşa basınız" << endl;
				(void)_getch();

			}
		} while (dogruSecim == !'d');				//ana menü seçimi

	} while (tamamMidevamMi == 't');			//sonraki işleme geçiş


	return 0;
}
