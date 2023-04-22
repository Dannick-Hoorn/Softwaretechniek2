#include <string>
#include <vector>
#include <iostream>
using namespace std;

void voeg_samen(vector<int>& v, const vector<int>& w);
void printvector(vector<int>& v);

int main() {
	int a1[5] = { 1,2,3,4,5 };
	int a2[5] = { 6,7,8,9,10 };
	vector<int> v(a1, a1 + 5);
	vector<int> w(a2, a2 + 5);

	voeg_samen(v, w);

	printvector(v);
}

void voeg_samen(vector<int>& v, const vector<int>& w) {
	for (auto pos = w.begin(); pos < w.end(); pos++) {
		v.push_back(*pos);
	}
}

void printvector(vector<int>& v) {
	for (auto pos = v.begin(); pos != v.end(); pos++) {
		cout << *pos << ", ";
	}
	cout << endl;
}