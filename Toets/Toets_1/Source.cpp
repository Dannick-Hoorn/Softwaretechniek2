#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class AppelBoom {
protected:
	int mTakken, mWortels, mBladeren;
public:
	AppelBoom() {
		mTakken = 0;
		mWortels = 0;
		mBladeren = 0;
	}
	AppelBoom(int takken, int wortels, int bladeren) {
		mTakken = takken;
		mWortels = wortels;
		mBladeren = bladeren;
	}

	void groei(int aantal) {
		mTakken += aantal;
		mWortels += aantal;
	}

	void bladGroei() {
		mBladeren += (mTakken * 100);
	}

	void snoei(int aantal) {
		mTakken -= aantal;
		mBladeren -= (aantal * 100);
	}

	std::string toString() const {
		std::ostringstream os;
		os << "takken: " << mTakken << endl;
		os << "wortels: " << mWortels << endl;
		os << "bladeren: " << mBladeren << endl;
		return os.str();
	}
};

int main() {
	AppelBoom a;
	cout << a.toString() << "\n";

	a.groei(10);
	a.bladGroei();
	a.snoei(2);

	cout << a.toString() << "\n";
}