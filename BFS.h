//
// Created by Tiki Lobel on 11/17/16.
//

#ifndef EX1_BFS_H
#define EX1_BFS_H
#include "Node.h"
#include <queue>
#include "Graph.h"
#include "Grid.h"
#include "Coordinate.h"

/*
 * Class which performs the Breadth-First Search on any given graph/diagram.
 * It contains the graph, start, and end-point, in Node pointer form.
 */
using namespace std;
class BFS {
private:
    std::queue<Node*> myDeque;
    int xsize;
    int ysize;
    Node* source;
    Graph* graph;
    Node* destination;

public:
    BFS(){};
    ~BFS();
    BFS(Graph* g, int x, int y, Coordinate* source, Coordinate* destination);
    void getPath();
    void PrintPath(Node* s, Node* d);
    std::vector<Node*> visitNeighbors(Node* n);
    Node* getDest();
    Node* getSource();

};

#endif //EXONE_BFS_H