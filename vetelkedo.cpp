/*
12. Sz�mok
A Szereti �n a sz�mokat? internetes vet�lked�ben a versenyz�k olyan k�rd�seket kapnak,
amelyekre egy eg�sz sz�mmal kell v�laszolniuk. A k�rd�sek k�l�nb�z� t�mak�r�kb�l
sz�rmaznak (pl. magyar, matematika, t�rt�nelem, k�mia), �s neh�zs�g�kt�l f�gg�en 1-t�l 3-ig
terjed� pontsz�mot �rnek. Tudjuk, hogy a k�rd�sekre adhat� v�laszok �rt�ke 0 �s 1 milli�rd
k�z� esik.
A feladatokat a verseny szervez�i egy adatf�jlban t�rolj�k. A f�jlban minden feladat k�t
sorban helyezkedik el. Az els� sor tartalmazza a k�rd�st, a m�sodik pedig � egy-egy
sz�k�zzel elv�lasztva � a helyes v�laszt, a helyes v�lasz�rt adhat� pontsz�mot �s a t�mak�r
megnevez�s�t. A f�jlban egyel�re �kezetes bet�k nem szerepelnek, pl. a �gy�m�lcs�z�� sz�
helyett a �gyumolcsizu� sz�t �rt�k be.
P�ld�ul:
Mikor volt a mohacsi vesz?
1526 1 tortenelem
A p�ld�ban szerepl� k�rd�s: Mikor volt a mohacsi vesz? A helyes v�lasz: 1526.
A helyes v�lasz 1 pontot �r, �s a k�rd�s a tortenelem t�mak�rbe tartozik.
Az adatf�jl m�g csak r�szben k�sz�lt el. Az �n feladata ennek a f�lk�sz adatf�jlnak
a tesztel�se. A f�jl legfeljebb 100 k�rd�st tartalmaz. Biztosan van benne matematika,
t�rt�nelem �s f�ldrajz feladat, de m�s t�mak�r�k is el�fordulnak.
K�sz�tsen programot, amely a felszam.txt �llom�ny adatait felhaszn�lva az al�bbi
k�rd�sekre v�laszol! A program forr�sk�dj�t mentse szamok n�ven! (A beolvasott f�jl
adatait �s a felhaszn�l� v�laszainak az �rv�nyess�g�t nem kell ellen�riznie.)
A k�perny�re �r�st ig�nyl� feladatok eredm�ny�nek megjelen�t�se el�tt �rja ki a k�perny�re
a feladat sorsz�m�t (p�ld�ul: 3. feladat)! Ha a felhaszn�l�t�l k�r be adatot, akkor jelen�tse
meg a k�perny�n azt is, hogy milyen adatot v�r! Az �kezetmentes ki�r�s is elfogadott.

1. Olvassa be a felszam.txt �llom�nyban tal�lt adatokat, �s azok felhaszn�l�s�val oldja
meg a k�vetkez� feladatokat!

2. H�ny feladat van az adatf�jlban? A v�laszt �rassa ki a k�perny�re!

3. Hat�rozza meg, hogy h�ny matematika feladat van az adatf�jlban, �s ezek k�z�l h�ny
feladat �r 1, 2, illetve 3 pontot! A v�laszt eg�sz mondatban �rassa ki a k�perny�re!
P�ld�ul:
Az adatfajlban 20 matematika feladat van, 1 pontot er
10 feladat, 2 pontot er 6 feladat, 3 pontot er 4 feladat.

4. Mett�l meddig terjed a f�jlban tal�lhat� v�laszok sz�m�rt�ke? A v�laszt eg�sz mondatban
�rja ki a k�perny�re!

5. Milyen t�mak�r�k szerepelnek t�nylegesen az adatf�jlban? �rassa ki a t�mak�r�k nev�t
a k�perny�re �gy, hogy minden el�fordul� t�mak�r pontosan egyszer jelenjen meg!

6. K�rje be egy t�mak�r nev�t, �s v�letlenszer�en sorsoljon ki egy k�rd�st ebb�l
a t�mak�rb�l! Sorsol�skor �gyeljen arra, hogy az adott t�mak�rbe es� valamennyi feladatnak legyen es�lye! (Felt�telezheti, hogy a felhaszn�l� helyesen adta meg egy l�tez�
t�mak�r nev�t.) �rassa ki a k�rd�st, k�rje be a felhaszn�l� v�lasz�t, majd adja meg
a v�lasz�rt j�r� pontsz�mot! (Helytelen v�lasz�rt 0 pont j�r.) Ha a v�lasz helytelen volt,
a helyes v�laszt is k�z�lje! A p�rbesz�d az al�bbi form�ban jelenjen meg:
P�ld�ul:
Milyen temakorbol szeretne kerdest kapni? tortenelem
Mikor volt a mohacsi vesz? 1514
A valasz 0 pontot er.
A helyes valasz: 1526

7. Gener�ljon egy 10 k�rd�sb�l �ll� feladatsort v�letlenszer�en �gy, hogy egyetlen feladat se
szerepeljen benne k�tszer! (�gyeljen azonban arra, hogy minden beolvasott feladatnak
legyen es�lye a kiv�laszt�sra!) A feladatsort �rassa ki a tesztfel.txt �llom�nyba
az al�bbi form�tumban! (Az els� sz�m a helyes megold�s�rt j�r� pontsz�m, ezt k�veti
a helyes v�lasz, majd a k�rd�s egy-egy sz�k�zzel elv�lasztva.) Az �llom�ny v�g�re �rassa
ki a feladatsorra �sszesen adhat� pontsz�mot is!
P�ld�ul:
�
1 1526 Mikor volt a mohacsi vesz?
�
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