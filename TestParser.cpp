
#include "TestParser.h"
/*
 * Tests that a correct point has been created.
 */
TEST_F(TestParser, CreatePoint) {
    string s = "2_8,1_1";
    Point source = p.createPoint(s);
    ASSERT_EQ(source.getX(), 2);
    ASSERT_EQ(source.getY(), 8);
}

/*
 * Tests that the input values are inside the boundaries.
 */
TEST_F(TestParser, IsValid) {
    string s = "2_-1,3_3";
    //Check that it wont create a point that is out of bounds Of grid size
    string s2 = "9_5,3_3";
    string s3 = "2_2,4_5";
    ASSERT_FALSE(p.isValid(s));
    ASSERT_FALSE(p.isValid(s2));
    ASSERT_TRUE(p.isValid(s3));
}