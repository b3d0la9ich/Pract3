#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Child {
    string gender;
    double motherHeight;
    double fatherHeight;
};

// Функция для вычисления будущего роста ребенка
double calculateChildHeight(const Child& child) {
    double childHeight = (child.motherHeight + child.fatherHeight) / 2.0;
    if (child.gender == "мужчина") {
        childHeight += 10;
    } else {
        childHeight -= 10;
    }
    return childHeight;
}

int main() {
    vector<Child> children = {
        {"мальчик", 165, 180}, 
        {"девочка", 170, 175}, 
        {"мальчик", 160, 190}, 
        {"девочка", 175, 170}  
    };

    vector<double> childHeights;
    for (const auto& child : children) {
        double height = calculateChildHeight(child);
        childHeights.push_back(height);
    }

    // Находим максимальный рост ребенка
    double maxChildHeight = *max_element(childHeights.begin(), childHeights.end());

    cout << "Самый высокий будущий ребенок будет иметь рост: " << maxChildHeight << " см" << endl;

    return 0;
}
