#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Transistor {
    string name;
    int power;
    int max_current;
    int quantity;
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<Transistor> transistors = {
        {"КТ315Г", 50, 100, 10},
        {"КТ814В", 60, 120, 20},
        {"КТ302", 40, 80, 15},
        {"КТ853", 70, 150, 5}
    };

    cout << "Повний список транзисторiв:" << endl;
    for (const Transistor& transistor : transistors) {
        cout << "Назва: " << transistor.name << ", Потужнiсть: " << transistor.power
            << ", Максимальний робочий струм: " << transistor.max_current
            << ", Кiлькiсть: " << transistor.quantity << endl;
    }

    auto max_power_transistor = max_element(transistors.begin(), transistors.end(), [](const Transistor& a, const Transistor& b) {
        return a.power < b.power;
        });

    max_power_transistor->quantity = 200;

    cout << "\nТранзистор з максимальною потужнiстю:" << endl;
    cout << "Назва: " << max_power_transistor->name << ", Потужнiсть: " << max_power_transistor->power
        << ", Максимальний робочий струм: " << max_power_transistor->max_current
        << ", Кiлькiсть: " << max_power_transistor->quantity << endl;

    return 0;
}