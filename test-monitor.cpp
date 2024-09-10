#include "./monitor.h"
#include <gtest/gtest.h>

// Test for isTemperatureCritical function
TEST(MonitorTest, IsTemperatureCritical) {
    EXPECT_TRUE(isTemperatureCritical(35.9));  // Below normal range
    EXPECT_TRUE(isTemperatureCritical(37.6));  // Above normal range
    EXPECT_FALSE(isTemperatureCritical(36.5)); // Within normal range
}

// Test for isPulseRateOutOfRange function
TEST(MonitorTest, IsPulseRateOutOfRange) {
    EXPECT_TRUE(isPulseRateOutOfRange(59));  // Below normal range
    EXPECT_TRUE(isPulseRateOutOfRange(101)); // Above normal range
    EXPECT_FALSE(isPulseRateOutOfRange(75)); // Within normal range
}

// Test for isSpo2Low function
TEST(MonitorTest, IsSpo2Low) {
    EXPECT_TRUE(isSpo2Low(89));  // Below normal range
    EXPECT_FALSE(isSpo2Low(91)); // Within normal range
}

// Test for vitalsOk function
TEST(MonitorTest, VitalsOk) {
    EXPECT_EQ(vitalsOk(35.9, 75, 95), 0);  // Temperature critical
    EXPECT_EQ(vitalsOk(36.5, 59, 95), 0);  // Pulse rate out of range
    EXPECT_EQ(vitalsOk(36.5, 75, 89), 0);  // Spo2 low
    EXPECT_EQ(vitalsOk(36.5, 75, 95), 1);  // All vitals okay
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}