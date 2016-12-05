
#include "gtest/gtest.h"
#include "TestTaxi.h"

/*
 * Tests that the correct number of kms has been inserted into the taxi.
 */
TEST_F(TestTaxi, updatingKMs) {
    Taxi t = Taxi();
    int kms = t.getKms();
    t.updateKms();
    int kms2 = t.getKms();
    EXPECT_FALSE(kms == kms2) << "Did not update kilometers.";
}