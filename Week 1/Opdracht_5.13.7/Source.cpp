#include <string>
#include <vector>
#include <iostream>
using namespace std;

void convert(int jaartal);

int main() {
	int jaartal = 1941;

	convert(jaartal);
}

void convert(int jaartal) {
	string letters[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int aantal [13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

	for (int i = 0; i < 13; i++) {
		while (jaartal >= aantal[i]) {
			cout << letters[i];
			jaartal -= aantal[i];
		}
	}
}