#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

	int getTakken() {
		return mTakken;
	}

	std::string toString() const {
		std::ostringstream os;
		os << "takken: " << mTakken << endl;
		os << "wortels: " << mWortels << endl;
		os << "bladeren: " << mBladeren << endl;
		return os.str();
	}
};

class Bos {
protected:
	vector<AppelBoom*> mBomen;
public:
	void addBomen(AppelBoom* b) {
		mBomen.push_back(b);
	}
	void printBos() {
		cout << mBomen.size() << endl;
	}
	int getTakkenBos() {
		int takkenTotaal = 0;
		for (int i = 0; i != mBomen.size(); i++) {
			takkenTotaal += mBomen[i]->getTakken();
		}
		return takkenTotaal;
	}
};


int main() {
	AppelBoom b1;
	AppelBoom b2;
	Bos bos;

	bos.addBomen(&b1);
	bos.addBomen(&b2);
	bos.printBos();

	b1.groei(40);
	b2.groei(65);
	cout << "Totaal aantal takken in bos: " << bos.getTakkenBos() << endl;
}