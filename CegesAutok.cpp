#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct adatok {
	int nap;
	string ido;
	string rendszam;
	int d_id;
	int km;
	int irany;
};

struct km_ek {
	int start, stop;
	string rendszam;
};


int main() {
	setlocale(LC_ALL, "hun");

	int i=0;
	int a_db;
	adatok t[500];

	//1. Beolvasas
	ifstream be;
	be.open("autok.txt");
	if (be.fail()) {
		cout << "Hiba" << endl;
		system("pause");
		exit(1);
	}
	while (!be.eof()) {
		be >> t[i].nap;
		be >> t[i].ido;
		be >> t[i].rendszam;
		be >> t[i].d_id;
		be >> t[i].km;
		be >> t[i].irany;
		i++;
	}
	be.close();

	i--;
	a_db = i;

	//kiiras teszt
	for (i = 0; i <= a_db; i++) {
		cout << i + 1 << ". adat: " << t[i].nap << "\t" << t[i].ido << "\t" << t[i].rendszam << "\t" << t[i].d_id << "\t" << t[i].km << "\t" << t[i].irany << "\t" << endl;
	}
	cout << "\n\n";

	//2. Keresés utolsó elvitt = 0
	i = a_db;
	while (i >= 0 && t[i].irany != 0) {
		i--;
	}
	if (i >= 0) {
		cout << "Utoljára elvitt autó(" << i+1 << "): " << t[i].nap << ". nap Rendszám: " << t[i].rendszam << endl << endl;
	}
	else {
		cout << "Nem volt utoljára elvitt autó!" << endl << endl;
	}

	//3. Nap adatai
	int n;
	string iranya;
	do {
		cout << "Kérek egy napot (1..30):" << endl;
		cin >> n;
	} while (n < 1 || n > 30);
	cout << "Forgalom a(z) " << n << ". napon:" << endl;
	for (i = 0; i <= a_db; i++) {
		if (n == t[i].nap) {
			if (t[i].irany == 0) {
				iranya = "ki";
			}
			else {
				iranya = "be";
			}
			cout << t[i].ido << " " << t[i].rendszam << " " << t[i].d_id << " " << iranya << endl;
		}
	}

	//4. Hány autó nem volt bent
	cout << "\n\n4. feladat\n";
	adatok autok[10];
	int autok_p = 0;
	int j = 0;

	autok[0] = t[0];
	for (i = 1; i <= a_db; i++) {
		j = 0;
		while (j <= autok_p && autok[j].rendszam != t[i].rendszam) {
			j++;
		}
		if (j <= autok_p) {
			autok[j].irany = t[i].irany;
		}
		else {
			autok_p = j;
			autok[j] = t[i];
		}	
	}
	int nem_db = 0;
	for (j = 0; j <= autok_p; j++) {
		if (autok[j].irany == 0) {
			nem_db++;
		}
	}
	cout << "A hónap végén " << nem_db << " autót nem hoztak vissza.";

	//5. Megtett távolság
	cout << "\n\n5. feladat\n";
	km_ek k[10];
	for (j = 0; j <= autok_p; j++) {
		k[j].rendszam = autok[j].rendszam;
		k[j].start = 0;
		k[j].stop = 0;
	}
	for (i = 0; i <= a_db; i++) {
		for (j = 0; j <= autok_p; j++) {
			if (k[j].rendszam == t[i].rendszam) {
				if (k[j].start == 0) {
					k[j].start = t[i].km;
				}
				else {
					k[j].stop = t[i].km;
				}
			}
		}
	}
	int km;
	for (j = 0; j <= autok_p; j++) {
		km = k[j].stop - k[j].start;
		cout << k[j].rendszam << " " << km << " km\n";
	}

	//6. Leghosszabb út
	cout << "\n6. feladat\n";
	int max_i = 0;
	int max_ut = 0;
	int ut = 0;

	for (i = 0; i <= a_db; i++) {
		for (j = 0; j <= autok_p; j++) {
			if (k[j].rendszam == t[i].rendszam) {
				ut = t[i].km - k[j].start;
				if (ut > max_ut) {
					max_ut = ut;
					max_i = i;
				}
				k[j].start = t[i].km;
			}
		}
	}
	cout << "Leghosszabb út: " << max_ut << " km, személy: " << t[max_i].d_id << endl;

	//7. menetlevél
	cout << "\n7. feladat\n";
	int volt = 0;
	string r;
	do {
		cout << "Rendszám: ";
		cin >> r;
		volt = 0;
		for (j = 0; j <= autok_p; j++) {
			if (k[j].rendszam == r) {
				volt = 1;
			}
		}
	} while (volt == 0);

	string fajlnev;
	fajlnev = r + "_menetlevel.txt";
	cout << fajlnev << endl;

	ofstream ki(fajlnev);
	if (ki.fail()) { cout << "Fajl hiba!" << endl; system("pause"); exit(1); }

	int s = 0;
	for (i = 0; i <= a_db; i++) {

		if (r == t[i].rendszam) {
			s++;
			if (s % 2 == 1) {
				ki << t[i].d_id << "\t" << t[i].nap << ". " << t[i].ido << "\t" << t[i].km << " km\t";
				//cout << t[i].d_id << "\t" << t[i].nap << ". " << t[i].ido << "\t" << t[i].km << " km\t";
			}
			else {
				ki << t[i].nap << ". " << t[i].ido << "\t" << t[i].km << " km\t" << endl;
				//cout << t[i].nap << ". " << t[i].ido << "\t" << t[i].km << " km\t" << endl;
			}
		}
	}

	ki.close();

	cout << "\n7/b. feladat\n";
	ifstream be2;
	be2.open(fajlnev);
	if (be2.fail()) { cout << "Hiba"; system("pause"); exit(1);}
	while (getline(be2, r)) {
		cout << r << endl;
	}
	be2.close();


	system("pause");
	return 0;
}
