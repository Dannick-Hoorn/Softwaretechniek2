#include <string>
#include <iostream>
using namespace std;

void vervang(string& s1, char bron, char doel);

void vervang2(string& s2, char bron, char doel);

int main() {
	string s1 = "abracadabra";
	vervang(s1, 'a', 'i');
	cout << s1 << endl;
	vervang2(s1, 'i', 'e');
	cout << s1 << endl;
}

//a
void vervang(string& s1, char bron, char doel) {
	string::iterator pos;
	for (pos = s1.begin(); pos != s1.end(); pos++) {
		if (*pos == bron) {
			*pos = doel;
		}
	}
}

//b
void vervang2(string& s2, char bron, char doel) {
	string::iterator pos;
}