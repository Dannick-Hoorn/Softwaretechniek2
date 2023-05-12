// Voorbeeld 7.2 Team van willekeurig veel studenten
// Vector met pointers naar Student
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

class Datum {
private:
    int dag, maand, jaar;

public:
    Datum(int dag, int maand, int jaar)
        : dag{ dag }, maand{ maand }, jaar{ jaar } {
    }

    std::string to_string() const {
        std::ostringstream os;
        os << std::setfill('0') << std::setw(2) << dag << '-'
            << std::setw(2) << maand << '-' << std::setw(4) << jaar;
        return os.str();
    }
};

class Student {
private:
    std::string naam, opleiding, geslacht;
    int nummer;
    Datum gebdat;

public:
    Student(std::string n, std::string opl, std::string gesl, int nr, const Datum& gbd)
        : naam{ n }, opleiding{ opl }, geslacht{ gesl }, nummer{ nr }, gebdat{ gbd } {
    }

    void setNaam(std::string n) {
        naam = n;
    }

    std::string to_string() const {
        std::ostringstream os;
        os << naam << " (" << gebdat.to_string() << "), ";
        os << opleiding << ", (";
        os << geslacht << "), ";
        os << nummer << '\n';
        return os.str();
    }
};

class Team {
private:
    std::string sport;
    std::vector<const Student*> teamleden;
    std::string naam;

public:
    Team(std::string sport, std::string naam) : sport{ sport }, naam{ naam } {
    }

    void voegToe(const Student* lid) {
        teamleden.push_back(lid);
    }

    std::string to_string() const {
        std::ostringstream os;

        os << "Het team '" << sport << "', met naam '" << naam << "' bestaat uit : " << '\n';
        for (auto pos = teamleden.begin(); pos != teamleden.end(); ++pos)
            os << (**pos).to_string() << '\n';
        return os.str();
    }

    std::string printnaam() const {
        std::ostringstream os;
        os << naam;
        return os.str();
    }
};

class Wedstrijd {
private:
    Team team1, team2;
    Datum wedDat;
    std::string uitslag;
public:
    Wedstrijd(Team& team1, Team& team2, Datum& wedDat, std::string uitslag) : team1{ team1 }, team2{ team2 }, wedDat{ wedDat }, uitslag{ uitslag } {

    }

    std::string to_string() const{
        std::ostringstream os;
        os << team1.printnaam() << " speelde tegen " << team2.printnaam() << " op " << wedDat.to_string() << ", de uitslag is " << uitslag << '\n';
        return os.str();

    }
};

int main() {
    Student student1{ "Elena", "wiskunde", "v", 201053, Datum{13, 5, 1990} },
        student2{ "Lucia", "Engels", "v", 227756, Datum{16, 4, 1991} },
        student3{ "Jeannette", "muziek", "v", 233475, Datum{29, 7, 1989} },
        student4{ "Menno", "informatica", "m", 212364, Datum{6, 3, 1992} };

    Team team1{ "roeien" , "HippeMensen"};
    team1.voegToe(&student1);
    team1.voegToe(&student2);
    Team team2{ "roeien", "CooleMensen" };
    team2.voegToe(&student3);
    team2.voegToe(&student4);

    Datum wedDat1{ 8,7,2023 };
    
    Wedstrijd wed1{ team1, team2, wedDat1, "1-0" };
    std::cout << wed1.to_string();
}
