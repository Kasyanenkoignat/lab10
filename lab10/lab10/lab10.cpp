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
        {"��315�", 50, 100, 10},
        {"��814�", 60, 120, 20},
        {"��302", 40, 80, 15},
        {"��853", 70, 150, 5}
    };

    cout << "������ ������ ����������i�:" << endl;
    for (const Transistor& transistor : transistors) {
        cout << "�����: " << transistor.name << ", ������i���: " << transistor.power
            << ", ������������ ������� �����: " << transistor.max_current
            << ", �i���i���: " << transistor.quantity << endl;
    }

    auto max_power_transistor = max_element(transistors.begin(), transistors.end(), [](const Transistor& a, const Transistor& b) {
        return a.power < b.power;
        });

    max_power_transistor->quantity = 200;

    cout << "\n���������� � ������������ ������i���:" << endl;
    cout << "�����: " << max_power_transistor->name << ", ������i���: " << max_power_transistor->power
        << ", ������������ ������� �����: " << max_power_transistor->max_current
        << ", �i���i���: " << max_power_transistor->quantity << endl;

    return 0;
}