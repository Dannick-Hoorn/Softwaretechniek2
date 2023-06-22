#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Fruit {
protected:
    double mGewicht;
    string mSoort;
public:
    virtual string to_string() const = 0;
};

class Appels : public Fruit {
public:
    Appels(double gewicht, string soort) {
        mGewicht = gewicht;
        mSoort = soort;
    }

    string to_string() const override {
        ostringstream os;
		os << "Soort: " << mSoort << "	Gewicht: " << mGewicht << endl;
        return os.str();
    }
};

class AppelBoom {
protected:
    int mTakken, mWortels, mBladeren;
    vector<Appels> mAppel;
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

    void addFruit(Appels a) {
        mAppel.push_back(a);
    }

    void printFruit() {
        for (int i = 0; i != mAppel.size(); i++) {
            cout << mAppel[i].to_string() << endl;
        }
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
    AppelBoom b1(10, 10, 100);
    Appels a1(0.155, "Granny Smith");
    Appels a2(0.163, "Pink Lady");

    b1.addFruit(a1);
    b1.addFruit(a2);

    b1.printFruit();
}
