
#include "gtest/gtest.h"
#include "TestNode.h"


TEST(TestNode, Node) {
    Point* p;
    Point point = Point(1,2);
    p = &point;
    Node n = Node(p);
    int* nums = n.getLocation();
    int x = nums[0];
    int y = nums[1];
    ASSERT_EQ(x, 1) << "x did not get correct value.";
    ASSERT_EQ(y, 2) << "y did not get correct value.";
}

TEST(TestNode, Visit) {
    Node n = Node();
    n.visit();
    ASSERT_TRUE(n.isVisited()) << "Did not visit properly.";
}
TEST(TestNode, Prev) {
    Point* point = new Point(1,2);
    Point* point2 = new  Point(3,3);
    Node* n = new Node(point);
    Node* prev = new Node(point2);
    n->setPrev(*prev);
    ASSERT_TRUE(n->getPrev() == prev) << "Previous Node not set correctly.";
    delete point;
    delete point2;
    delete n;
    delete prev;
}

TEST(TestNode, GetLocations) {
    Point* point = new Point(1,2);
    Node* n = new Node(point);
    Point po(n->getMyLocation());
    int x = po.getX();
    int y = po.getY();
    ASSERT_EQ(x,1) << "X value is incorrect.";
    ASSERT_EQ(y,2) << "Y value is incorrect.";
    x = po.getNextCoordinate(0);
    y = po.getNextCoordinate(1);
    ASSERT_EQ(x,1) << "[0] coordinate is incorrect.";
    ASSERT_EQ(y,2) << "[1] coordinate is incorrect.";
    delete point;
    delete n;
}
