#include <iostream>
#include <iomanip>
using namespace std;


class Rechthoek {
private:
	int breedte;
	int hoogte;
public:
	Rechthoek(int breedte = 0, int hoogte = 0);
	void print();
};

void Rechthoek::print() {
	for (int i = 0; i < hoogte; i++) {
		for (int j = 0; j < breedte; j++) {
			if (i == 0 or i == (hoogte -1)) {
				cout << setw(1) << "X";
			}
			else if(j == 0 or j == (breedte -1)) {
				cout << setw(1) << "X";
			}
			else {
				cout << setw(1) << " ";
			}
		}
	cout << endl;
		
	}
}


Rechthoek::Rechthoek(int x, int y) {
	breedte = x;
	hoogte = y;
}

int main() {
	Rechthoek r1{ 5,3 };
	r1.print();
	Rechthoek r2{ 15,5 };
	r2.print();
}