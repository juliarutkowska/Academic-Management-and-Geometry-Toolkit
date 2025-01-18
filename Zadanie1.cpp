#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// Struktura reprezentująca punkt
struct Punkt {
    double x, y;

    // Konstruktor
    Punkt(double wspX, double wspY) : x(wspX), y(wspY) {}

    // Metoda toString (prosta wersja)
    string toString() const {
        // Proste połączenie łańcuchów znaków
        return "{ x: " + to_string(x) + ", y: " + to_string(y) + " }";
    }
};

// Funkcja do obliczania odległości między dwoma punktami
double obliczOdleglosc(const Punkt& p1, const Punkt& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Funkcja sprawdzająca, czy trzy punkty tworzą trójkąt
bool czyTrojkat(const Punkt& p1, const Punkt& p2, const Punkt& p3) {
    // Obliczamy długości boków
    double a = obliczOdleglosc(p1, p2);
    double b = obliczOdleglosc(p2, p3);
    double c = obliczOdleglosc(p1, p3);

    // Sprawdzamy warunek istnienia trójkąta (trójkąt istnieje, jeśli suma długości dwóch boków jest większa od trzeciego)
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Funkcja zwracająca najbardziej oddalone punkty z tablicy
pair<Punkt, Punkt> znajdzNajbardziejOddalonePunkty(const vector<Punkt>& punkty) {
    double maksymalnaOdleglosc = 0.0;
    pair<Punkt, Punkt> najbardziejOddalone = { punkty[0], punkty[0] };

    for (size_t i = 0; i < punkty.size(); ++i) {
        for (size_t j = i + 1; j < punkty.size(); ++j) {
            double odleglosc = obliczOdleglosc(punkty[i], punkty[j]);
            if (odleglosc > maksymalnaOdleglosc) {
                maksymalnaOdleglosc = odleglosc;
                najbardziejOddalone = { punkty[i], punkty[j] };
            }
        }
    }

    return najbardziejOddalone;
}

// Przykład użycia
int main() {
    // Tworzenie punktów
    Punkt p1(0, 0), p2(3, 4), p3(6, 8), p4(10, 10);

    // Wyświetlenie punktów
    cout << "Punkt 1: " << p1.toString() << "\n";
    cout << "Punkt 2: " << p2.toString() << "\n";
    cout << "Punkt 3: " << p3.toString() << "\n";

    // Obliczenie odległości
    cout << "Odległość między p1 a p2: " << obliczOdleglosc(p1, p2) << "\n";

    // Sprawdzenie, czy punkty tworzą trójkąt
    if (czyTrojkat(p1, p2, p3)) {
        cout << "Punkty tworzą trójkąt.\n";
    }
    else {
        cout << "Punkty nie tworzą trójkąta.\n";
    }

    // Znalezienie najbardziej oddalonych punktów
    vector<Punkt> punkty = { p1, p2, p3, p4 };
    pair<Punkt, Punkt> najbardziejOddalone = znajdzNajbardziejOddalonePunkty(punkty);
    Punkt punktA = najbardziejOddalone.first;
    Punkt punktB = najbardziejOddalone.second;
    cout << "Najbardziej oddalone punkty to: " << punktA.toString() << " i " << punktB.toString()
        << ", odległość: " << obliczOdleglosc(punktA, punktB) << "\n";

    return 0;
}
