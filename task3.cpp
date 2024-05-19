#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Создаем массив слов, содержащий названия овощей и фруктов
    vector<string> words = {"apple", "cucumber", "banana", "potato", "orange"};

    // Создаем массив слов, содержащий названия фруктов
    vector<string> fruits = {"apple", "banana", "orange"};

    // Используем стандартный алгоритм remove_if для удаления фруктов
    words.erase(remove_if(words.begin(), words.end(), [&fruits](const string& word) {
        return find(fruits.begin(), fruits.end(), word) != fruits.end();
    }), words.end());

    // Выводим результат
    cout << "List:\n";
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}