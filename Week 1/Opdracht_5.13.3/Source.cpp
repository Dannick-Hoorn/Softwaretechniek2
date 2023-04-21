#include <string>
#include <vector>
#include <iostream>
using namespace std;

void verdubbel(vector<int>& v);
void printvector(vector<int>& v);

int main() {
	int a[5] = { 1,2,3,4,5 };
	vector<int> vi(a, a+5);
	printvector(vi);
	verdubbel(vi);
	printvector(vi);
	}

void verdubbel(vector<int>& v) {
	for (auto pos = v.begin(); pos != v.end(); ++pos) {
		*pos = *pos * 2;
	}
}

void printvector(vector<int>& v) {
	for (int i = 0; i != v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}