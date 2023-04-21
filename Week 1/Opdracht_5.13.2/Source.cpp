#include <string>
#include <vector>
#include <iostream>
using namespace std;

string voeg_samen(const vector<string>& v);

int main() {
	string arr[]{ "aap", "beer", "cobra" };
	vector<string> vs(arr, arr + 3);
	cout << voeg_samen(vs) << '.';
}

string voeg_samen(const vector<string>& v) {
	string result;
	for (int i = 0; i < v.size(); i++) {
		result += v[i];
		if (i != v.size() - 1) {
			result += "-";
		}
	}
	return result;
}