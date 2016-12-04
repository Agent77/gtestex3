
#include "Point.h"
#include "TestPoint.h"
#include <gtest/gtest.h>
using namespace std;
class TestPoint: public::testing::Test {
protected:
    Point point;
public:
    TestPoint() {} //: (point = new Point(1, 2)) {}
};

    TEST(TestPoint, getMyLocation) {
        Point p1 =  Point(1, 0);
        Point p2(p1.getMyLocation());
    ASSERT_EQ(p1.getX(), p2.getX())  << "myLocation didn't get 0,0";
    ASSERT_EQ(p1.getY(), p2.getY())  << "myLocation didn't get 0,0";
        /*p1 = Point(-1, -1);
        Point point(p1.getMyLocation());
        p2 = point;
        ASSERT_EQ(p1.getX(), p2.getX()) << "myLocation didn't get -1,-1";
        ASSERT_EQ(p1.getY(), p2.getY())  << "myLocation didn't get -1,-1";
*/
    }

TEST(TestPoint, getNextCoordinate) {
        Point p1 = Point(1, 2);
        int x = p1.getNextCoordinate(0);
        int y = p1.getNextCoordinate(1);
        ASSERT_EQ(x, 1) << "getNextCoordinate didn't get x";
        ASSERT_EQ(y, 2) << "getNextCoordinate didn't get y";
    }

TEST(TestPoint, getCoordinateArray) {
        Point p1 = Point(1, 2);
        int* a = p1.getCoordinates();
        ASSERT_TRUE((a[0] == 1) && (a[1] == 2)) << "Coordinates returned incorrectly.";
    }
TEST(TestPoint, Print) {
    //std::ostream& o;
    Point p = Point(7,9);
    //string s = p.printFormat(o);
    //ASSERT_STREQ(s, "(7,8)") << "Wrong format.";
}