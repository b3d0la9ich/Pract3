#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Car {
    string name;
    int speed;
    double cost;
};

// Функция для вычисления эффективности машины
double calculateEfficiency(const Car& car) {
    return car.speed / car.cost;
}

int main() {
    vector<Car> cars = {
        {"BMW", 350, 140000},
        {"Mercedes", 290, 87000}, 
        {"Toyota", 330, 85000}
    };

    // Используем max_element для нахождения самой выгодной машины
    auto bestCar = max_element(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return calculateEfficiency(a) < calculateEfficiency(b);
    });

    cout << "The most efficient car is: " << bestCar->name << endl;

    return 0;
}