#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Opdracht 1 oefentoets
/*
int inproduct(vector<int> u,vector<int> v) {
	int product = 0;

	while (u.size() > v.size()) {
		v.push_back(0);
	}

	while (v.size() > u.size()) {
		u.push_back(0);
	}


	if (u.size() == v.size()) {
		for (int i = 0; i != u.size(); i++) {
			product += u[i] * v[i];
		}
	}
	return product;
}

int main()
{
	vector<int> x = { 1,2,3,4, 6, 7};
	vector<int> y = { 4,3,2,1, 1};
	cout << "inproduct = " << inproduct(x, y);
	cin.get();
}
*/

//Opdracht 2 oefentoets
/*
class Punt {
private:
	int xCoord, yCoord;
public:
	Punt(int x, int y): xCoord(x), yCoord(y) {
		x = xCoord;
		y = yCoord;
	}
	void zetCoordinaten(int x, int y) {
		xCoord = x;
		yCoord = y;
	}

	int getXCoord() {
		return xCoord;
	}

	int getYCoord() {
		return yCoord;
	}
};

class GrafischObject {
private:
	Punt middelpunt;
	string kleur;
public:
	GrafischObject(Punt m, string k) : middelpunt(m), kleur(k) {
		m = middelpunt;
		k = kleur;
	}

	void zetMiddelpunt(Punt p){
		middelpunt = p;
	}

	void print() {
		cout << "Grafisch object met middelpuntX = " << middelpunt.getXCoord() << ", middelpuntY = " << middelpunt.getYCoord() << " met de kleur " << kleur << endl;
	}
};

int main() {
	Punt coolpunt(10, 20);
	GrafischObject object(coolpunt, "Rood");
	object.print();

	coolpunt.zetCoordinaten(50, 80);
	object.zetMiddelpunt(coolpunt);
	object.print();
}
*/

//Opdracht 3

class Punt {
protected:
	int xCoord, yCoord;
public:
	Punt(int x, int y) : xCoord(x), yCoord(y) {
		x = xCoord;
		y = yCoord;
	}
	void zetCoordinaten(int x, int y) {
		xCoord = x;
		yCoord = y;
	}

	int getXCoord() {
		return xCoord;
	}

	int getYCoord() {
		return yCoord;
	}
};

class GrafischObject {
protected:
	Punt middelpunt;
	string kleur;
public:
	GrafischObject(Punt m, string k) : middelpunt(m), kleur(k) {
		m = middelpunt;
		k = kleur;
	}

	void zetMiddelpunt(Punt p) {
		middelpunt = p;
	}

	void print() {
		cout << "Grafisch object met middelpuntX = " << middelpunt.getXCoord() << ", middelpuntY = " << middelpunt.getYCoord() << " met de kleur " << kleur << endl;
	}
};

class Rechthoek : public GrafischObject {
protected:
	int l, b;
public:
	Rechthoek(Punt m, string k, int lengte, int breedte) : GrafischObject(m, k), l(lengte), b(breedte) {

	}

	Punt geefLinksBoven() {
		int LBY = middelpunt.getYCoord() + l / 2;
		int LBX = middelpunt.getXCoord() - b / 2;
		Punt LB(LBX, LBY);
		return LB;
	}
	Punt geefRechtsBoven() {
		int RBY = middelpunt.getYCoord() + l / 2;
		int RBX = middelpunt.getXCoord() + b / 2;
		Punt RB(RBX, RBY);
		return RB;
	}
	Punt geefLinksOnder() {
		int LOY = middelpunt.getYCoord() - l / 2;
		int LOX = middelpunt.getXCoord() - b / 2;
		Punt LO(LOX, LOY);
		return LO;
	}
	Punt geefRechtsOnder() {
		int ROY = middelpunt.getYCoord() - l / 2;
		int ROX = middelpunt.getXCoord() + b / 2;
		Punt RO(ROX, ROY);
		return RO;
	}
};


int main() {
	Punt coolpunt(10, 20);
	GrafischObject object(coolpunt, "Rood");
	object.print();

	coolpunt.zetCoordinaten(50, 80);
	object.zetMiddelpunt(coolpunt);
	object.print();
	
	Rechthoek rechthoek1 (coolpunt, "Blauw", 5, 7);
	Punt LinksBoven1 = rechthoek1.geefLinksBoven();
	cout << LinksBoven1.getXCoord() << ", " << LinksBoven1.getYCoord() << endl;
}