/*
F E H É R J É K

A fehérjék óriás molekulák, amelyeknek egy része az élõ szervezetekben végbemenõ folyamatokat katalizálják. 
Egy-egy fehérje aminosavak százaiból épül fel, melyek láncszerûen kapcsolódnak egymáshoz. 
A természetben a fehérjék fajtája több millió. Minden fehérje húszféle aminosav különbözõ mennyiségû és sorrendû összekapcsolódásával épül fel. 
Az alábbi táblázat tartalmazza az aminosavak legfontosabb adatait, a megnevezéseket és az õket alkotó atomok számát 
(az aminosavak mindegyike tartalmaz szenet, hidrogént, oxigént és nitrogént, néhányban kén is van):

Neve Rövidítés Betûjele C H O N S
Glicin Gly G 2 5 2 1 0
Alanin Ala A 3 7 2 1 0
Arginin Arg R 6 14 2 4 0
Fenilalanin Phe F 9 11 2 1 0
Cisztein Cys C 3 7 2 1 1
Triptofán Trp W 11 12 2 2 0
Valin Val V 5 11 2 1 0
Leucin Leu L 6 13 2 1 0
Izoleucin Ile I 6 13 2 1 0
Metionin Met M 5 11 2 1 1

Készítsen programot feherjek néven, ami megoldja a következõ feladatokat! 
Ügyeljen arra, hogy a program forráskódját a megadott helyre mentse!

1. Töltse be az aminosavak.txt fájlból az aminosavak adatait! 
A fájlban minden adat külön sorban található, a fájl az aminosavak nevét nem tartalmazza.
Ha az adatbetöltés nem sikerül, vegye fel a fenti táblázat alapján állandóként az elsõ 7 adatsort, és azzal dolgozzon! Az elsõ néhány adat:

Gly
G
2
5
2
1
0
Ala
A
3
7
2
1
0

2. Határozza meg az aminosavak relatív molekulatömegét, ha a szén atomtömege 12, a hidrogéné 1, az oxigéné 16, a nitrogéné 14 és a kén atomtömege 32!
Például a Glicin esetén a relatív molekulatömeg 2·12 + 5·1 + 2·16 + 1·14 + 0·32 = 75. 
A következõ feladatok eredményeit írja képernyõre, illetve az eredmeny.txt fájlba! 
A kiírást a feladat sorszámának feltüntetésével kezdje (például: 4. feladat)!

3. Rendezze csökkenõ sorrendbe az aminosavakat a relatív molekulatömeg szerint!
Írja ki a képernyõre és az eredmenyek.txt fájlba az aminosavak hárombetûs azonosítóját és a molekulatömeget!
Az azonosítót és hozzátartozó molekulatömeget egy sorba, szóközzel elválasztva írja ki!

4. A bsa.txt a BSA nevû fehérje aminosav sorrendjét tartalmazza – egybetûs jelöléssel.
(A fehérjelánc legfeljebb 1000 aminosavat tartalmaz.) Határozza meg a fehérje összegképletét (azaz a C, H, O, N és S számát)! 
A meghatározásánál vegye figyelembe, hogy az aminosavak összekapcsolódása során minden kapcsolat létrejöttekor egy vízmolekula (H2O) lép ki!
Az összegképletet a képernyõre és az eredmenyek.txt fájlba az alábbi formában írja ki: Például: C 16321 H 34324 O 4234 N 8210 S 2231 
(Amennyiben a bsa.txt beolvasása sikertelen, helyette tárolja a G,A,R,F,C betûjeleket ötször egymás után és a feladatokat erre a „láncra” oldja meg!)

5. A fehérjék szekvencia szerkezetét hasításos eljárással határozzák meg. Egyes enzimek bizonyos aminosavak után kettéhasítják a fehérjemolekulát.
Például a Kimotripszin enzim a Tirozin (Y), Fenilalanin (W) és a Triptofán (F) után hasít. Határozza meg, és írja ki képernyõre a Kimotripszin enzimmel
széthasított BSA lánc leghosszabb darabjának hosszát és az eredeti láncban elfoglalt helyét (elsõ és utolsó aminosavának sorszámát)! 
A kiíráskor nevezze meg a kiírt adatot, például: „kezdet helye:”!

6. Egy másik enzim (a Factor XI) az Arginin (R) után hasít, de csak akkor, ha Alinin (A) vagy Valin (V) követi.
Határozza meg, hogy a hasítás során keletkezõ elsõ fehérjelánc részletben hány Cisztein (C) található!
A választ teljes mondatba illesztve írja ki a képernyõre!

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Feher {
	string nev;
	char kod[1];
	int C, H, O, N, S;
	int Moltom;
};

class Feherje {
private: Feher *tomb;
		 int t_db;
		 int Atom[5] = { 12,1,16,14,32 };
		 string f_ki = "eredmeny.txt";
		 string Amino;
		 int a_db;
		 Feher A;

public:
	Feherje(string fnev);
	void Molekulatomeg();
	void Sorrend();
	void Aminosav(string fnev);
	void Kimotripszin();
	void Factor();

	~Feherje() {
		delete[]tomb;
	}
};


int main() {
	string fajl = "aminosavak.txt";
	string fajla = "bsa.txt";

	Feherje FF(fajl);
	FF.Molekulatomeg();
	FF.Sorrend();
	FF.Aminosav(fajla);
	FF.Kimotripszin();
	FF.Factor();

	system("pause");
	return 0;
}


/*   FV   */

Feherje::Feherje(string fnev) {
	int i = 0;
	t_db = 0;
	string s;
	 
	ifstream be;
	be.open(fnev);
	if (be.fail()) {
		cout << "Fajl beolvasai hiba!";
		system("pause");
		exit(1);
	}
	while (!be.eof()) {
		be >> s;
		t_db++;
	}
	t_db /= 7;

	cout << t_db << endl;

	tomb = new Feher[t_db];

	be.clear();
	be.seekg(0, ios::beg);

	while (!be.eof() || i < t_db) {
		be >> tomb[i].nev;
		be >> tomb[i].kod;
		be >> tomb[i].C;
		be >> tomb[i].H;
		be >> tomb[i].O;
		be >> tomb[i].N;
		be >> tomb[i].S;
		tomb[i].Moltom = 0;
		i++;
	}
	be.close();

	/*for (i = 0; i < t_db; i++) {
		cout << i + 1 << ". " << tomb[i].nev << " " << tomb[i].kod << " " << tomb[i].C << " " << tomb[i].H << " " << tomb[i].O << " " 
			<< tomb[i].N << " " << tomb[i].S << " " << tomb[i].Moltom << endl;
	}*/

}

void Feherje::Molekulatomeg() {
	ofstream ki(f_ki);
	ki << "2. feladat" << endl;

	for (int i = 0; i < t_db; i++) {
		tomb[i].Moltom = tomb[i].C * Atom[0] + tomb[i].H * Atom[1] + tomb[i].O * Atom[2] + tomb[i].N * Atom[3] + tomb[i].S * Atom[4];
		cout << i + 1 << ". " << tomb[i].nev << " " << tomb[i].Moltom << endl;

		ki << i + 1 << ". " << tomb[i].nev << " " << tomb[i].kod << " " << tomb[i].C << " " << tomb[i].H << " " << tomb[i].O << " "
			<< tomb[i].N << " " << tomb[i].S << " " << tomb[i].Moltom << endl;
	}

	ki.close();
}

void Feherje::Sorrend() {
	ofstream ki(f_ki, std::ios_base::app);
	ki << "3. feladat" << endl;

	Feher st;

	for (int i = 0; i < t_db - 1; i++) {
		for (int j = i + 1; j < t_db; j++) {
			if (tomb[i].Moltom < tomb[j].Moltom) {
				st = tomb[i];
				tomb[i] = tomb[j];
				tomb[j] = st;
			}
		}
	}

	for (int i = 0; i < t_db; i++) {
		cout << tomb[i].nev << " " << tomb[i].Moltom << endl;
		ki << tomb[i].nev << " " << tomb[i].Moltom << endl;
	}

	for (int i = 0; i < t_db; i++) {
		cout << i + 1 << ". " << tomb[i].nev << " " << tomb[i].kod << " " << tomb[i].C << " " << tomb[i].H << " " << tomb[i].O << " "
			<< tomb[i].N << " " << tomb[i].S << " " << tomb[i].Moltom << endl;
	}

	ki.close();
}

void Feherje::Aminosav(string fnev) {
	int i;
	string s = "";
	Amino = "";
	a_db = 0;
	float Ossz[5] = { 0 };

	ifstream be(fnev);
	while (!be.eof()) {
		be >> s; // Amino[i];
		Amino += s;

		i = 0;
		while (i < t_db && s != tomb[i].kod) {
			i++;
		}
		Ossz[0] += tomb[i].C;
		Ossz[1] += tomb[i].H;
		Ossz[2] += tomb[i].O;
		Ossz[3] += tomb[i].N;
		Ossz[4] += tomb[i].S;

		//cout << s << ": " << tomb[i].kod << ": i:" << i << ": C " << Ossz[0] << " H " << Ossz[1] << " O " << Ossz[2] << " N " << Ossz[3] << " S " << Ossz[4] << endl;

		a_db++;
	}
	be.close();
	cout << Amino << endl;
	//cout << a_db << endl;

	//cout << "C " << Ossz[0] << " H " << Ossz[1] << " O " << Ossz[2] << " N " << Ossz[3] << " S " << Ossz[4] << endl;

	Ossz[1] -= (a_db - 1) * 2;
	Ossz[2] -= (a_db - 1);

	cout << "C " << Ossz[0] << " H " << Ossz[1] << " O " << Ossz[2] << " N " << Ossz[3] << " S " << Ossz[4] << endl;
};

void Feherje::Kimotripszin() {
	int start = 0;
	int stop = 0;
	int max_hossz = 0;

	int s1, s2;

	for (int i = 0; i < a_db; i++) {
		stop = i;
		if (Amino[i] == 'Y' || Amino[i] == 'W' || Amino[i] == 'F' ) {
			cout << (stop - start) + 1  << " " << Amino.substr(start, (stop - start) + 1) << endl;
			if (max_hossz < (stop - start) + 1 ) {
				max_hossz = stop - start + 1;
				s1 = start;
				s2 = stop;
			}
			start = i + 1;
			stop = i + 1;
		}
	}
	cout << (stop - start) + 1 << " " << Amino.substr(start, (stop - start) + 1) << endl;
	if (max_hossz < (stop - start) + 1) {
		max_hossz = stop - start + 1;
		s1 = start;
		s2 = stop;
	}

	cout << "S1: " << s1 << " S2: " << s2 << " Hossz: " << max_hossz << endl;
};

void Feherje::Factor() {
	int start = 0;
	int stop = 0;
	int max_hossz = 0;
	int c_db = 0;

	int s1, s2;

	cout << "\nFactor (" << a_db << ")" << endl;
	for (int i = 0; i < a_db-1; i++) {
		stop = i;
		if (Amino[i] == 'R' && (Amino[i+1] == 'A' || Amino[i+1] == 'V')) {
			if (c_db == 0) {
				for (int j = 0; j < i; j++) {
					if (Amino[j] == 'C') c_db++;
				}
				cout << "Cisztein szama az elso feherjelancban: " << c_db << endl;
			}


			cout << (stop - start) + 1 << " " << Amino.substr(start, (stop - start) + 1) << endl;
			if (max_hossz < (stop - start) + 1) {
				max_hossz = stop - start + 1;
				s1 = start;
				s2 = stop;
			}
			start = i + 1;
			stop = i + 1;
		}
	}
	cout << (a_db - start) << " " << Amino.substr(start, (a_db - start)) << endl;
	if (max_hossz < (a_db - start) ) {
		max_hossz = a_db - start;
		s1 = start;
		s2 = a_db;
	}

	cout << "S1: " << s1 << " S2: " << s2 << " Hossz: " << max_hossz << endl;
};
