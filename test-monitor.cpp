#include "monitor.h"
#include <gtest/gtest.h>

// Test for isSpo2Low function
TEST(MonitorTest, IsSpo2Low) {
    EXPECT_TRUE(isSpo2Low(89));  // Below normal range
    EXPECT_FALSE(isSpo2Low(91)); // Within normal range
}

// Test for isTemperatureWarning function
TEST(MonitorTest, IsTemperatureWarning) {
    EXPECT_TRUE(isTemperatureWarning(36.0));  // Approaching hypothermia
    EXPECT_TRUE(isTemperatureWarning(37.5));  // Approaching hyperthermia
    EXPECT_FALSE(isTemperatureWarning(36.5)); // Normal range
}

// Test for isPulseRateWarning function
TEST(MonitorTest, IsPulseRateWarning) {
    EXPECT_TRUE(isPulseRateWarning(60));  // Approaching low pulse rate
    EXPECT_TRUE(isPulseRateWarning(100)); // Approaching high pulse rate
    EXPECT_FALSE(isPulseRateWarning(75)); // Normal range
}

// Test for isSpo2Warning function
TEST(MonitorTest, IsSpo2Warning) {
    EXPECT_TRUE(isSpo2Warning(90));  // Approaching low SPO2
    EXPECT_FALSE(isSpo2Warning(92)); // Normal range
}

// Test for vitalsOk function
TEST(MonitorTest, VitalsOk) {
    EXPECT_EQ(vitalsOk(35.9, 75, 95), 0);  // Temperature critical
    EXPECT_EQ(vitalsOk(36.5, 59, 95), 0);  // Pulse rate out of range
    EXPECT_EQ(vitalsOk(36.5, 75, 89), 0);  // Spo2 low
    EXPECT_EQ(vitalsOk(36.5, 75, 95), 1);  // All vitals okay
}

// Test for language support
TEST(MonitorTest, LanguageSupport) {
    language = "EN";
    EXPECT_STREQ(getMessage("ALERT"), "Vitals are not okay!");
    EXPECT_STREQ(getMessage("TEMP_HYPO_WARNING"), "Warning: Approaching hypothermia");
    EXPECT_STREQ(getMessage("TEMP_HYPER_WARNING"), "Warning: Approaching hyperthermia");
    EXPECT_STREQ(getMessage("PULSE_LOW_WARNING"), "Warning: Approaching low pulse rate");
    EXPECT_STREQ(getMessage("PULSE_HIGH_WARNING"), "Warning: Approaching high pulse rate");
    EXPECT_STREQ(getMessage("SPO2_WARNING"), "Warning: Approaching low SPO2");

    language = "DE";
    EXPECT_STREQ(getMessage("ALERT"), "Vitalwerte sind nicht in Ordnung!");
    EXPECT_STREQ(getMessage("TEMP_HYPO_WARNING"), "Warnung: Annäherung an Hypothermie");
    EXPECT_STREQ(getMessage("TEMP_HYPER_WARNING"), "Warnung: Annäherung an Hyperthermie");
    EXPECT_STREQ(getMessage("PULSE_LOW_WARNING"), "Warnung: Annäherung an niedrigen Puls");
    EXPECT_STREQ(getMessage("PULSE_HIGH_WARNING"), "Warnung: Annäherung an hohen Puls");
    EXPECT_STREQ(getMessage("SPO2_WARNING"), "Warnung: Annäherung an niedrigen SPO2");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}