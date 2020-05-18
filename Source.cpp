#include<iostream>
#include <conio.h>
#include"windows.h"
#include<fstream>

using namespace std;

#define ENDL cout << endl;
#define PAUSE  Sleep(1500);
#define Clear system("cls");

const string fileName = "WeaponProperties.txt";

class Weapon
{
private:

	float rangeOfShot;
	int caliber;
	int bulletsNumber;
	int maxBulletsNumber;	

public:

	void Initialize(float range, int _caliber, int maxSize) 
	{
		rangeOfShot = range;
		caliber = _caliber;
		maxBulletsNumber = maxSize;
		bulletsNumber = maxSize;
	}

	bool Shot() 
	{
		if (bulletsNumber==0) {			
			return 0;		
		}
		else {
			bulletsNumber--;
			return 1;
		}	
	}

	void Recharge() 
	{ 		
		bulletsNumber = maxBulletsNumber;
	}

	void Save() const
	{	
		ofstream fout;
		fout.open(fileName);
		bool isOpen = fout.is_open();
		if (isOpen == true) {
			
			fout << rangeOfShot << endl;
			fout << caliber << endl;
			fout << bulletsNumber << endl;
			fout << maxBulletsNumber << endl;
		}
		else {
			cout << "Error!" << endl;
		}
		fout.close();	
	}

	void Init() 
	{
		ifstream fin;
		fin.open(fileName); //про файли нічого не було сказано додатково, тому я вирішила, що кожного разу інформація буде перезаписуватись

		bool isOpen = fin.is_open();
		if (isOpen == true) {

			while (!fin.eof()) {				

				fin >> rangeOfShot;
				fin >> caliber;
				fin >> bulletsNumber;
				fin >> maxBulletsNumber;				
			}
		}
		else {
			cout << "Error!" << endl;
		}
		fin.close();
	}
};

int main() {

	int action = 0;	
	float range;	
	int caliber;	
	int maxBulletsNumber;

	Weapon weaponFirst;
	Weapon weaponSecond;

	do {
		Clear
			cout << "1. Initialize object " << endl;
		cout << "2. Shoot out! " << endl;
		cout << "3. Recharge the weapon " << endl;
		cout << "4. Save object to the file " << endl;	
		cout << "5. Load object from file " << endl;
		cout << "6. Exit " << endl;
		ENDL

		cout << "Enter action: ";
		cin >> action;
		ENDL
		switch (action) {

		case 1:
			
			do {
				cout << "Enter range of shot: ";
				cin >> range;
				if (range <= 0) {
					cout << "Error" << endl;
				}
			} while (range <= 0);

			do {
				cout << "Enter caliber: ";
				cin >> caliber;
				if (caliber <4) { //не розбираюсь у зброї, Гугл підказав, що калібр  не менше 4, можливо, погано шукала))
					cout << "Error" << endl;
				}
			} while (caliber <4);

			do {
				cout << "Enter maximum number of bullets in the store: ";
				cin >> maxBulletsNumber;
				if (maxBulletsNumber <= 0) {
					cout << "Error" << endl;
				}
			} while (maxBulletsNumber <= 0);

			weaponFirst.Initialize(range, caliber, maxBulletsNumber); ENDL
			cout << "Object was successfully initialized" << endl;
			PAUSE
				break;
		case 2:
			if (weaponFirst.Shot() == 0) {			
				cout << "Shop bullets is empty! Please recharge weapon!" << endl;
			}
			else {
				cout << "The shot was fired!" << endl;
			}
			PAUSE
				break;
		case 3:
			weaponFirst.Recharge();
			cout << "The weapon was successfully reloaded!" << endl;
			PAUSE
			break;
		case 4:
			weaponFirst.Save();
			cout << "Object was successfully saved!" << endl;

			PAUSE
				break;	
		case 5:
			weaponFirst.Init();
			cout << "Object was loaded." << endl;
			PAUSE
				break;
			break;
		case 6:
			break;
		default:
			cout << "Enter correct number!" << endl;
		}

	} while (action != 6);


	system("pause");
	return 0;
}