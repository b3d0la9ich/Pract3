#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Charger {
    string name;
    double current; // Ток заряда в А
    Charger(const string& n, double c) : name(n), current(c) {}
};

pair<string, double> findBestCharger(const vector<Charger>& chargers, int phoneCapacity) {
    auto compareChargeTime = [=](const Charger& charger1, const Charger& charger2) {
        // Вычисляем время зарядки для каждой зарядки (в часах)
        double time1 = static_cast<double>(phoneCapacity) / (charger1.current * 1000);
        double time2 = static_cast<double>(phoneCapacity) / (charger2.current * 1000);
        // Сравниваем время зарядки
        return time1 < time2;
    };

    auto bestCharger = min_element(chargers.begin(), chargers.end(), compareChargeTime);

    double chargingTime = static_cast<double>(phoneCapacity) / (bestCharger->current * 1000);

    return make_pair(bestCharger->name, chargingTime);
}

int main() {
    vector<Charger> chargers = {
        {"Зарядка 1", 1},
        {"Зарядка 2", 1.5},
        {"Зарядка 3", 2}
    };

    int phoneCapacity = 5020; // емкость телефона в мАч

    pair<string, double> bestChargerInfo = findBestCharger(chargers, phoneCapacity);

    cout << "Наилучшая зарядка: " << bestChargerInfo.first << endl;
    cout << "Время зарядки: " << bestChargerInfo.second << " часа(ов)" << endl;

    return 0;
}