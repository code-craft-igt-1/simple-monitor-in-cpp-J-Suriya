#include "monitor.h"
#include <iostream>


void alert(const char* message) {
    std::cout << message << std::endl;
}

bool isTemperatureCritical(float temperature) {
    return (temperature < 36.0 || temperature > 37.5);
}

bool isPulseRateOutOfRange(float pulseRate) {
    return (pulseRate < 60 || pulseRate > 100);
}

bool isSpo2Low(float spo2) {
    return spo2 < 90;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureCritical(temperature) || isPulseRateOutOfRange(pulseRate) || isSpo2Low(spo2)) {
        alert("Vitals are not okay!");
        return 0;
    }
    return 1;
}
