#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "hun");

	int t[2000];
	int i = 0;
	int t_db = 0;
	int tav_be = 0;

	int maxm = 0;

	//1. feladat beolvas, megszamol
	ifstream be("melyseg.txt");
	if (be.fail()) {
		cout << "Hiba!";
		system("pause");
		exit(1);
	}
	while (!be.eof()) {
		be >> t[i];

		if (t[i] > t[maxm]) maxm = i;

		i++;
	}
	i = i--;
	t_db = i;
	be.close();

	cout << "Maxmélység: " << maxm + 1 << " méterre, és " << t[maxm] << " méter mély.\n\n";

	cout << "1.feladat\n";
	cout << "Adatok száma: " << t_db+1 << "\n\n";

	//2.feladat beker, kiir
	cout << "2.feladat\n";
	do {
		cout << "Kérek egy távolságot(1.." << t_db + 1 << "): ";
		cin >> tav_be;
	} while (tav_be<1 || tav_be>t_db);
	cout << "Mélység: " << t[tav_be - 1] << "\n\n";

	//3.feladat ?% érintetlen
	cout << "3.feladat\n";
	int c_0 = 0;
	for (i = 0; i <= t_db; i++) {
		if (t[i] == 0) c_0++;
	}
	cout << "Érintetlen terület: " << fixed << setprecision(2) << (float(c_0) / (t_db + 1))*100 << "%.\n\n";

	//4. gödrök fájlba
	cout << "4.feladat\n\n";
	int sor = 0;
	ofstream ki("godrok.txt");
	for (i = 1; i <= t_db; i++) {
		if (t[i] > 0) {
			ki << t[i] << " ";
		}
		if (t[i] == 0 && t[i-1] > 0) {
			sor++;
			ki << "\n";
		}
	}
	ki.close();

	//5. gödrök száma
	cout << "5.feladat\n";
	cout << "Gödrök száma: " << sor << "\n\n";

	//6. 
	cout << "6.feladat\n";
	if (t[tav_be - 1] == 0) {
		cout << "Az adott helyen nincs gödör.\n";
	}
	else {
		int kezd, veg;
		i = tav_be - 1;
		while (i > 0 && t[i] != 0) {
			i--;
		}
		kezd = ++i;
		i = tav_be - 1;
		while (i <= t_db && t[i] != 0) {
			i++;
		}
		veg = --i;
		cout << "a)\n" << "Kezdo: " << kezd + 1 << " m, vége: " << veg + 1 << " m.\n\n";

		cout << "b)\n";
		int cs = 0;
		int volt = 0;
		int max_mely = t[kezd];
		int terfogat = 0;
		int terfogat2 = 0;
		for (i = kezd; i <= veg; i++) {
			if (t[i - 1] > t[i]) cs = 0;
			if (t[i - 1] < t[i] && volt == 0) {
				volt = 1;
				cs = 1;
			}
			if (max_mely < t[i]) max_mely = t[i];
			terfogat = terfogat + t[i];
			if(t[i]>1) terfogat2 = terfogat2 + t[i]-1;
		}
		if (cs == 0 && volt == 1) {
			cout << "Nem mélyül folyamatosan.\n";
		}
		else if (cs == 1 && volt == 1) {
			cout << "Folyamatosan mélyül.\n";
		}

		cout << "c)\n";
		cout << "Maxmélység: " << max_mely << " méter.\n\n";

		cout << "d)\n";
		cout << "Térfogata: " << terfogat*10 << " m^3.\n\n";

		cout << "e)\n";
		cout << "Vízmennyiség: " << terfogat2 * 10 << " m^3.\n\n";

	}


	for (i = 0; i <= t_db; i++) {

	}

	system("pause");
	return 0;
}