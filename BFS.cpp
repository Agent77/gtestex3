#include <sstream>
#include "BFS.h"

using namespace std;
/*
 * Initializes the BFS source and destination based
 * on input, and sets the BFS graph to the graph object
 * that was sent.
 */


BFS::BFS(Graph* g) { //TODO when initializing source, visit it.
    //this->source =  g->getNode(sLoc);
    //(*(source)).visit();
    //(*(source)).setPrev(*source);
    //this->destination = g->getNode(dLoc);
    this->graph = g;
}
/*
 * Prints the path from Source to Destination by
 * working backwards, from destination, and asking for the
 * node's 'previous' until arriving at the source.
 */
void BFS::PrintPath( Node* source, Node* destination) {
    Coordinate *path[100] = {};
    int count = 0;
    Node *currentNode = destination;
    Coordinate *c = ((*(currentNode)).getMyLocation());
    path[count] = c;
    count++;
    Node *n;
    do {
        n = ((*(graph)).getLocationOfPrev(currentNode));
        if (n->getMyLocation()->equalTo(source->getMyLocation())) {
            path[count] = n->getMyLocation();
            break;
        }
        path[count] = n->getMyLocation();
        count++;
        currentNode = n;
    } while (!(currentNode->getMyLocation()->equalTo(source->getMyLocation())));

    for (int i = count; i >= 0; i--) {
        Point point = path[i];
        cout << point << endl;
    }

    graph->deleteGraph();
}
/*
 * Gets the path from a source to a destination using a queue.
 * each iteration, it checks if it has arrived the destination.
 * Once it breaks, it prints the path.
 */
void BFS::getPath() {
    Node* newSource;
    Coordinate *c1;
    Coordinate *c2;
    myDeque.push(source);
    newSource = source;
    do {

        visitNeighbors(newSource);
        if (!myDeque.empty()) {
            myDeque.pop();
        }
        newSource = myDeque.front();
        if(newSource == NULL) {
        break;
        }
            c1 = (*(newSource)).getMyLocation();
            c2 = (*(destination)).getMyLocation();
    } while(!(c2->equalTo(c1)));
//    BFS::PrintPath(source, destination);
}

/*
 * Function visits all the neighbors of the sent node, n, by calling
 * the node's function 'getNeighbors()'. It then iterates
 * over the vector of neighbors, to check if they've been visited.
 * If they haven't, its sets their member 'visited' to true and
 * pushes them onto the queue.
 */
std::vector<Node*> BFS::visitNeighbors(Node* n) {
    std::vector<Node *> neighbors = (*(graph)).getNeighbors(n);
    vector<Node *>::iterator v = neighbors.begin();
    while (v != neighbors.end()) {
        if (!(*(*v)).isVisited()) {
            (*(*v)).visit();
            myDeque.push((*v));
        }
        v++;
    }
    return neighbors;
}
BFS::~BFS() {

}
Node* BFS::getDest() {
    return destination;
}
Node* BFS::getSource() {
    return source;
}

Coordinate* BFS::getNextInPath(Coordinate* sLoc, Coordinate* dLoc){
    this->source =  graph->getNode(sLoc);
    this->source->visit();
    //this->source->setPrev(*source);
    this->destination = graph->getNode(dLoc);
    this->getPath();
    Node *node= getDest();
    Node* previousNode;
    while (node != source && node->getPrev()!=NULL){
     /*   if(node->getMyLocation()->equalTo(source->getMyLocation())) {
            break;
        }*/
        previousNode = node;
        node = node->getPrev();


    }
    return previousNode->getMyLocation();
}