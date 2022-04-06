/*

 F U T � R S Z O L G � L A T

A nagyv�rosokon bel�l, ha csomagot gyorsan kell eljuttatni egyik helyr�l a m�sikra, akkor sokszor a legjobb v�laszt�s egy ker�kp�ros fut�rszolg�lat ig�nybev�tele.
A fut�rszolg�lat a fut�rjainak a megtett utak alapj�n ad fizet�st. Az egyik fut�r egy h�ten �t feljegyezte fuvarjai legfontosabb adatait, �s azokat elt�rolta egy �llom�nyban.
Az �llom�nyban az adatok r�gz�t�se nem mindig k�veti az id�rendi sorrendet. Azokra a napokra, amikor nem dolgozott, nincsenek adatok bejegyezve az �llom�nyba.
A f�jlban legal�bb 10 sor van, �s minden sor egy-egy �t adatait tartalmazza egym�st�l sz�k�zzel elv�lasztva. 
Az els� adat a nap sorsz�ma, ami 1 �s 7 k�z�tti �rt�k lehet. A m�sodik sz�m a napon bel�li fuvarsz�m, ami 1 �s 40 k�z�tti �rt�k lehet. 
Ez minden nap 1-t�l kezd�dik, �s az aznapi utols� fuvarig egyes�vel n�vekszik. A harmadik sz�m az adott fuvar sor�n megtett utat jelenti kilom�terben, eg�szre kerek�tve.
Ez az �rt�k nem lehet 30-n�l nagyobb.

P�ld�ul:
1 1 5
1 2 9
3 2 12
1 4 3
3 1 7
�

A 3. sor p�ld�ul azt mutatja, hogy a h�t harmadik napj�n a m�sodik fuvar 12 kilom�teres t�vols�got jelentett.
K�sz�tsen programot, amely az utak.txt �llom�ny adatait felhaszn�lva az al�bbi k�rd�sekre v�laszol! 
A program forr�sk�dj�t mentse futarszolgalat n�ven! 
(A program meg�r�sakor a felhaszn�l� �ltal megadott adatok helyess�g�t, �rv�nyess�g�t nem kell ellen�riznie, felt�telezheti, 
hogy a rendelkez�sre �ll� adatok a le�rtaknak megfelelnek.)
A k�perny�re �r�st ig�nyl� r�szfeladatok eredm�ny�nek megjelen�t�se el�tt �rja a k�perny�re a feladat sorsz�m�t (p�ld�ul: 3. feladat:)! 
Ha a felhaszn�l�t�l k�r be adatot, jelen�tse meg a k�perny�n, hogy milyen �rt�ket v�r! Az �kezetmentes ki�r�s is elfogadott.

Feladatok:

1. Olvassa be az utak.txt �llom�nyban tal�lt adatokat, s annak felhaszn�l�s�val oldja meg a k�vetkez� feladatokat!

2. �rja ki a k�perny�re, hogy mekkora volt a h�t m�sodik �tja kilom�terben! 
Figyeljen arra, hogy olyan �llom�ny eset�n is helyes �rt�ket adjon, amiben p�ld�ul a h�t els� napj�n a fut�r nem dolgozott!

3. �rja ki a k�perny�re, hogy mekkora volt a h�t utols� �tja kilom�terben!

4. Tudjuk, hogy a fut�r minden h�ten tart legal�bb egy szabadnapot.
�rja ki a k�perny�re, hogy a h�t h�nyadik napjain nem dolgozott a fut�r!

5. �rja ki a k�perny�re, hogy a h�t melyik napj�n volt a legt�bb fuvar!
Amennyiben t�bb nap is azonos, maxim�lis sz�m� fuvar volt, elegend� ezek egyik�t ki�rnia.

6. Sz�m�tsa ki �s �rja a k�perny�re a mint�nak megfelel�en, hogy az egyes napokon h�ny kilom�tert kellett tekerni!

1. nap: 124 km
2. nap: 0 km
3. nap: 75 km

7. A fut�r az egyes utakra az �t hossz�t�l f�gg�en kap fizet�st az al�bbi t�bl�zatnak megfelel�en:

1 � 2 km 500 Ft
3 � 5 km 700 Ft
6 � 10 km 900 Ft
11 � 20 km 1 400 Ft
21 � 30 km 2 000 Ft

K�rjen be a felhaszn�l�t�l egy tetsz�leges t�vols�got, �s hat�rozza meg, hogy mekkora d�jaz�s j�r �rte! Ezt �rja a k�perny�re!

8. Hat�rozza meg az �sszes r�gz�tett �t ellen�rt�k�t! Ezeket az �rt�keket �rja ki a befizetes.txt �llom�nyba nap szerint,
azon bel�l pedig az �t sorsz�ma szerinti cs�kken� sorrendben, az al�bbi form�tumban:

1. nap 1. �t: 2000 Ft
1. nap 2. �t: 900 Ft
1. nap 3. �t: 700 Ft

9. Hat�rozza meg, �s �rja ki a k�perny�re, hogy a fut�r mekkora �sszeget kap a heti munk�j��rt!

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct utak {
	int nap, sorszam, tav;
};

class Futar {
private: utak* ut;
	   int ut_db;
	   int max_sorszam;
	   int max_nap;
	   int max_fizetes;

public:
	Futar(string fnev);
	int Utja(int hanyadik);
	int Max_db();
	void Szabadnap();
	int Legtobbfuvar();
	void Napi_km();
	int Ber(int ut);
	void Napi_fizu();
	int Fizetes();

	~Futar() {
		delete[]ut;
	}
};

Futar::Futar(string fnev) {
	max_sorszam = 40;
	max_nap = 7;
	int max_adat = max_nap * max_sorszam;
	ut = new utak[max_adat];
	ut_db = 0;
	int i, j;
	int s1, s2;

	ifstream be;
	be.open(fnev);
	if (be.fail()) {
		cout << "Fajl hiba";
		system("pause");
		exit(1);
	}

	while (be >> ut[ut_db].nap >> ut[ut_db].sorszam >> ut[ut_db].tav) {
		ut_db++;
	}
	be.close();

	//sorba rendez�s
	utak seg;
	for (i = 0; i < ut_db - 1; i++) {
		for (j = i+1; j < ut_db; j++) {
			s1 = ut[i].nap * max_sorszam + ut[i].sorszam;
			s2 = ut[j].nap * max_sorszam + ut[j].sorszam;
			if (s1 > s2) {
				seg = ut[i];
				ut[i] = ut[j];
				ut[j] = seg;
			}
		}
	}

	for (i = 0; i < ut_db; i++) {
		cout << ut[i].nap << " " << ut[i].sorszam << " " << ut[i].tav << endl;
	}

};

int Futar::Utja(int hanyadik) {
	return ut[hanyadik].tav;
};

int Futar::Max_db() {
	return ut_db - 1;
};

void Futar::Szabadnap() {
	int *na;
	na = new int[max_nap];

	for (int i = 0; i < max_nap; i++) {
		na[i] = 0;
	}

	for (int i = 0; i < ut_db; i++) {
		na[ut[i].nap-1]++;
	}

	cout << "Szabadnapok:\n";
	for (int i = 0; i < max_nap; i++) {
		if (na[i] == 0) {
			cout << i+1 << " ";
		}
	}

	cout << endl;

};

int Futar::Legtobbfuvar() {
	int max_fuvar = 0;
	for (int i = 1; i < ut_db; i++) {
		if (ut[max_fuvar].sorszam < ut[i].sorszam) max_fuvar = i;
	}

	return ut[max_fuvar].nap;
};

void Futar::Napi_km() {
	int* na;
	na = new int[max_nap];

	for (int i = 0; i < max_nap; i++) {
		na[i] = 0;
	}

	for (int i = 0; i < ut_db; i++) {
		na[ut[i].nap - 1] += ut[i].tav;

		//if (ut[i].nap - 1 == 0) cout << ut[i].tav << " " << na[ut[i].nap - 1] << endl;
	}

	cout << "Napi km\n";
	for (int i = 0; i < max_nap; i++) {
		cout << i + 1 << " nap: " << na[i] << " km\n";
	}

	cout << endl;
};

int Futar::Ber(int ut) {
	int b = 0;

	if (ut >= 1 && ut <= 2) b = 500;
	if (ut >= 3 && ut <= 5) b = 700;
	if (ut >= 6 && ut <= 10) b = 900;
	if (ut >= 11 && ut <= 20) b = 1400;
	if (ut >= 21 && ut <= 30) b = 2000;

	return b;
}

void Futar::Napi_fizu() {
	int t;
	max_fizetes = 0;

	ofstream ki("befizetes.txt");

	cout << "Napi fizet�s\n";
	for (int i = 0; i < ut_db; i++) {
		t = Ber(ut[i].tav);
		max_fizetes += t;

		ki << ut[i].nap << ". nap " << ut[i].sorszam << ". �t: " << t << " Ft\n";
		cout << ut[i].nap << ". nap " << ut[i].sorszam << ". �t: " << t << " Ft\n";
	}
	ki.close();
	cout << endl;
};

int Futar::Fizetes() {
	return max_fizetes;
}


int main() {
	setlocale(LC_ALL, "hun");
	string fnev = "utak.txt";

	cout << "1.feladat: f�jl beolvas�s\n\n";
	Futar FF(fnev);

	cout << "\n2.feladat: m�sodik �t\n\n";
	cout << "M�sodik �t " << FF.Utja(1) << " km" << endl;

	cout << "\n3.feladat: utols� �t\n\n";
	cout << "Utols� �t " << FF.Utja(FF.Max_db()) << " km" << endl;

	cout << "\n4.feladat: szabadnap\n\n";
	FF.Szabadnap();

	cout << "\n5.feladat: legt�bb fuvar napja\n\n";
	cout << "Legt�bb fuvar napja: " << FF.Legtobbfuvar() << endl;

	cout << "\n6.feladat: napi km\n\n";
	FF.Napi_km();

	int t = 0;
	cout << "\n7.feladat: fizetes\n\n";
	cout << "K�rek egy t�vot:";
	cin >> t;
	cout << "\nFizet�se " << FF.Ber(t) << endl;

	cout << "\n8.feladat: napi fizetes\n\n";
	FF.Napi_fizu();

	cout << "\n9.feladat: fizetese\n\n";
	cout << "Heti fizet�se: " << FF.Fizetes() << " Ft" << endl;

	system("pause");
	return 0;
}