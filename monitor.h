#ifndef MONITOR_H
#define MONITOR_H
#include <string>

extern std::string language;

void alert(const char* message);

bool isTemperatureCritical(float temperature);
bool isTemperatureWarning(float temperature);
bool isPulseRateOutOfRange(float pulseRate);
bool isPulseRateWarning(float pulseRate);
bool isSpo2Low(float spo2);
bool isSpo2Warning(float spo2);

const char* getMessage(const char* key);

int vitalsOk(float temperature, float pulseRate, float spo2);

#endif // MONITOR_H