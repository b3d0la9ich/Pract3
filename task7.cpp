#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для представления ученика
struct Student {
    string name;
    vector<int> grades;

    // Функция для вычисления среднего балла
    double averageGrade() const {
        if (grades.empty()) return 0.0;
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }
};

// Функция для сравнения учеников по среднему баллу
bool compareByAverageGrade(const Student &a, const Student &b) {
    return a.averageGrade() > b.averageGrade();
}

int main() {
    // Создание вектора учеников
    vector<Student> students = {
        {"Masha", {2, 3, 4, 5}},
        {"Ivan", {5, 5, 4, 5}},
        {"Nikita", {2, 5, 3, 2}}
    };

    // Замена оценок 5 на 2 и 2 на 5 для каждого ученика
    for (auto &student : students) {
        for (int &grade : student.grades) {
            if (grade == 5) {
                grade = 2;
            } else if (grade == 2) {
                grade = 5;
            }
        }
    }

    // Сортировка учеников по среднему баллу
    sort(students.begin(), students.end(), compareByAverageGrade);

    // Вывод рейтинга по среднему баллу
    cout << "Рейтинг учеников по среднему баллу:" << endl;
    for (const auto &student : students) {
        cout << student.name << ": " << student.averageGrade() << endl;
    }

    return 0;
}
