#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string director;
    string title;
    string studio;
    int year;
    int duration; // продолжительность в минутах

public:
    // Конструктор
    Movie(const string& d, const string& t, const string& s, int y, int dur)
        : director(d), title(t), studio(s), year(y), duration(dur) {}

    // Геттеры
    string getDirector() const { return director; }
    string getTitle() const { return title; }
    string getStudio() const { return studio; }
    int getYear() const { return year; }
    int getDuration() const { return duration; }

    // Метод для отображения информации о фильме
    void displayInfo() const {
        cout << "Director: " << director << endl;
        cout << "Title: " << title << endl;
        cout << "Studio: " << studio << endl;
        cout << "Year: " << year << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "------------------------------" << endl;
    }

    // Метод для проверки, был ли фильм выпущен после указанного года
    bool releasedAfter(int targetYear) const {
        return year > targetYear;
    }

    // Метод для проверки совпадения режиссера
    bool hasDirector(const string& targetDirector) const {
        return director == targetDirector;
    }

    // Метод для проверки совпадения студии
    bool hasStudio(const string& targetStudio) const {
        return studio == targetStudio;
    }
};

int main() {
    Movie library[5] = {
        Movie("Steven Spielberg", "Jurassic Park", "Universal Pictures", 1993, 127),
        Movie("James Cameron", "Avatar", "20th Century Fox", 2009, 162),
        Movie("Christopher Nolan", "Inception", "Warner Bros.", 2010, 148),
        Movie("Ridley Scott", "Gladiator", "DreamWorks", 2000, 155),
        Movie("Peter Jackson", "The Lord of the Rings: The Fellowship of the Ring", "New Line Cinema", 2001, 178)
    };

    string directorQuery, studioQuery;
    int yearQuery;

    cout << "Enter director's name: ";
    cin >> directorQuery;

    cout << "Movies by " << directorQuery << ":" << endl;
    for (const auto& movie : library) {
        if (movie.hasDirector(directorQuery)) {
            movie.displayInfo();
        }
    }

    cout << "\nEnter studio's name: ";
    cin >> studioQuery;

    cout << "Movies produced by " << studioQuery << ":" << endl;
    for (const auto& movie : library) {
        if (movie.hasStudio(studioQuery)) {
            movie.displayInfo();
        }
    }

    cout << "\nEnter year: ";
    cin >> yearQuery;

    cout << "Movies released after " << yearQuery << ":" << endl;
    for (const auto& movie : library) {
        if (movie.releasedAfter(yearQuery)) {
            movie.displayInfo();
        }
    }

    return 0;
}
