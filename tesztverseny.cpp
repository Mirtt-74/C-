/*
6. feladat - tesztverseny
Egy k�zismereti versenyen a versenyz�knek 14 tesztfeladatot t�znek ki. A versenyz�knek minden feladat eset�n n�gy megadott lehet�s�g (A, B, C, D)
k�z�l kell a helyes v�laszt megjel�lni�k. A versenybizotts�g garant�lja, hogy tesztlapon minden k�rd�shez pontosan egy helyes v�lasz tartozik. 
A kit�lt�tt tesztlapokat elektronikusan r�gz�tik, a vissza�l�sek elker�l�se v�gett a versenyz�ket bet�kb�l �s sz�mokb�l �ll� k�ddal azonos�tj�k.
A helyes megold�st �s a versenyz�k v�laszait a valaszok.txt sz�veges �llom�ny tartalmazza. A f�jlban legfeljebb 500 versenyz� adatai szerepelnek. 
A f�jl els� sor�ban a helyes v�laszok szerepelnek. A f�jl t�bbi sora a versenyz�k k�dj�val kezd�dik, ezt egy sz�k�z, majd az adott versenyz� �ltal
adott v�laszok sorozata k�veti. A versenyz�k k�dja legfeljebb 5 karakterb�l �ll. A v�laszok a feladatokkal egyez� sorrendben, elv�laszt�jel n�lk�l,
nagybet�vel szerepelnek. Ha a versenyz� egy k�rd�sre nem v�laszolt, akkor annak hely�n X bet� szerepel.

BCCCDBBBBCDAAA                     helyes v�laszok
AB123 BXCDBBACACADBC	1. versenyz� k�dja �s adatai
AH97 BCACDBDDBCBBCA

Feladatok:
1.	Olvassa be �s t�rolja el a valaszok.txt sz�veges �llom�ny adatait (a helyes v�laszt �s a versenyz�k eredm�nyeit) 
egy megfelel� adatszerkezetbe, t�rolja az egyes versenyz�k pontsz�mait is (minden helyes v�lasz egy pont) !
2.	�rja ki a k�perny�re, hogy h�ny versenyz� vett r�szt a versenyen!
3.	�rja ki a legt�bb pontot el�rt versenyz� azonos�t�j�t �s pontsz�m�t!
4.	D�ntse el volt e maxim�lis pontsz�mot el�rt versenyz�!
5.	Sz�molja meg h�ny versenyz� nem tudott legal�bb a k�rd�sek fel�re v�laszolni!
6.	Rendezze a pontsz�m szerint cs�kken� en az eredm�nyeket �s �rja ki az els� 10 helyezettet a k�perny�re!

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

	//1. feladat: f�jl beolvas�s
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
	cout << "Nem tudta a k�rd�sek fel�t: " << VERSENY.Nemtudott(7) << endl;

	cout << "\n5/b feladat" << endl;
	cout << "Nem tudta a k�rd�sek fel�t (X): " << VERSENY.Nemtudott_X(7) << endl;

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
