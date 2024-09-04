#include "./monitor.h"
#include <gtest/gtest.h>

// Test for isTemperatureCritical function
TEST(MonitorTest, IsTemperatureCritical) {
    EXPECT_TRUE(isTemperatureCritical(103));
    EXPECT_TRUE(isTemperatureCritical(94));
    EXPECT_FALSE(isTemperatureCritical(98.6));
}

// Test for isPulseRateOutOfRange function
TEST(MonitorTest, IsPulseRateOutOfRange) {
    EXPECT_TRUE(isPulseRateOutOfRange(59));
    EXPECT_TRUE(isPulseRateOutOfRange(101));
    EXPECT_FALSE(isPulseRateOutOfRange(75));
}

// Test for isSpo2Low function
TEST(MonitorTest, IsSpo2Low) {
    EXPECT_TRUE(isSpo2Low(89));
    EXPECT_FALSE(isSpo2Low(91));
}

// Test for vitalsOk function
TEST(MonitorTest, VitalsOk) {
    EXPECT_EQ(vitalsOk(103, 75, 95), 0);
    EXPECT_EQ(vitalsOk(98.6, 59, 95), 0);
    EXPECT_EQ(vitalsOk(98.6, 75, 89), 0);
    EXPECT_EQ(vitalsOk(98.6, 75, 95), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}