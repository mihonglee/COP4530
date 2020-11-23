#ifndef EDGE_H
#define EDGE_H
#include <string>
const std::string EMPTY_STR = " ";

class Edge {
public:
    Edge() {
        u = EMPTY_STR;
        v = EMPTY_STR;
        edgeWeight = 0;
    };
    ~Edge();
    std::string u;
    std::string v;
    unsigned long edgeWeight;
};

#endif /*EDGE_H*/