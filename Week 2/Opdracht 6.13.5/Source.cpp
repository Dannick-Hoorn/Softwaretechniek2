class Teller {
private:
	int waarde = 0;
public:
	Teller(int w) {
		waarde = w;
	}
	void verhoog() {
		waarde++;
	}
	void verlaag() {
		waarde--;
	}
	int get_Teller(){
		return waarde;
	}
	int set_Teller(int n) {
		waarde = n;
	}
};