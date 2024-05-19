#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int exam1;
    int exam2;
    int exam3;
};

// Функция для проверки критериев по баллам
bool checkCriteria(const Student& student) {
    return (student.exam1 >= 40 && student.exam2 >= 50 && student.exam3 >= 44);
}

// Функция для вычисления суммарного балла студента
int totalScore(const Student& student) {
    return student.exam1 + student.exam2 + student.exam3;
}

int main() {
    // Создаем список студентов
    list<Student> students = {
        {"Student1", 45, 55, 47},
        {"Student2", 30, 60, 50},
        {"Student3", 50, 40, 45},
        {"Student4", 70, 80, 90}
    };

    // Используем алгоритмы для решения задачи
    auto it = partition(students.begin(), students.end(), checkCriteria);

    // Вычисляем суммарный балл для студентов, прошедших критерии
    for (auto i = students.begin(); i != it; ++i) {
        int total = totalScore(*i);
        if (total > 215) {
            cout << i->name << " you are welcome!" << endl;
        } else {
            cout << i->name << " с вас 160 тыщ!" << endl;
        }
    }

    return 0;
}