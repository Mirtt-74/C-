/*

ROBOT PROGRAM

Tibiék iskolai szakkörön robotot építenek. Már elkészítettek egy olyan változatot, amelyik sík terepen kellõ pontossággal vezérelhetõ.
A robot a memóriájába elõre betáplált programok egyikét hajtja végre. 
A robot jelenleg csak az E, K, D, N utasításokat érti, amelyek a négy égtáj (sorrendben: észak, kelet, dél, nyugat) irányában tett 1 centiméteres elmozdulást eredményezik.
A robotba táplált programokat a robotprogram.txt állományban rögzítettük. 
Az állomány elsõ sorában a betáplált programok száma található, amely legfeljebb 100. 
Alatta soronként egy-egy program olvasható. Egy sor legfeljebb 200 karakter hosszúságú, benne az E, K, D, N karakterek, mint utasítások találhatók. A sorok nem tartalmaznak szóközt.
Például:
robotprogram.txt
12
ENNNDKENDND
ENNDDDDENDENDEEDDNNKED

A 2. sorban az elsõ betáplált program utasításai vannak. Készítsen programot, amely az alábbi kérdésekre válaszol! A program forráskódját mukodorobot néven mentse! 
Minden részfeladat megoldása elõtt írja a képernyõre a feladat sorszámát! 
Ha a felhasználótól kér be adatot, jelenítse meg a képernyõn, hogy milyen értéket vár (például 2. feladat: Kérem az utasítássor sorszámát!)!

1. Olvassa be a program.txt állományban talált adatokat, s azok felhasználásával oldja meg a következõ feladatokat! 
Ha az állományt nem tudja beolvasni, az állomány elsõ 8 sorának adatait jegyezze be a programba és dolgozzon azzal!

2. Kérje be egy utasítássor számát, majd írja a képernyõre, hogy:
a)	Egyszerûsíthetõ-e az utasítássorozat! Az egyszerûsíthetõ, illetve nem egyszerûsíthetõ választ írja a képernyõre! 
(Egy utasítássort egyszerûsíthetõnek nevezünk, ha van benne két szomszédos, ellentétes irányt kifejezõ utasításpár, hiszen ezek a párok elhagyhatók. Ilyen ellentétes utasításpár az ED, DE, KN, NK.)

b)	Az utasítássor végrehajtását követõen legkevesebb mennyi E vagy D és K vagy N utasítással lehetne a robotot a kiindulási pontba visszajuttatni! 
A választ a következõ formában jelenítse meg: 3 lépést kell tenni az ED, 4 lépést a KN tengely mentén.

c)	Annak végrehajtása során hányadik lépést követõen került (légvonalban) legtávolabb a robot a kiindulási ponttól és mekkora volt ez a távolság! 
A távolságot a lépés sorszámát követõen 4 tizedes pontossággal írja a képernyõre!

3. A robot a mozgáshoz szükséges energiát egy beépített akkuból nyeri. A robot 1 centiméternyi távolság megtételéhez 2 egység, az irányváltásokhoz és az induláshoz 3 egység energiát használ. 
Ennek alapján az EKK utasítássor végrehajtásához 12 egység energia szükséges. 
A szakkörön használt teljesen feltöltött kis kapacitású akkuból 100, a nagykapacitásúból 500 egységnyi energia nyerhetõ ki. 
Adja meg azon utasítássorokat, amelyek végrehajtásához a teljesen feltöltött kis kapacitású akku is elegendõ! 
Írja a képernyõre egymástól szóközzel elválasztva az utasítássor sorszámát és a szükséges energia mennyiségét! 
Minden érintett utasítássor külön sorba kerüljön!

4. Tibiék továbbfejlesztették az utasításokat értelmezõ programot. 
Az új, jelenleg még tesztelés alatt álló változatban a több, változatlan irányban tett elmozdulást helyettesítjük az adott irányban tett elmozdulások számával és az irány betûjével.
Tehát például a DDDDKDDD utasítássor leírható rövidített 4DK3D formában is. Az önállóan álló utasításnál az 1-es számot nem szabad kiírni! 
Hozza létre az ujrobotprog.txt állományt, amely a robotprogram.txt állományban foglalt utasítássorozatokat az új formára alakítja úgy, 
hogy az egymást követõ azonos utasításokat minden esetben a rövidített alakra cseréli! 
Az ujrobotprog.txt állományba soronként egy utasítássor kerüljön, a sorok ne tartalmazzanak szóközt!

5. Sajnos a tesztek rámutattak arra, hogy a program új verziója még nem tökéletes, ezért vissza kell térni az utasítássorok leírásának régebbi változatához. 
Mivel a szakkörösök nagyon bíztak az új változatban, ezért néhány utasítássort már csak ennek megfelelõen készítettek el. Segítsen ezeket visszaírni az eredeti formára! 
Az ismétlõdések száma legfeljebb 200 lehet! Kérjen be egy új formátumú utasítássort, majd írja a képernyõre régi formában!


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
	cout << abs(y) << " lépést kell tenni az ED, " << abs(x) << " lépést a KN tengely mentén." << endl;

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