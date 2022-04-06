#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct adatok{
	int csalad;
	int ev;
	string nev;
};

int main() {
	setlocale(LC_ALL, "hun");

	int i, j;
	int csalad_id = 0;
	int hova = 0;

	adatok adat[12];

	//fájl beolvasás

	ifstream be;
	be.open("gyerek.txt");
	if (be.fail()) {
		cout << "Hiba!";
		system("pause");
		exit(1);
	}

	while (!be.eof()) {
		hova = csalad_id * 2;
		adat[hova].csalad = csalad_id;
		adat[hova+1].csalad = csalad_id;
		be >> adat[hova].ev;
		be >> adat[hova+1].ev;
		be >> adat[hova].nev;
		be >> adat[hova+1].nev;
		csalad_id++;
	}
	be.close();

	cout << "1. feladat: fájl beolvasás\n\n";
	for (i = 0; i < 12; i++) {
		cout << "Sorszám: " << i << " Név: " << adat[i].nev << " Kor: " << adat[i].ev << endl; 
	}

	//év>10
	cout << "2. feladat: 10+ éves\n\n";
	int db_10 = 0;
	for (i = 0; i < 12; i++) {
		if (adat[i].ev > 10) db_10++;
	}
	cout << db_10 << " gyerek múlt el 10 éves." << endl << endl;

	//átlag
	cout << "3. feladat: átlag év\n\n";
	float atlag = 0;
	for (i = 0; i < 12; i++) {
		atlag = atlag + adat[i].ev;
	}
	atlag /= 12;
	cout << "Átlag életkor: " << atlag << endl << endl;

	//ikrek
	cout << "4. feladat: ikrek\n\n";
	int iker = 0;
	i = 0;
	while (i < 12 && adat[i].ev != adat[i + 1].ev) {
		i += 2;
	}
	if (i < 12) {
		cout << "Van iker." << endl << endl;
	}
	else {
		cout << "Nincs iker." << endl << endl;
	}

	//névsor
	cout << "5. feladat: névsor\n\n";
	adatok seg;
	for (i = 0; i <= 10; i++) {
		for (j = i+1; j <= 11; j++) {
			if (adat[i].nev > adat[j].nev) {
				seg = adat[i];
				adat[i] = adat[j];
				adat[j] = seg;
			}
		}
	}
	for (i = 0; i < 12; i++) {
		cout << "Sorszám: " << i << " Név: " << adat[i].nev << " Kor: " << adat[i].ev << endl;
	}


	system("pause");
	return 0;
}