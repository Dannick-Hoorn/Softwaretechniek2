#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Fruit {
protected:
	double mGewicht;
	string mSoort;
public:
	virtual string to_string() const = 0;
};

class Appels : public Fruit {
public:
	Appels(double gewicht, string soort) {
		mGewicht = gewicht;
		mSoort = soort;
	}
	
	string to_string() const override{
		ostringstream os;
		os << "Soort: " << mSoort << "	Gewicht: " << mGewicht << endl;
		return os.str();
	}
};

int main() {
	Appels a1(0.192, "Granny Smith");
	Appels a2(0.145, "Pink Lady");

	cout << a1.to_string() << endl;
	cout << a2.to_string() << endl;

}


