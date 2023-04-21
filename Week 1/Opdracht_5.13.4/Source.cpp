#include <string>
#include <vector>
#include <iostream>
using namespace std;

int som(vector<int>& v);

int main() {
	int a[5] = { 1,2,3,4,5 };
	vector<int> vi(a, a + 5);
	cout << som(vi) << endl;

}

int som(vector<int>& v) {
	int result = 0;
	for (auto pos = v.begin(); pos != v.end(); ++pos) {
		result += *pos;
	}
	return result;
}
