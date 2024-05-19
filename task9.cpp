#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BasketballPlayer {
    string name;
    double arm_span_height; // Рост человека с поднятыми вверх руками
    double vertical_jump;
};

// Функция для определения, может ли игрок допрыгнуть до кольца
bool canReachRing(const BasketballPlayer& player) {
    return (player.arm_span_height + player.vertical_jump) >= 3.5;
}

int main() {
    // Создаем вектор с информацией о баскетболистах
    vector<BasketballPlayer> players = {
        {"Иван", 2.35, 1.1},
        {"Петр", 2.42, 1.2},
        {"Алексей", 2.68, 0.7}
    };

    // Ищем игрока, который может допрыгнуть до кольца
    auto it = find_if(players.begin(), players.end(), canReachRing);

    if (it != players.end()) {
        cout << it->name << " может допрыгнуть до кольца.\n";
    } else {
        cout << "Ни один из игроков не может допрыгнуть до кольца.\n";
    }

    return 0;
}