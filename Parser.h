
#ifndef TRY_PARSER_H
#define TRY_PARSER_H


#include "Graph.h"

class Parser {
private:
    int xSize;
    int ySize;
public:
    Parser() {};
    Parser(string s) {};
    ~Parser(){};
    Graph* getGraph(char* c[]) {};
    Coordinate* createPoint(string s) {};
    //Node* createNode(Point p){};
    bool isValid(string s) {};
    int toInt(string s) {};

};


#endif //TRY_PARSER_H
