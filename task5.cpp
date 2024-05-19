#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для представления автомобиля
struct Car {
    string name;
    int speed; // скорость в км/ч

    // Конструктор для удобного создания объектов Car
    Car(string n, int s) : name(n), speed(s) {}
};

// Функция для вывода списка автомобилей
void printCars(const vector<Car>& cars) {
    for (const auto& car : cars) {
        cout << car.name << " - " << car.speed << " км/ч" << endl;
    }
}

int main() {
    // Список автомобилей Mercedes
    vector<Car> mercedesCars = {
        Car("Mercedes A-Class", 240),
        Car("Mercedes C-Class", 250),
        Car("Mercedes E-Class", 270)
    };

    // Список автомобилей BMW
    vector<Car> bmwCars = {
        Car("BMW 3 Series", 250),
        Car("BMW 5 Series", 260),
        Car("BMW 7 Series", 280)
    };

    // Объединение двух списков в один
    vector<Car> mergedCars;
    mergedCars.reserve(mercedesCars.size() + bmwCars.size()); // Зарезервируем память
    mergedCars.insert(mergedCars.end(), mercedesCars.begin(), mercedesCars.end());
    mergedCars.insert(mergedCars.end(), bmwCars.begin(), bmwCars.end());

    // Сортировка объединённого списка по убыванию скорости
    sort(mergedCars.begin(), mergedCars.end(), [](const Car& a, const Car& b) {
        return a.speed > b.speed;
    });

    // Вывод результата
    cout << "Объединенный список автомобилей (от самой быстрой до самой медленной):" << endl;
    printCars(mergedCars);

    return 0;
}
