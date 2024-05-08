#include <iostream>
#include <string>

struct Transistor {
    std::string name;
    double power;
    double maxCurrent;
    int quantity;
};

Transistor* findMaxPowerTransistor(Transistor* transistors, size_t size) {
    Transistor* maxPowerTransistor = nullptr;
    double maxPower = -1.0; 

    for (size_t i = 0; i < size; ++i) {
        if (transistors[i].power > maxPower) {
            maxPower = transistors[i].power;
            maxPowerTransistor = &transistors[i];
        }
    }

    return maxPowerTransistor;
}

int main() {
    Transistor transistors[] = {
        {"สา315ร", 10.5, 2.0, 100},
        {"สา814ย", 8.0, 1.5, 50},
        {"สา302", 12.0, 2.5, 75},
        {"สา853", 9.5, 2.2, 120}
    };

    std::cout << "Transistors:\n";
    for (const auto& transistor : transistors) {
        std::cout << "Name: " << transistor.name << ", Power: " << transistor.power
            << ", Max Current: " << transistor.maxCurrent << ", Quantity: " << transistor.quantity << "\n";
    }

    Transistor* maxPowerTransistor = findMaxPowerTransistor(transistors, sizeof(transistors) / sizeof(Transistor));
    if (maxPowerTransistor != nullptr) {
        maxPowerTransistor->quantity = 200;
    }

    std::cout << "\nUpdated Transistors:\n";
    for (const auto& transistor : transistors) {
        std::cout << "Name: " << transistor.name << ", Power: " << transistor.power
            << ", Max Current: " << transistor.maxCurrent << ", Quantity: " << transistor.quantity << "\n";
    }

    return 0;
}