#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Przedmiot {
    string nazwa;
    int punkty_ects;
    vector<char> oceny;
};

struct Student {
    int numer;
    string imie;
    string nazwisko;
    int semestr;
    vector<Przedmiot> przedmioty;
};

vector<Student> studenci;

void dodajStudenta() {
    Student s;
    cout << "Podaj numer indeksu: ";
    cin >> s.numer;
    cout << "Podaj imie: ";
    cin >> s.imie;
    cout << "Podaj nazwisko: ";
    cin >> s.nazwisko;
    cout << "Podaj bieżący semestr: ";
    cin >> s.semestr;

    int liczba_przedmiotow;
    cout << "Podaj liczbę przedmiotów: ";
    cin >> liczba_przedmiotow;

    for (int i = 0; i < liczba_przedmiotow; i++) {
        Przedmiot p;
        cout << "Podaj nazwę przedmiotu: ";
        cin >> p.nazwa;
        cout << "Podaj punkty ECTS: ";
        cin >> p.punkty_ects;

        int liczba_ocen;
        cout << "Podaj liczbę ocen z przedmiotu " << p.nazwa << ": ";
        cin >> liczba_ocen;

        for (int j = 0; j < liczba_ocen; j++) {
            char ocena;
            cout << "Podaj ocenę: ";
            cin >> ocena;
            p.oceny.push_back(ocena);
        }

        s.przedmioty.push_back(p);
    }

    studenci.push_back(s);
    cout << "Student dodany!" << endl;
}

void wyswietlStudenta(int numer) {
    for (int i = 0; i < studenci.size(); i++) {
        if (studenci[i].numer == numer) {
            cout << "Numer: " << studenci[i].numer << endl;
            cout << "Imie: " << studenci[i].imie << endl;
            cout << "Nazwisko: " << studenci[i].nazwisko << endl;
            cout << "Semestr: " << studenci[i].semestr << endl;
            for (int j = 0; j < studenci[i].przedmioty.size(); j++) {
                cout << "Przedmiot: " << studenci[i].przedmioty[j].nazwa << ", Punkty ECTS: " << studenci[i].przedmioty[j].punkty_ects << ", Oceny: ";
                for (int k = 0; k < studenci[i].przedmioty[j].oceny.size(); k++) {
                    cout << studenci[i].przedmioty[j].oceny[k] << " ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "Student o numerze " << numer << " nie istnieje." << endl;
}

void usunStudenta(int numer) {
    for (int i = 0; i < studenci.size(); i++) {
        if (studenci[i].numer == numer) {
            studenci.erase(studenci.begin() + i);
            cout << "Student usunięty." << endl;
            return;
        }
    }
    cout << "Student o numerze " << numer << " nie istnieje." << endl;
}

void przeniesNaKolejnySemestr(int numer) {
    for (int i = 0; i < studenci.size(); i++) {
        if (studenci[i].numer == numer) {
            if (studenci[i].semestr < 9) {
                studenci[i].semestr++;
                cout << "Student przeniesiony na semestr " << studenci[i].semestr << "." << endl;
            } else {
                cout << "Student ukończył studia." << endl;
            }
            return;
        }
    }
    cout << "Student o numerze " << numer << " nie istnieje." << endl;
}

void wyswietlSrednia(int numer) {
    for (int i = 0; i < studenci.size(); i++) {
        if (studenci[i].numer == numer) {
            double suma = 0;
            int suma_ects = 0;
            for (int j = 0; j < studenci[i].przedmioty.size(); j++) {
                for (int k = 0; k < studenci[i].przedmioty[j].oceny.size(); k++) {
                    double ocena_wartosc = 0;
                    switch (studenci[i].przedmioty[j].oceny[k]) {
                        case 'A': ocena_wartosc = 5.0; break;
                        case 'B': ocena_wartosc = 4.0; break;
                        case 'C': ocena_wartosc = 3.0; break;
                        case 'D': ocena_wartosc = 2.0; break;
                        case 'E': ocena_wartosc = 1.0; break;
                    }
                    suma += ocena_wartosc * studenci[i].przedmioty[j].punkty_ects;
                    suma_ects += studenci[i].przedmioty[j].punkty_ects;
                }
            }
            double srednia = suma_ects == 0 ? 0 : suma / suma_ects;
            cout << "Średnia studenta " << studenci[i].numer << ": " << srednia << endl;
            return;
        }
    }
    cout << "Student o numerze " << numer << " nie istnieje." << endl;
}

void wyswietlRanking() {
    cout << "Ranking studentów:" << endl;
    for (int i = 0; i < studenci.size(); i++) {
        double suma = 0;
        int suma_ects = 0;
        for (int j = 0; j < studenci[i].przedmioty.size(); j++) {
            for (int k = 0; k < studenci[i].przedmioty[j].oceny.size(); k++) {
                double ocena_wartosc = 0;
                switch (studenci[i].przedmioty[j].oceny[k]) {
                    case 'A': ocena_wartosc = 5.0; break;
                    case 'B': ocena_wartosc = 4.0; break;
                    case 'C': ocena_wartosc = 3.0; break;
                    case 'D': ocena_wartosc = 2.0; break;
                    case 'E': ocena_wartosc = 1.0; break;
                }
                suma += ocena_wartosc * studenci[i].przedmioty[j].punkty_ects;
                suma_ects += studenci[i].przedmioty[j].punkty_ects;
            }
        }
        double srednia = suma_ects == 0 ? 0 : suma / suma_ects;
        cout << "Student " << studenci[i].numer << ": " << studenci[i].imie << " " << studenci[i].nazwisko << ", Średnia: " << srednia << endl;
    }
}

int main() {
    int wybor, numer;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Dodaj studenta" << endl;
        cout << "2. Wyświetl studenta" << endl;
        cout << "3. Usuń studenta" << endl;
        cout << "4. Przenieś studenta na kolejny semestr" << endl;
        cout << "5. Wyświetl średnią studenta" << endl;
        cout << "6. Wyświetl ranking studentów" << endl;
        cout << "7. Wyjście" << endl;
        cout << "Wybierz opcję: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                dodajStudenta();
                break;
            case 2:
                cout << "Podaj numer indeksu: ";
                cin >> numer;
                wyswietlStudenta(numer);
                break;
            case 3:
                cout << "Podaj numer indeksu: ";
                cin >> numer;
                usunStudenta(numer);
                break;
            case 4:
                cout << "Podaj numer indeksu: ";
                cin >> numer;
                przeniesNaKolejnySemestr(numer);
                break;
            case 5:
                cout << "Podaj numer indeksu: ";
                cin >> numer;
                wyswietlSrednia(numer);
                break;
            case 6:
                wyswietlRanking();
                break;
            case 7:
                return 0;
            default:
                cout << "Nieprawidłowa opcja." << endl;
        }
    }

    return 0;
}
