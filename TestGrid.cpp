
#include "TestGrid.h"
#include "Node.h"
#include "Point.h"
#include <gtest/gtest.h>

TEST_F(TestGrid, GetLocationOfPrev) {
    Node* prev = new Node(point2);
    n->setPrev(*prev);
    grid->getLocationOfPrev(n);
    ASSERT_TRUE(n->getPrev() == prev) << "Previous not set correctly.";
    delete prev;
}

TEST_F(TestGrid, GetNeighbors) {
    Point* point = new Point(1,1);
    Node* n = new Node(point);
    Grid* grid = new Grid(4,4);
    Point p[4];
    p[0] = Point(0,1);
    p[1] = Point(1,2);
    p[2] = Point(2,1);
    p[3] = Point(1,0);
    std::vector<Node*> neighbors = grid->getNeighbors(n);
    vector<Node*>::iterator v = neighbors.begin();
    int i = 0;
    while (v != neighbors.end()) {
        int* loc = (*(*(v))).getLocation();
        ASSERT_EQ(p[i].getX(), loc[0]) << "Wrong neighbor!";
        ASSERT_EQ(p[i].getY(), (*(*(v))).getLocation()[1]) << "Wrong neighbor!";
        v++;
        i++;
    }
    //Point* pointNeg = new Point(0,0);
    //n =  Node(pointNeg);
    //std::vector<Node*> neighbors = grid->getNeighbors(n);
    delete point;
    delete n;
    delete grid;
}

TEST_F(TestGrid, GetNode) {
    Point* p = new Point(1,2);
    Node n = Node(p);
    ASSERT_TRUE(n.getLocation()[0] == 1 && n.getLocation()[1] == 2) << "Node initialized incorrectly.";
}