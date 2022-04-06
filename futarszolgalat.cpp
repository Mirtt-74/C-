/*

 F U T Á R S Z O L G Á L A T

A nagyvárosokon belül, ha csomagot gyorsan kell eljuttatni egyik helyrõl a másikra, akkor sokszor a legjobb választás egy kerékpáros futárszolgálat igénybevétele.
A futárszolgálat a futárjainak a megtett utak alapján ad fizetést. Az egyik futár egy héten át feljegyezte fuvarjai legfontosabb adatait, és azokat eltárolta egy állományban.
Az állományban az adatok rögzítése nem mindig követi az idõrendi sorrendet. Azokra a napokra, amikor nem dolgozott, nincsenek adatok bejegyezve az állományba.
A fájlban legalább 10 sor van, és minden sor egy-egy út adatait tartalmazza egymástól szóközzel elválasztva. 
Az elsõ adat a nap sorszáma, ami 1 és 7 közötti érték lehet. A második szám a napon belüli fuvarszám, ami 1 és 40 közötti érték lehet. 
Ez minden nap 1-tõl kezdõdik, és az aznapi utolsó fuvarig egyesével növekszik. A harmadik szám az adott fuvar során megtett utat jelenti kilométerben, egészre kerekítve.
Ez az érték nem lehet 30-nál nagyobb.

Például:
1 1 5
1 2 9
3 2 12
1 4 3
3 1 7
…

A 3. sor például azt mutatja, hogy a hét harmadik napján a második fuvar 12 kilométeres távolságot jelentett.
Készítsen programot, amely az utak.txt állomány adatait felhasználva az alábbi kérdésekre válaszol! 
A program forráskódját mentse futarszolgalat néven! 
(A program megírásakor a felhasználó által megadott adatok helyességét, érvényességét nem kell ellenõriznie, feltételezheti, 
hogy a rendelkezésre álló adatok a leírtaknak megfelelnek.)
A képernyõre írást igénylõ részfeladatok eredményének megjelenítése elõtt írja a képernyõre a feladat sorszámát (például: 3. feladat:)! 
Ha a felhasználótól kér be adatot, jelenítse meg a képernyõn, hogy milyen értéket vár! Az ékezetmentes kiírás is elfogadott.

Feladatok:

1. Olvassa be az utak.txt állományban talált adatokat, s annak felhasználásával oldja meg a következõ feladatokat!

2. Írja ki a képernyõre, hogy mekkora volt a hét második útja kilométerben! 
Figyeljen arra, hogy olyan állomány esetén is helyes értéket adjon, amiben például a hét elsõ napján a futár nem dolgozott!

3. Írja ki a képernyõre, hogy mekkora volt a hét utolsó útja kilométerben!

4. Tudjuk, hogy a futár minden héten tart legalább egy szabadnapot.
Írja ki a képernyõre, hogy a hét hányadik napjain nem dolgozott a futár!

5. Írja ki a képernyõre, hogy a hét melyik napján volt a legtöbb fuvar!
Amennyiben több nap is azonos, maximális számú fuvar volt, elegendõ ezek egyikét kiírnia.

6. Számítsa ki és írja a képernyõre a mintának megfelelõen, hogy az egyes napokon hány kilométert kellett tekerni!

1. nap: 124 km
2. nap: 0 km
3. nap: 75 km

7. A futár az egyes utakra az út hosszától függõen kap fizetést az alábbi táblázatnak megfelelõen:

1 – 2 km 500 Ft
3 – 5 km 700 Ft
6 – 10 km 900 Ft
11 – 20 km 1 400 Ft
21 – 30 km 2 000 Ft

Kérjen be a felhasználótól egy tetszõleges távolságot, és határozza meg, hogy mekkora díjazás jár érte! Ezt írja a képernyõre!

8. Határozza meg az összes rögzített út ellenértékét! Ezeket az értékeket írja ki a befizetes.txt állományba nap szerint,
azon belül pedig az út sorszáma szerinti csökkenõ sorrendben, az alábbi formátumban:

1. nap 1. út: 2000 Ft
1. nap 2. út: 900 Ft
1. nap 3. út: 700 Ft

9. Határozza meg, és írja ki a képernyõre, hogy a futár mekkora összeget kap a heti munkájáért!

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

	//sorba rendezés
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

	cout << "Napi fizetés\n";
	for (int i = 0; i < ut_db; i++) {
		t = Ber(ut[i].tav);
		max_fizetes += t;

		ki << ut[i].nap << ". nap " << ut[i].sorszam << ". út: " << t << " Ft\n";
		cout << ut[i].nap << ". nap " << ut[i].sorszam << ". út: " << t << " Ft\n";
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

	cout << "1.feladat: fájl beolvasás\n\n";
	Futar FF(fnev);

	cout << "\n2.feladat: második út\n\n";
	cout << "Második út " << FF.Utja(1) << " km" << endl;

	cout << "\n3.feladat: utolsó út\n\n";
	cout << "Utolsó út " << FF.Utja(FF.Max_db()) << " km" << endl;

	cout << "\n4.feladat: szabadnap\n\n";
	FF.Szabadnap();

	cout << "\n5.feladat: legtöbb fuvar napja\n\n";
	cout << "Legtöbb fuvar napja: " << FF.Legtobbfuvar() << endl;

	cout << "\n6.feladat: napi km\n\n";
	FF.Napi_km();

	int t = 0;
	cout << "\n7.feladat: fizetes\n\n";
	cout << "Kérek egy távot:";
	cin >> t;
	cout << "\nFizetése " << FF.Ber(t) << endl;

	cout << "\n8.feladat: napi fizetes\n\n";
	FF.Napi_fizu();

	cout << "\n9.feladat: fizetese\n\n";
	cout << "Heti fizetése: " << FF.Fizetes() << " Ft" << endl;

	system("pause");
	return 0;
}