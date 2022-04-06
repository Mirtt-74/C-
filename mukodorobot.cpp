/*

ROBOT PROGRAM

Tibi�k iskolai szakk�r�n robotot �p�tenek. M�r elk�sz�tettek egy olyan v�ltozatot, amelyik s�k terepen kell� pontoss�ggal vez�relhet�.
A robot a mem�ri�j�ba el�re bet�pl�lt programok egyik�t hajtja v�gre. 
A robot jelenleg csak az E, K, D, N utas�t�sokat �rti, amelyek a n�gy �gt�j (sorrendben: �szak, kelet, d�l, nyugat) ir�ny�ban tett 1 centim�teres elmozdul�st eredm�nyezik.
A robotba t�pl�lt programokat a robotprogram.txt �llom�nyban r�gz�tett�k. 
Az �llom�ny els� sor�ban a bet�pl�lt programok sz�ma tal�lhat�, amely legfeljebb 100. 
Alatta soronk�nt egy-egy program olvashat�. Egy sor legfeljebb 200 karakter hossz�s�g�, benne az E, K, D, N karakterek, mint utas�t�sok tal�lhat�k. A sorok nem tartalmaznak sz�k�zt.
P�ld�ul:
robotprogram.txt
12
ENNNDKENDND
ENNDDDDENDENDEEDDNNKED

A 2. sorban az els� bet�pl�lt program utas�t�sai vannak. K�sz�tsen programot, amely az al�bbi k�rd�sekre v�laszol! A program forr�sk�dj�t mukodorobot n�ven mentse! 
Minden r�szfeladat megold�sa el�tt �rja a k�perny�re a feladat sorsz�m�t! 
Ha a felhaszn�l�t�l k�r be adatot, jelen�tse meg a k�perny�n, hogy milyen �rt�ket v�r (p�ld�ul 2. feladat: K�rem az utas�t�ssor sorsz�m�t!)!

1. Olvassa be a program.txt �llom�nyban tal�lt adatokat, s azok felhaszn�l�s�val oldja meg a k�vetkez� feladatokat! 
Ha az �llom�nyt nem tudja beolvasni, az �llom�ny els� 8 sor�nak adatait jegyezze be a programba �s dolgozzon azzal!

2. K�rje be egy utas�t�ssor sz�m�t, majd �rja a k�perny�re, hogy:
a)	Egyszer�s�thet�-e az utas�t�ssorozat! Az egyszer�s�thet�, illetve nem egyszer�s�thet� v�laszt �rja a k�perny�re! 
(Egy utas�t�ssort egyszer�s�thet�nek nevez�nk, ha van benne k�t szomsz�dos, ellent�tes ir�nyt kifejez� utas�t�sp�r, hiszen ezek a p�rok elhagyhat�k. Ilyen ellent�tes utas�t�sp�r az ED, DE, KN, NK.)

b)	Az utas�t�ssor v�grehajt�s�t k�vet�en legkevesebb mennyi E vagy D �s K vagy N utas�t�ssal lehetne a robotot a kiindul�si pontba visszajuttatni! 
A v�laszt a k�vetkez� form�ban jelen�tse meg: 3 l�p�st kell tenni az ED, 4 l�p�st a KN tengely ment�n.

c)	Annak v�grehajt�sa sor�n h�nyadik l�p�st k�vet�en ker�lt (l�gvonalban) legt�volabb a robot a kiindul�si pontt�l �s mekkora volt ez a t�vols�g! 
A t�vols�got a l�p�s sorsz�m�t k�vet�en 4 tizedes pontoss�ggal �rja a k�perny�re!

3. A robot a mozg�shoz sz�ks�ges energi�t egy be�p�tett akkub�l nyeri. A robot 1 centim�ternyi t�vols�g megt�tel�hez 2 egys�g, az ir�nyv�lt�sokhoz �s az indul�shoz 3 egys�g energi�t haszn�l. 
Ennek alapj�n az EKK utas�t�ssor v�grehajt�s�hoz 12 egys�g energia sz�ks�ges. 
A szakk�r�n haszn�lt teljesen felt�lt�tt kis kapacit�s� akkub�l 100, a nagykapacit�s�b�l 500 egys�gnyi energia nyerhet� ki. 
Adja meg azon utas�t�ssorokat, amelyek v�grehajt�s�hoz a teljesen felt�lt�tt kis kapacit�s� akku is elegend�! 
�rja a k�perny�re egym�st�l sz�k�zzel elv�lasztva az utas�t�ssor sorsz�m�t �s a sz�ks�ges energia mennyis�g�t! 
Minden �rintett utas�t�ssor k�l�n sorba ker�lj�n!

4. Tibi�k tov�bbfejlesztett�k az utas�t�sokat �rtelmez� programot. 
Az �j, jelenleg m�g tesztel�s alatt �ll� v�ltozatban a t�bb, v�ltozatlan ir�nyban tett elmozdul�st helyettes�tj�k az adott ir�nyban tett elmozdul�sok sz�m�val �s az ir�ny bet�j�vel.
Teh�t p�ld�ul a DDDDKDDD utas�t�ssor le�rhat� r�vid�tett 4DK3D form�ban is. Az �n�ll�an �ll� utas�t�sn�l az 1-es sz�mot nem szabad ki�rni! 
Hozza l�tre az ujrobotprog.txt �llom�nyt, amely a robotprogram.txt �llom�nyban foglalt utas�t�ssorozatokat az �j form�ra alak�tja �gy, 
hogy az egym�st k�vet� azonos utas�t�sokat minden esetben a r�vid�tett alakra cser�li! 
Az ujrobotprog.txt �llom�nyba soronk�nt egy utas�t�ssor ker�lj�n, a sorok ne tartalmazzanak sz�k�zt!

5. Sajnos a tesztek r�mutattak arra, hogy a program �j verzi�ja m�g nem t�k�letes, ez�rt vissza kell t�rni az utas�t�ssorok le�r�s�nak r�gebbi v�ltozat�hoz. 
Mivel a szakk�r�s�k nagyon b�ztak az �j v�ltozatban, ez�rt n�h�ny utas�t�ssort m�r csak ennek megfelel�en k�sz�tettek el. Seg�tsen ezeket vissza�rni az eredeti form�ra! 
Az ism�tl�d�sek sz�ma legfeljebb 200 lehet! K�rjen be egy �j form�tum� utas�t�ssort, majd �rja a k�perny�re r�gi form�ban!


*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

class Osztaly {
private: string *tomb;
		 int prg_db;
		 string *tomb_uj;
		 string fki = "ujrobotprog.txt";

public:
	Osztaly(string fnev);
	int Darab();
	string Egyszeru(int s);
	void Lepes(int s);
	void Energia();
	void Ujrobotprg();
	void Vissza();

	~Osztaly() {
		delete[]tomb;
	}

};

Osztaly::Osztaly(string fnev) {
	tomb = new string[100];
	int i = 0;

	ifstream be(fnev);
	if (be.fail()) {
		cout << "Fajl hiba";
		system("pause");
		exit(1);
	}
	be >> prg_db;
	while (be >> tomb[i]) {
		i++;
	}
	be.close();

	cout << "Programok szama: " << prg_db << endl;
	for (i = 0; i < prg_db; i++) {
		cout << i + 1 << ". " << tomb[i] << endl;
	}
};

int Osztaly::Darab() {
	return prg_db;
};

string Osztaly::Egyszeru(int s) {
	int s_len;
	string m;
	int i = 0;
	bool volt = false;
	string ki = "nem egyszerusitheto";

	m = tomb[s - 1];
	s_len = m.length();
	do {
		string ss = m.substr(i, 2);
		if (ss == "ED" || ss == "DE" || ss == "KN" || ss == "NK") volt = true;
		i++;
	} while (i < s_len && volt == false);

	if (volt == true) ki = "egyszerusitheto";

	return ki;

};

void Osztaly::Lepes(int s) {
	int x = 0, y = 0;
	int s_len;
	string m;
	int i = 0;
	float tav = 0;
	float max_tav = 0;
	int max_lepes = 0;

	m = tomb[s - 1];
	s_len = m.length();
	for (i = 0; i < s_len; i++) {
		char ss = m[i];
		switch (ss) {
		case 'E': y++; break;
		case 'D': y--; break;
		case 'K': x++; break;
		case 'N': x--; break;
		}	
		tav = x*x + y*y;
		tav = sqrt(tav);
		if (tav > max_tav) {
			max_tav = tav;
			max_lepes = i + 1;
		}
	}

	cout << "\n2/b. feladat: Vissza\n\n";
	cout << abs(y) << " l�p�st kell tenni az ED, " << abs(x) << " l�p�st a KN tengely ment�n." << endl;

	cout << "\n2/c. feladat: Tav\n\n";
	cout << "Maximum tavolsag " << max_lepes << " lepesnel tavolsaga: " << max_tav << " cm\n\n";


};

void Osztaly::Energia() {
	int i, j, s;
	int *e;

	e = new int[prg_db];

	for (i = 0; i < prg_db; i++) {
		s = tomb[i].length();
		e[i] = 3 + 2*s;
		for (j = 1; j < s; j++) {
			if (tomb[i][j - 1] != tomb[i][j]) e[i] += 3;
		}

		if (e[i] < 10000) {
			cout << i + 1 << ". " << e[i] << endl;
		}
	}
}

void Osztaly::Ujrobotprg() {
	int i, j, s, k;

	tomb_uj = new string[prg_db];

	for (i = 0; i < prg_db; i++) {
		s = tomb[i].length();
		k = 0;
		//tomb_uj[prg_db] = "";
		for (j = 1; j < s; j++) {
			k++;
			if (tomb[i][j - 1] != tomb[i][j]) {
				if (k == 1) {
					tomb_uj[i] +=  tomb[i][j - 1];
				}
				else {
					tomb_uj[i] += std::to_string(k) + tomb[i][j - 1];
				}
				k = 0;
			}
		}
			if (k == 0) {
				tomb_uj[i] += tomb[i][s-1];
			}
			else {
				tomb_uj[i] += std::to_string(k) + tomb[i][s-1];
			}
	}

	ofstream ki(fki);
	if (ki.fail()) { cout << "Fajl hiba!" << endl; system("pause"); exit(1); }
	for (i = 0; i < prg_db; i++) {
		ki << tomb_uj[i] << endl;
		cout << tomb_uj[i] << endl;
	}
	ki.close();
}

void Osztaly::Vissza() {
	string s;
	int sl, j, i;
	char s1;
	string ki;

	cout << "Kerek egy kodsorozatot!";
	cin >> s;

	sl = s.length();
	for (j = 0; j < sl; j++) {
		s1 = s[j];
		if (s1 >= '0' && s1 <= '9') {
			int k = s1-48;
			for (i = 0; i < k; i++) {
				ki += s[j+1];
			}
			j++;
		}
		else {
			ki += s[j];
		}
	}
	cout << "Dekod: " << ki << endl;

}

int main() {
	setlocale(LC_ALL, "hun");

	string fajlnev = "robotprogram.txt";
	int ssz;
	int psz;

	cout << "1. feladat: beolvasas\n\n";
	Osztaly DD(fajlnev);

	cout << "2. feladat: sorszam bekeres\n\n";
	psz = DD.Darab();
	do {
		cout << "Kerek egy sorszamot (1.." << psz << "):";
		cin >> ssz;
		cin.ignore();
	} while (ssz <= 0 || ssz > psz);

	cout << "2/a. feladat: Egyszerusitheto?\n\n";
	cout << "A(z) " << ssz << ". program " << DD.Egyszeru(ssz) << endl;
	DD.Lepes(ssz);

	cout << "3. feladat: Energia\n\n";
	DD.Energia();

	cout << "\n4. feladat: Kodolas\n\n";
	DD.Ujrobotprg();

	cout << "\n5. feladat: DeKodolas\n\n";
	DD.Vissza();


	system("pause");
	return 0;
}