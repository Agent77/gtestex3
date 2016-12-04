
#include "gtest/gtest.h"
#include "TestTaxi.h"

TEST(TestTaxi, updatingKMs) {
    Taxi t = Taxi();
    int kms = t.getKms();
    t.updateKms();
    int kms2 = t.getKms();
    EXPECT_FALSE(kms == kms2) << "Did not update kilometers.";
}