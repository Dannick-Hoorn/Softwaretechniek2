#include<iostream>
#include <sstream>
#include <string>
using namespace std;


class tijdstip {
private:
	int uren;
	int minuten;
	int seconden;
public:
	tijdstip(int u, int m, int s) {
		uren = u;
		minuten = m;
		seconden = s;
	}
	string to_string() {
		ostringstream os;
		os << uren << ":" << minuten << ":" << seconden << endl;
		return os.str();
	}
	void volgend_uur() {
		if (uren < 23) {
			uren++;
		}
		else {
			uren = 0;
		}
	}
	void volgende_minuut() {
		if (minuten < 59) {
			minuten++;
		}
		else {
			minuten = 0;
		}
	}
	void volgende_seconde() {
		if (seconden < 59) {
			seconden++;
		}
		else {
			seconden = 0;
		}
	}
};
int main() {
	tijdstip t1{ 23,59,59 };
	cout << t1.to_string() << endl;
	t1.volgende_minuut();
	t1.volgende_seconde();
	t1.volgend_uur();
	cout << t1.to_string() << endl;
}