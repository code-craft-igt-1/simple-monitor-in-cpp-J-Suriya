#ifndef MONITOR_H
#define MONITOR_H

void alert(const char* message);

bool isTemperatureCritical(float temperature);
bool isPulseRateOutOfRange(float pulseRate);
bool isSpo2Low(float spo2);

int vitalsOk(float temperature, float pulseRate, float spo2);

#endif // MONITOR_H