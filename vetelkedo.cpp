/*
12. Számok
A Szereti Ön a számokat? internetes vetélkedõben a versenyzõk olyan kérdéseket kapnak,
amelyekre egy egész számmal kell válaszolniuk. A kérdések különbözõ témakörökbõl
származnak (pl. magyar, matematika, történelem, kémia), és nehézségüktõl függõen 1-tõl 3-ig
terjedõ pontszámot érnek. Tudjuk, hogy a kérdésekre adható válaszok értéke 0 és 1 milliárd
közé esik.
A feladatokat a verseny szervezõi egy adatfájlban tárolják. A fájlban minden feladat két
sorban helyezkedik el. Az elsõ sor tartalmazza a kérdést, a második pedig – egy-egy
szóközzel elválasztva – a helyes választ, a helyes válaszért adható pontszámot és a témakör
megnevezését. A fájlban egyelõre ékezetes betûk nem szerepelnek, pl. a „gyümölcsízû” szó
helyett a „gyumolcsizu” szót írták be.
Például:
Mikor volt a mohacsi vesz?
1526 1 tortenelem
A példában szereplõ kérdés: Mikor volt a mohacsi vesz? A helyes válasz: 1526.
A helyes válasz 1 pontot ér, és a kérdés a tortenelem témakörbe tartozik.
Az adatfájl még csak részben készült el. Az Ön feladata ennek a félkész adatfájlnak
a tesztelése. A fájl legfeljebb 100 kérdést tartalmaz. Biztosan van benne matematika,
történelem és földrajz feladat, de más témakörök is elõfordulnak.
Készítsen programot, amely a felszam.txt állomány adatait felhasználva az alábbi
kérdésekre válaszol! A program forráskódját mentse szamok néven! (A beolvasott fájl
adatait és a felhasználó válaszainak az érvényességét nem kell ellenõriznie.)
A képernyõre írást igénylõ feladatok eredményének megjelenítése elõtt írja ki a képernyõre
a feladat sorszámát (például: 3. feladat)! Ha a felhasználótól kér be adatot, akkor jelenítse
meg a képernyõn azt is, hogy milyen adatot vár! Az ékezetmentes kiírás is elfogadott.

1. Olvassa be a felszam.txt állományban talált adatokat, és azok felhasználásával oldja
meg a következõ feladatokat!

2. Hány feladat van az adatfájlban? A választ írassa ki a képernyõre!

3. Határozza meg, hogy hány matematika feladat van az adatfájlban, és ezek közül hány
feladat ér 1, 2, illetve 3 pontot! A választ egész mondatban írassa ki a képernyõre!
Például:
Az adatfajlban 20 matematika feladat van, 1 pontot er
10 feladat, 2 pontot er 6 feladat, 3 pontot er 4 feladat.

4. Mettõl meddig terjed a fájlban található válaszok számértéke? A választ egész mondatban
írja ki a képernyõre!

5. Milyen témakörök szerepelnek ténylegesen az adatfájlban? Írassa ki a témakörök nevét
a képernyõre úgy, hogy minden elõforduló témakör pontosan egyszer jelenjen meg!

6. Kérje be egy témakör nevét, és véletlenszerûen sorsoljon ki egy kérdést ebbõl
a témakörbõl! Sorsoláskor ügyeljen arra, hogy az adott témakörbe esõ valamennyi feladatnak legyen esélye! (Feltételezheti, hogy a felhasználó helyesen adta meg egy létezõ
témakör nevét.) Írassa ki a kérdést, kérje be a felhasználó válaszát, majd adja meg
a válaszért járó pontszámot! (Helytelen válaszért 0 pont jár.) Ha a válasz helytelen volt,
a helyes választ is közölje! A párbeszéd az alábbi formában jelenjen meg:
Például:
Milyen temakorbol szeretne kerdest kapni? tortenelem
Mikor volt a mohacsi vesz? 1514
A valasz 0 pontot er.
A helyes valasz: 1526

7. Generáljon egy 10 kérdésbõl álló feladatsort véletlenszerûen úgy, hogy egyetlen feladat se
szerepeljen benne kétszer! (Ügyeljen azonban arra, hogy minden beolvasott feladatnak
legyen esélye a kiválasztásra!) A feladatsort írassa ki a tesztfel.txt állományba
az alábbi formátumban! (Az elsõ szám a helyes megoldásért járó pontszám, ezt követi
a helyes válasz, majd a kérdés egy-egy szóközzel elválasztva.) Az állomány végére írassa
ki a feladatsorra összesen adható pontszámot is!
Például:
…
1 1526 Mikor volt a mohacsi vesz?
…
A feladatsorra osszesen 20 pont adhato.



*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Kerdes {
	string kerdes;
	int valasz;
	int pont;
	string tema;
};

class Feladat {
private: Kerdes *tomb;
		 int t_db;
		 string tema[100];
		 int tema_db = 0;

public:
	Feladat(string fnev);
	int HanyFeladat();
	string Tipus(string mit);
	void MinMax();
	void Temakor();
	void EgyKerdes();
	void TizKerdes();

	~Feladat() {
		delete[]tomb;
	}
};

int main() {
	string fajlnev = "felszam.txt";

	Feladat TT(fajlnev);
	cout << "\nFeladatok szama: " << TT.HanyFeladat() << endl;
	TT.Temakor();
	cout << TT.Tipus("matematika") << endl;
	TT.MinMax();
	TT.TizKerdes();

	/*for (int i = 0; i < 10; i++) {
		TT.TizKerdes();
		cout << endl;
	}*/

	string te;
	do {
		TT.EgyKerdes();
		cout << "\nAkarsz meg jatszani(Y/N)? " << endl;
		cin >> te;
	} while (te == "Y" || te == "y");

	//TT.TizKerdes();


	system("pause");
	return 0;
}

Feladat::Feladat(string fnev) {
	tomb = new Kerdes[100];
	t_db = 0;
	string s;
	int sor = 0;

	ifstream be(fnev);
	if (be.fail()) {
		cout << "Fajl hiba";
		system("pause");
		exit(1);
	}

	while (getline(be, s)) {
		sor++;
		if (sor % 2 == 0) {
			int s_len = s.length();
			int s1 = 0;
			int s2 = 0;
			int sz = 0;
			for (int i = 0; i < s_len; i++) {
				if (s[i] == ' ') {
					if (sz == 0) {
						tomb[t_db].valasz = std::stoi(s.substr(0, i));
						s1 = i + 1;
						sz++;
					}
					else if (sz == 1) {
						tomb[t_db].pont = std::stoi(s.substr(s1, i - s1));
						s1 = i + 1;
						tomb[t_db].tema = s.substr(s1, s_len - s1);
						sz++;
					}
				}
			}
			t_db++;
		}
		else {
			tomb[t_db].kerdes = s;
		}

	}

	/*while (!be.eof()) {
		getline(be, tomb[t_db].kerdes);
		getline(be, tomb[t_db].valasz);

		/*be >> tomb[t_db].valasz;
		be >> tomb[t_db].pont;
		be >> tomb[t_db].tema;* /
		cout << tomb[t_db].kerdes << " " << tomb[t_db].valasz << " " << tomb[t_db].pont << " " << tomb[t_db].tema << endl;
		t_db++;
	}*/

	be.close();

	for (int i = 0; i < t_db; i++) {
		cout << i + 1 << ". " << tomb[i].kerdes << " : " << tomb[i].valasz << " : " << tomb[i].pont << " : " << tomb[i].tema << endl;
	}

};

int Feladat::HanyFeladat() {
	return t_db;
};

string Feladat::Tipus(string mit) {
	int db = 0;
	int pont[5] = { 0 };

	string te = mit;
	int volt;

	/*do {
		cout << "\nKerek egy tantargyat:" << endl;
		cin >> te;
		volt = 0;
		for (int j = 0; j <= tema_db; j++) {
			if (tema[j] == te) {
				volt = 1;
			}
		}
	} while (volt == 0);*/

	for (int i = 0; i < t_db; i++) {
		if (tomb[i].tema == te) {
			db++;
			pont[tomb[i].pont]++;
		}
	}

	string s = "\nAz adatfajlban " + std::to_string(db)  + " "  + te + " feladat van, 1 pontot er " + std::to_string(pont[1]) + " feladat, 2 pontot er " + std::to_string(pont[2]) + " feladat, 3 pontot er " + std::to_string(pont[3]) + " feladat.";

	return s;
};

void Feladat::MinMax() {
	int m1 = 0; //tomb[0].pont;
	int m2 = 0; //tomb[0].pont;

	for (int i = 1; i < t_db; i++) {
		if (tomb[i].valasz < tomb[m1].valasz) {
			m1 = i;
		}
		if (tomb[i].valasz > tomb[m2].valasz) {
			m2 = i;
		}
	}

	cout << "\nMinimum szam: " << tomb[m1].valasz << ", maximum szam: " << tomb[m2].valasz << endl;
};

void Feladat::Temakor() {
	//string tema[100];
	//int tema_db = 0;

	tema[0] = tomb[0].tema;

	for (int i = 1; i < t_db; i++) {
		int v = 0;
		for (int j = 0; j <= tema_db; j++) {
			if (tema[j] == tomb[i].tema) {
				v = 1;
			}
		}
		if (v == 0) {
			tema_db++;
			tema[tema_db] = tomb[i].tema;
		}
	}

	cout << "Temakorok:" << endl;
	for (int j = 0; j <= tema_db; j++) {
		cout << tema[j] << endl;
	}

};

void Feladat::EgyKerdes() {
	int db = 0;
	Kerdes egy[100];
	string te;
	int volt;

	do {
		cout << "\nMilyen temakorbol szeretne kerdest kapni? " << endl;
		cin >> te;
		volt = 0;
		for (int j = 0; j <= tema_db; j++) {
			if (tema[j] == te) {
				volt = 1;
			}
		}
	} while (volt == 0);

	for (int i = 0; i < t_db; i++) {
		if (tomb[i].tema == te) {
			egy[db] = tomb[i];
			//cout << i + 1 << ". " << egy[db].kerdes << " : " << egy[db].valasz << " : " << egy[db].pont << " : " << egy[db].tema << endl;
			db++;
		}
	}
	
	srand((unsigned int)time(NULL));
	int s = rand() % db;
	int v = 0;
	cout << egy[s].kerdes << endl;
	cin >> v;
	if (v == egy[s].valasz) {
		cout << "A jo valasz " << egy[s].pont << " pontot er." << endl;
	}
	else {
		cout << "A valasz 0 pontot er." << endl;
		cout << "A helyes valasz: " << egy[s].valasz << endl;
	}

};

void Feladat::TizKerdes() {
	int db = 0;
	int pont[10] = { 0 };
	Kerdes egy[10];
	string te;
	int volt;
	int szum_pont = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		int s = rand() % t_db;
		int j = 0;
		while (j < i && s != pont[j]) {
			j++;
		}
		if (j == i) {
			pont[j] = s;
		}
		else {
			i--;
		}
		cout << "i: " << i << " j: " << j << " s: " << s << endl;
	}

	ofstream ki("tesztfel.txt");
	if (ki.fail()) { cout << "Fajl hiba!" << endl; system("pause"); exit(1); }
	for (int i = 0; i < 10; i++) {
		szum_pont += tomb[pont[i]].pont;
		ki << tomb[pont[i]].pont << " " << tomb[pont[i]].valasz << " " << tomb[pont[i]].kerdes << endl;
		cout << tomb[pont[i]].pont << " " << tomb[pont[i]].valasz << " " << tomb[pont[i]].kerdes << endl;
	}
	ki << "\nA feladatsorra osszesen " << szum_pont << " pont adhato." << endl;
	cout << "\nA feladatsorra osszesen " << szum_pont << " pont adhato." << endl;
	ki.close();

};