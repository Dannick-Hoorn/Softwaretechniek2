// Voorbeeld 13.2  Rechthoek en Driehoek
#include <iostream>
#include <string>
#include <vector>

class Figuur {
protected:
    char symbool;
public:
    Figuur(char symbool = '*') : symbool{ symbool } {
    }
    void setSymbool(char sym) {
        symbool = sym;
    }

    virtual void teken() const = 0;
};

class Rechthoek : public Figuur {
private:
    int breedte, hoogte;
public:
    Rechthoek(int breedte, int hoogte) : breedte{ breedte }, hoogte{ hoogte } {
    };
    void teken() const;
};

class Driehoek : public Figuur {
private:
    int grootte;
public:
    Driehoek(int grootte) : grootte{ grootte } {
    };
    void teken() const;
};


class Ruit : public Figuur {
private:
    int breedte;
public:
    Ruit(int grootte) : breedte{ grootte } {
    };
    void teken() const;
};

int main() {
    std::vector<Figuur*> v;

    Figuur* f = new Rechthoek{ 6, 2 };
    f->setSymbool('a');
    v.push_back(f);

    f = new Driehoek{ 5 };
    f->setSymbool('b');
    v.push_back(f);

    f = new Ruit{ 6 };
    f->setSymbool('c');
    v.push_back(f);

    auto einde = v.end();
    for (auto pos = v.begin(); pos != einde; ++pos)
        (*pos)->teken();
    std::cin.get();
}

// Implementatie
void Rechthoek::teken() const {
    // Maak een regel met symbolen, gescheiden door een spatie
    // Bijvoorbeeld:
    // * * * * * * * * *
    std::string regel;
    for (int k = 0; k < breedte; ++k) {
        regel += symbool;
        regel += ' ';
    }
    // Zet de zojuist gemaakte regels onder elkaar
    for (int r = 0; r < hoogte; ++r) {
        std::cout << regel << '\n';
    }
}
void Driehoek::teken() const {
    // Maak een regel bestaande uit een aantal spaties,
    // gevolgd door een symbool en een spatie, bijvoorbeeld:
    // _______*_    (spaties zijn hier weergegeven met _)
    std::string regel;
    for (int k = 0; k < grootte; ++k)
        regel += ' ';
    regel += symbool;
    regel += ' ';
    // Zet een aantal regels onder elkaar
    for (int r = 0; r < grootte; ++r) {
        std::cout << regel << '\n';
        // Verwijder het eerste karakter uit de regel
        regel.erase(0, 1);
        // Voeg aan het eind een symbool en een spatie toe
        regel += symbool;
        regel += ' ';
    }
}

void Ruit::teken() const {
    std::string regel;
    for (int k = 0; k < breedte; ++k) {
        regel += ' ';
    }
    regel += symbool;
    regel += ' ';

    for (int r = 0; r < breedte; ++r) {
        std::cout << regel << '\n';
        // Verwijder het eerste karakter uit de regel
        regel.erase(0, 1);
        // Voeg aan het eind een symbool en een spatie toe
        regel += symbool;
        regel += ' ';
    }
    
    for (int r = 0; r < breedte +1; ++r) {
        std::cout << regel << '\n';
        // Verwijder het eerste karakter uit de regel
        regel = ' ' + regel;
        // Voeg aan het eind een symbool en een spatie toe
        regel.erase(regel.length() - 2, 2);
    }
    
    
}
