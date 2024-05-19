#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name; 
    string city;
    int exam1;
    int exam2;
    int exam3;
};

bool isEligible(const Student& student) { // если все оценки не ниже 4
    return all_of(begin({student.exam1, student.exam2, student.exam3}), end({student.exam1, student.exam2, student.exam3}), [](int grade) { return grade >= 4; });
}

bool hasGrade3(const Student& student) { // если хотя бы одна 3
    return any_of(begin({student.exam1, student.exam2, student.exam3}), end({student.exam1, student.exam2, student.exam3}), [](int grade) { return grade == 3; });
}

bool sortByAverage(const Student& a, const Student& b) {
    int avgA = (a.exam1 + a.exam2 + a.exam3) / 3;
    int avgB = (b.exam1 + b.exam2 + b.exam3) / 3;
    return avgA > avgB;
}

int main() {
    vector<Student> students = {
        {"Alice", "Искитим", 4, 5, 4},
        {"Bob", "Бердск", 3, 5, 4},
        {"Nikita", "Новосибирск", 4, 4, 5},
        {"David", "Искитим", 5, 5, 5}
    };

    vector<Student> eligibleStudents; // оценки не ниже 4
    vector<Student> studentsWithGrade3; // хотя бы одна 3
    vector<Student> studentsNotFromIskitimWithoutGrade3; // нет троек но не из Искитима

    // Фильтрация студентов, которые подходят по оценкам
    copy_if(students.begin(), students.end(), back_inserter(eligibleStudents), isEligible);

    // Фильтрация студентов, у которых есть хотя бы одна тройка
    copy_if(students.begin(), students.end(), back_inserter(studentsWithGrade3), hasGrade3);

    // Фильтрация студентов, у которых нет троек, и которые не из Искитима
    copy_if(students.begin(), students.end(), back_inserter(studentsNotFromIskitimWithoutGrade3), [](const Student& student) {
        return !hasGrade3(student) && student.city != "Искитим";
    });

    // Сортировка студентов по среднему баллу
    sort(eligibleStudents.begin(), eligibleStudents.end(), sortByAverage);

    // Выбор студента из Искитима с наивысшим средним баллом и вывод его имени
    auto it = find_if(eligibleStudents.begin(), eligibleStudents.end(), [](const Student& student) {
        return student.city == "Искитим";
    });

    // Вывод студентов, у которых нет троек и они с Искитима
    cout << "Student from Iskitim with highest average score: " << it->name << " - " << it->exam1 << " " << it->exam2 << " " << it->exam3 << endl;

    // Вывод студентов, у которых есть хотя бы одна тройка
    cout << "Students with at least one grade of 3:" << endl;
    for (const auto& student : studentsWithGrade3) {
        cout << student.name << endl;
    }

    // Вывод студентов без троек, но не из Искитима
    cout << "Students not from Iskitim without grade 3:" << endl;
    for (const auto& student : studentsNotFromIskitimWithoutGrade3) {
        cout << student.name << endl;
    }

    return 0;
}