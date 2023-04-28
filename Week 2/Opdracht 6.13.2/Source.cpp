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
	
};
int main() {
	tijdstip t1{ 15,41,53 };
	cout << t1.to_string() << endl;
}