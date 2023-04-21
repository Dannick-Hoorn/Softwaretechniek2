#include <string>
#include <vector>
#include <iostream>
using namespace std;

void keerom(vector<int>& v);
void printvector(vector<int>& v);

int main() {
	int a[5] = { 1,2,3,4,5 };
	vector<int> vi(a, a + 5);
	
	printvector(vi);
	keerom(vi);
	printvector(vi);
}

void keerom(vector<int>& v) {
	auto eerste = v.begin();
	auto laatste = v.end() - 1;

	while (eerste < laatste) {
		auto temp = *eerste;
		*eerste = *laatste;
		*laatste = temp;
		eerste++;
		laatste--;
	}
}

void printvector(vector<int>& v) {
	for (auto pos = v.begin(); pos != v.end(); pos++) {
		cout << *pos << ", ";
	}
	cout << endl;
}