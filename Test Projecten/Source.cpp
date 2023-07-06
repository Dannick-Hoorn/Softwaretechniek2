#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Rijder
{
private:
	string Naam;
	int Nummer;
	double Tijd; //in seconden

public:
	Rijder(string Naam, int Num, double Tijd) : Naam{ Naam }, Nummer{ Num }, Tijd{ Tijd } {

	};

	double getTijd(){
		return Tijd;
	}

	int getNR() {
		return Nummer;
	}

	string getNaam() {
		return Naam;
	}

	void setNR(int NewNR) {
		Nummer = NewNR;
	}

	void setTijd(double NewTijd) {
		Tijd = NewTijd;
	}

	void setNaam(string NewNaam) {
		Naam = NewNaam;
	}

	string to_string() {
		ostringstream os;
		os << "Naam: " << Naam << " Nummer: " << Nummer << " Tijd: " << Tijd << endl;
		return os.str();
	}
};

class Startlijst {
private:
	string Categorie;
	vector<Rijder> mRijders;
public:
	Startlijst(string Cat) : Categorie{ Cat } {
	};

	void addRijder(Rijder R1) {
		mRijders.push_back(R1);
	}

	void sortNaam() {
		string Naam1 = "";
		string Naam2 = "";
		
		char startLetter1 = ' ';
		char startLetter2 = ' ';
		for (int j = 0; j != mRijders.size() - 1; j++) {//geneste for loop om sorteren vaak genoeg te laten gebeuren
			for (int i = 0; i != mRijders.size() - 1; i++) {
				Naam1 = mRijders[i].getNaam();
				startLetter1 = Naam1.at(0);
				Naam2 = mRijders[i + 1].getNaam();
				startLetter2 = Naam2.at(0);
				if (startLetter2 < startLetter1) {
					Rijder temp1 = mRijders[i];
					mRijders[i] = mRijders[i + 1];
					mRijders[i + 1] = temp1;
				}
			}
		}
	}

	void sortNum() {
		for (int j = 0; j != mRijders.size() - 1; j++) {//geneste for loop om sorteren vaak genoeg te laten gebeuren
			for (int i = 0; i != mRijders.size() - 1; i++) {
				if (mRijders[i+1].getNR() < mRijders[i].getNR()) {
					Rijder temp1 = mRijders[i];
					mRijders[i] = mRijders[i + 1];
					mRijders[i + 1] = temp1;
				}
			}
		}
	}

	void sortTijd() {
		for (int j = 0; j != mRijders.size() - 1; j++) {//geneste for loop om sorteren vaak genoeg te laten gebeuren
			for (int i = 0; i != mRijders.size() - 1; i++) {
				if (mRijders[i + 1].getTijd() < mRijders[i].getTijd()) {
					Rijder temp1 = mRijders[i];
					mRijders[i] = mRijders[i + 1];
					mRijders[i + 1] = temp1;
				}
			}
		}
	}

	string to_string() {
		ostringstream os;
		for (int i = 0; i != mRijders.size(); i++) {
			os << "Naam: " << mRijders[i].getNaam() << '\t' << " Nummer: " << mRijders[i].getNR() << '\t' << " Tijd: " << mRijders[i].getTijd() << endl;
		}
		return os.str();
	}
};

int main() {
	Rijder Rijder1("Dannick", 69, 42.06);
	Rijder Rijder2("Marissa", 21, 38.25);
	Rijder Rijder3("Hilco", 40, 45.04);
	Rijder Rijder4("Adriaan", 35, 48.69);
	Startlijst Start1("Licht");
	Start1.addRijder(Rijder1);
	Start1.addRijder(Rijder2);
	Start1.addRijder(Rijder3);
	Start1.addRijder(Rijder4);

	cout << Start1.to_string() << endl;

	Start1.sortNaam();

	cout << Start1.to_string() << endl;

	Start1.sortTijd();

	cout << Start1.to_string() << endl;

	Start1.sortNum();

	cout << Start1.to_string();


};

