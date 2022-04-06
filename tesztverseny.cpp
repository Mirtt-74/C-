/*
6. feladat - tesztverseny
Egy közismereti versenyen a versenyzõknek 14 tesztfeladatot tûznek ki. A versenyzõknek minden feladat esetén négy megadott lehetõség (A, B, C, D)
közül kell a helyes választ megjelölniük. A versenybizottság garantálja, hogy tesztlapon minden kérdéshez pontosan egy helyes válasz tartozik. 
A kitöltött tesztlapokat elektronikusan rögzítik, a visszaélések elkerülése végett a versenyzõket betûkbõl és számokból álló kóddal azonosítják.
A helyes megoldást és a versenyzõk válaszait a valaszok.txt szöveges állomány tartalmazza. A fájlban legfeljebb 500 versenyzõ adatai szerepelnek. 
A fájl elsõ sorában a helyes válaszok szerepelnek. A fájl többi sora a versenyzõk kódjával kezdõdik, ezt egy szóköz, majd az adott versenyzõ által
adott válaszok sorozata követi. A versenyzõk kódja legfeljebb 5 karakterbõl áll. A válaszok a feladatokkal egyezõ sorrendben, elválasztójel nélkül,
nagybetûvel szerepelnek. Ha a versenyzõ egy kérdésre nem válaszolt, akkor annak helyén X betû szerepel.

BCCCDBBBBCDAAA                     helyes válaszok
AB123 BXCDBBACACADBC	1. versenyzõ kódja és adatai
AH97 BCACDBDDBCBBCA

Feladatok:
1.	Olvassa be és tárolja el a valaszok.txt szöveges állomány adatait (a helyes választ és a versenyzõk eredményeit) 
egy megfelelõ adatszerkezetbe, tárolja az egyes versenyzõk pontszámait is (minden helyes válasz egy pont) !
2.	Írja ki a képernyõre, hogy hány versenyzõ vett részt a versenyen!
3.	Írja ki a legtöbb pontot elért versenyzõ azonosítóját és pontszámát!
4.	Döntse el volt e maximális pontszámot elért versenyzõ!
5.	Számolja meg hány versenyzõ nem tudott legalább a kérdések felére válaszolni!
6.	Rendezze a pontszám szerint csökkenõ en az eredményeket és írja ki az elsõ 10 helyezettet a képernyõre!

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct aa {
	string nev;
	string valasz;
	int pont;
};

class Adat {
private:
	string jo;
	aa *tomb;
	int aa_db;
public:
	Adat(string fajlnev);
	int darab();
	void Legjobb();
	string VoltMax();
	int Nemtudott(int p);
	int Nemtudott_X(int p);
	void Rendezes(int p);
	void Csere();

	~Adat() {
		delete[]tomb;
	};



};

int main() {
	setlocale(LC_ALL, "hun");

	//1. feladat: fájl beolvasás
	cout << "\n1. feladat" << endl;
	string fajlnev = "valaszok.txt";
	Adat VERSENY(fajlnev);

	cout << "\n2. feladat" << endl;
	cout << "Versenyzok szama: " << VERSENY.darab() << endl;

	cout << "\n3. feladat" << endl;
	VERSENY.Legjobb();

	cout << "\n4. feladat" << endl;
	cout <<  VERSENY.VoltMax() << endl;

	cout << "\n5. feladat" << endl;
	cout << "Nem tudta a kérdések felét: " << VERSENY.Nemtudott(7) << endl;

	cout << "\n5/b feladat" << endl;
	cout << "Nem tudta a kérdések felét (X): " << VERSENY.Nemtudott_X(7) << endl;

	cout << "\n6. feladat" << endl;
	VERSENY.Rendezes(10);
	//VERSENY.Rendezes(VERSENY.darab());

	cout << "\nNem feladat" << endl;
	VERSENY.Csere();
	

	system("pause");
	return 0;
}

Adat::Adat(string fajlnev) {
	tomb = new aa[500];
	aa_db = 0;

	ifstream be;
	be.open(fajlnev);
	if (be.fail()) {
		cout << "Fajl hiba!";
		system("pause");
		exit(1);
	}
	be >> jo;
	//cout << "      " << jo << endl;

	while (be >> tomb[aa_db].nev >> tomb[aa_db].valasz) {
		tomb[aa_db].pont = 0;
		for (int i = 0; i < 14; i++) {
			if (jo[i] == tomb[aa_db].valasz[i]) {
				tomb[aa_db].pont++;
			}
		}
		
		//cout << tomb[aa_db].nev << " " << tomb[aa_db].valasz << " " << tomb[aa_db].pont << endl;
		aa_db++;
	}
	be.close();

	//cout << aa_db << endl;

/*	for (int i = 0; i < aa_db; i++) {
		cout << tomb[i].nev << " " << tomb[i].valasz << endl;
	}*/

};

int Adat::darab() {
	return aa_db;
};

void Adat::Legjobb() {
	//maximum
	int maxpont = 0;

	for (int i = 1; i < aa_db; i++) {
		if (tomb[maxpont].pont < tomb[i].pont) maxpont = i;
	}

	/*for (int i = 0; i < aa_db; i++) {
		if (tomb[maxpont].pont == tomb[i].pont) {
			cout << "Legjobb versenyzo(k): " << tomb[i].nev << " " << tomb[i].pont << endl;
		}
	}*/

	cout << "Legjobb versenyzo: " << tomb[maxpont].nev << " " << tomb[maxpont].pont << endl;
};

string Adat::VoltMax() {
	int i = 0;
	string volt = "Nem volt maximalis pontszam!";

	while (i < aa_db && tomb[i].pont != 14) {
		i++;
	}
	if (i < aa_db) {
		volt = "Volt maximalis pontszam!";
	}

	return volt;
};

int Adat::Nemtudott(int p) {
	int d = 0;
	for (int i = 0; i < aa_db; i++) {
		if (tomb[i].pont <= p) d++;
	}
	return d;
};

int Adat::Nemtudott_X(int p) {
	int d = 0;
	int x = 0;
	for (int i = 0; i < aa_db; i++) {
		x = 0;
		for (int j = 0; j < 14; j++) {
			if (tomb[i].valasz[j] == 'X') {
				x++;
			}
		}
		if (x >= p) {
			cout << tomb[i].nev << " " << tomb[i].valasz << " " << tomb[i].pont << endl;
			d++;
		}
	}
	return d;
};

void Adat::Rendezes(int p) {
	aa s;

	for (int i = 0; i < aa_db - 1; i++) {
		for (int j = i + 1; j < aa_db; j++) {
			if (tomb[i].pont < tomb[j].pont) {
				s = tomb[i];
				tomb[i] = tomb[j];
				tomb[j] = s;
			}
		}
	}

	for (int i = 0; i < p; i++) {
		cout << tomb[i].nev << " " << tomb[i].valasz << " " << tomb[i].pont << endl;
	}
};

void Adat::Csere() {
	cout << "      " << jo << endl;
	for (int i = 0; i < aa_db; i++) {
		for (int j = 0; j < 14; j++) {
			if (jo[j] != tomb[i].valasz[j]) {
				tomb[i].valasz[j] = ' ';
			}
		}
		cout << tomb[i].nev << " " << tomb[i].valasz << " " << tomb[i].pont << endl;
	}
}
