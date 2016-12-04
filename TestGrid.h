
#ifndef EX2_TESTGRID_H
#define EX2_TESTGRID_H

#include "gtest/gtest.h"
#include "Grid.h"

class TestGrid:public::testing::Test {
protected:
    Grid* grid;
    Point* point;
    Point* point2;
    Node* n;
public:
    virtual void SetUp() {
        cout<< "Setting Up.\n";
        grid =  new Grid(4,4);
        point = new Point(1,2);
        point2 = new Point(3,3);
        n = new Node(point);
    }
    virtual void TearDown() {
        cout<<" Tearing Down.\n";
        delete point;
        delete point2;
        delete n;
        delete grid;
    }

};


#endif //EX2_TESTGRID_H
//coment