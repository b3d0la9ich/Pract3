#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    string firstName;
    string lastName;
    int birthYear;
};

bool isAdult(int birthYear) {
    int currentYear = 2024;
    return (currentYear - birthYear) >= 18;
}

void checkAccess(const Person& person) {
    if (isAdult(person.birthYear)) {
        cout << person.firstName << " " << person.lastName << ": доступ разрешен" << endl;
    } else {
        cout << person.firstName << " " << person.lastName << ": иди учи уроки!" << endl;
    }
}

int main() {
    vector<Person> people = {
        {"John", "Doe", 2005},
        {"Jane", "Smith", 2000},
        {"Alice", "Johnson", 2010}
    };

    // Используем std::for_each для итерации по списку людей
    for_each(people.begin(), people.end(), checkAccess);

    return 0;
}