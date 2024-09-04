#include "./monitor.h"

#include <iostream>
using std::cout;

void alert(const char* message) {
    cout << message << "\n";
}

bool isTemperatureCritical(float temperature) {
    return temperature > 102 || temperature < 95;
}

bool isPulseRateOutOfRange(float pulseRate) {
    return pulseRate < 60 || pulseRate > 100;
}

bool isSpo2Low(float spo2) {
    return spo2 < 90;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureCritical(temperature)) {
        alert("Temperature is critical!");
        return 0;
    }
    if (isPulseRateOutOfRange(pulseRate)) {
        alert("Pulse Rate is out of range!");
        return 0;
    }
    if (isSpo2Low(spo2)) {
        alert("SpO2 level is low!");
        return 0;
    }
    return 1;
}
