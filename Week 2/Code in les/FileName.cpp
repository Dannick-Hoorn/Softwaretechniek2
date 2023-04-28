/*
Deze week classes (Hoofdstuk 6)

Classes zijn zelfgemaakte datatypen, lijkt op structs (C)
*/

#include <string>
using namespace std;

class student {
	int leeftijd;
	string naam;
	
	student(int l, string n) {
		leeftijd = l;
		naam = n;
	}
};

/*
Objecten en klassen:
Zwolle is een object van klasse Stad
Douwe is een object van klasse Docent

Class bankrekening, objecten bijvoorbeeld:
-saldo
-rekeningnummer
-achternaam
*/

class Bankrekening {
private: //alleen binnen class te gebruiken
	string achternaam;
	double saldo;
public:	// ook buiten class te gebruiken
	Bankrekening(string a, double s){
		saldo = s;
		achternaam = a;
	}

	void stortBedrag(double storting) {
		saldo += storting;
	}
};




