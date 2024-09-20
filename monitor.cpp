#include "monitor.h"
#include <map>
#include <iostream>

std::string language = "EN";

const float TEMP_WARNING_TOLERANCE = 1.53;
const float PULSE_WARNING_TOLERANCE = 1.5;
const float SPO2_WARNING_TOLERANCE = 1.35;

bool isTemperatureCritical(float temperature) {
    return (temperature < 36.0 || temperature > 37.5);
}

bool isTemperatureWarning(float temperature) {
    return (temperature >= 36.0 && temperature < 36.0 + TEMP_WARNING_TOLERANCE) ||
           (temperature > 37.5 - TEMP_WARNING_TOLERANCE && temperature <= 37.5);
}

bool isPulseRateOutOfRange(float pulseRate) {
    return (pulseRate < 60 || pulseRate > 100);
}

bool isPulseRateWarning(float pulseRate) {
    return (pulseRate >= 60 && pulseRate < 60 + PULSE_WARNING_TOLERANCE) ||
           (pulseRate > 100 - PULSE_WARNING_TOLERANCE && pulseRate <= 100);
}

bool isSpo2Low(float spo2) {
    return spo2 < 90;
}

bool isSpo2Warning(float spo2) {
    return (spo2 >= 90 && spo2 < 90 + SPO2_WARNING_TOLERANCE);
}

const char* getMessage(const char* key) {
    static const std::map<std::string, const char*> messages_de = {
        {"ALERT", "Vitalwerte sind nicht in Ordnung!"},
        {"TEMP_HYPO_WARNING", "Warnung: Annäherung an Hypothermie"},
        {"TEMP_HYPER_WARNING", "Warnung: Annäherung an Hyperthermie"},
        {"PULSE_LOW_WARNING", "Warnung: Annäherung an niedrigen Puls"},
        {"PULSE_HIGH_WARNING", "Warnung: Annäherung an hohen Puls"},
        {"SPO2_WARNING", "Warnung: Annäherung an niedrigen SPO2"}
    };

    static const std::map<std::string, const char*> messages_en = {
        {"ALERT", "Vitals are not okay!"},
        {"TEMP_HYPO_WARNING", "Warning: Approaching hypothermia"},
        {"TEMP_HYPER_WARNING", "Warning: Approaching hyperthermia"},
        {"PULSE_LOW_WARNING", "Warning: Approaching low pulse rate"},
        {"PULSE_HIGH_WARNING", "Warning: Approaching high pulse rate"},
        {"SPO2_WARNING", "Warning: Approaching low SPO2"}
    };

    const std::map<std::string, const char*>& messages = (language == "DE") ? messages_de : messages_en;

    auto it = messages.find(key);
    if (it != messages.end()) {
        return it->second;
    } else {
        return "Unknown key";
    }

}

void alert(const char* message) {
    std::cout << message << std::endl;
}

void checkTemperature(float temperature) {
    if (isTemperatureCritical(temperature)) {
        alert(getMessage("ALERT"));
    } else {
        bool isWarning = isTemperatureWarning(temperature);
        if (isWarning) {
            if (temperature < 36.0 + TEMP_WARNING_TOLERANCE) {
                alert(getMessage("TEMP_HYPO_WARNING"));
            } else {
                alert(getMessage("TEMP_HYPER_WARNING"));
            }
        }
    }
}

void checkPulseRate(float pulseRate) {
    if (isPulseRateOutOfRange(pulseRate)) {
        alert(getMessage("ALERT"));
    } else if (isPulseRateWarning(pulseRate)) {
        if (pulseRate < 60 + PULSE_WARNING_TOLERANCE) {
            alert(getMessage("PULSE_LOW_WARNING"));
        } else {
            alert(getMessage("PULSE_HIGH_WARNING"));
        }
    }
}

void checkSpo2(float spo2) {
    if (isSpo2Low(spo2)) {
        alert(getMessage("ALERT"));
    } else if (isSpo2Warning(spo2)) {
        alert(getMessage("SPO2_WARNING"));
    }
    
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    checkTemperature(temperature);
    checkPulseRate(pulseRate);
    checkSpo2(spo2);
    return !(isTemperatureCritical(temperature) || isPulseRateOutOfRange(pulseRate) || isSpo2Low(spo2));
}