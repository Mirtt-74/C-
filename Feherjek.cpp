/*
F E H � R J � K

A feh�rj�k �ri�s molekul�k, amelyeknek egy r�sze az �l� szervezetekben v�gbemen� folyamatokat kataliz�lj�k. 
Egy-egy feh�rje aminosavak sz�zaib�l �p�l fel, melyek l�ncszer�en kapcsol�dnak egym�shoz. 
A term�szetben a feh�rj�k fajt�ja t�bb milli�. Minden feh�rje h�szf�le aminosav k�l�nb�z� mennyis�g� �s sorrend� �sszekapcsol�d�s�val �p�l fel. 
Az al�bbi t�bl�zat tartalmazza az aminosavak legfontosabb adatait, a megnevez�seket �s az �ket alkot� atomok sz�m�t 
(az aminosavak mindegyike tartalmaz szenet, hidrog�nt, oxig�nt �s nitrog�nt, n�h�nyban k�n is van):

Neve R�vid�t�s Bet�jele C H O N S
Glicin Gly G 2 5 2 1 0
Alanin Ala A 3 7 2 1 0
Arginin Arg R 6 14 2 4 0
Fenilalanin Phe F 9 11 2 1 0
Cisztein Cys C 3 7 2 1 1
Triptof�n Trp W 11 12 2 2 0
Valin Val V 5 11 2 1 0
Leucin Leu L 6 13 2 1 0
Izoleucin Ile I 6 13 2 1 0
Metionin Met M 5 11 2 1 1

K�sz�tsen programot feherjek n�ven, ami megoldja a k�vetkez� feladatokat! 
�gyeljen arra, hogy a program forr�sk�dj�t a megadott helyre mentse!

1. T�ltse be az aminosavak.txt f�jlb�l az aminosavak adatait! 
A f�jlban minden adat k�l�n sorban tal�lhat�, a f�jl az aminosavak nev�t nem tartalmazza.
Ha az adatbet�lt�s nem siker�l, vegye fel a fenti t�bl�zat alapj�n �lland�k�nt az els� 7 adatsort, �s azzal dolgozzon! Az els� n�h�ny adat:

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

2. Hat�rozza meg az aminosavak relat�v molekulat�meg�t, ha a sz�n atomt�mege 12, a hidrog�n� 1, az oxig�n� 16, a nitrog�n� 14 �s a k�n atomt�mege 32!
P�ld�ul a Glicin eset�n a relat�v molekulat�meg 2�12 + 5�1 + 2�16 + 1�14 + 0�32 = 75. 
A k�vetkez� feladatok eredm�nyeit �rja k�perny�re, illetve az eredmeny.txt f�jlba! 
A ki�r�st a feladat sorsz�m�nak felt�ntet�s�vel kezdje (p�ld�ul: 4. feladat)!

3. Rendezze cs�kken� sorrendbe az aminosavakat a relat�v molekulat�meg szerint!
�rja ki a k�perny�re �s az eredmenyek.txt f�jlba az aminosavak h�rombet�s azonos�t�j�t �s a molekulat�meget!
Az azonos�t�t �s hozz�tartoz� molekulat�meget egy sorba, sz�k�zzel elv�lasztva �rja ki!

4. A bsa.txt a BSA nev� feh�rje aminosav sorrendj�t tartalmazza � egybet�s jel�l�ssel.
(A feh�rjel�nc legfeljebb 1000 aminosavat tartalmaz.) Hat�rozza meg a feh�rje �sszegk�plet�t (azaz a C, H, O, N �s S sz�m�t)! 
A meghat�roz�s�n�l vegye figyelembe, hogy az aminosavak �sszekapcsol�d�sa sor�n minden kapcsolat l�trej�ttekor egy v�zmolekula (H2O) l�p ki!
Az �sszegk�pletet a k�perny�re �s az eredmenyek.txt f�jlba az al�bbi form�ban �rja ki: P�ld�ul: C 16321 H 34324 O 4234 N 8210 S 2231 
(Amennyiben a bsa.txt beolvas�sa sikertelen, helyette t�rolja a G,A,R,F,C bet�jeleket �tsz�r egym�s ut�n �s a feladatokat erre a �l�ncra� oldja meg!)

5. A feh�rj�k szekvencia szerkezet�t has�t�sos elj�r�ssal hat�rozz�k meg. Egyes enzimek bizonyos aminosavak ut�n kett�has�tj�k a feh�rjemolekul�t.
P�ld�ul a Kimotripszin enzim a Tirozin (Y), Fenilalanin (W) �s a Triptof�n (F) ut�n has�t. Hat�rozza meg, �s �rja ki k�perny�re a Kimotripszin enzimmel
sz�thas�tott BSA l�nc leghosszabb darabj�nak hossz�t �s az eredeti l�ncban elfoglalt hely�t (els� �s utols� aminosav�nak sorsz�m�t)! 
A ki�r�skor nevezze meg a ki�rt adatot, p�ld�ul: �kezdet helye:�!

6. Egy m�sik enzim (a Factor XI) az Arginin (R) ut�n has�t, de csak akkor, ha Alinin (A) vagy Valin (V) k�veti.
Hat�rozza meg, hogy a has�t�s sor�n keletkez� els� feh�rjel�nc r�szletben h�ny Cisztein (C) tal�lhat�!
A v�laszt teljes mondatba illesztve �rja ki a k�perny�re!

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
