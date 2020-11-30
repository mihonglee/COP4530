#ifndef EDGE_H
#define EDGE_H
#include <string>

class Edge {
public:
    Edge() {
        u = " ";
        v = " ";
        edgeWeight = 0;
    };
    ~Edge();
    std::string u;
    std::string v;
    unsigned long edgeWeight;
};

#endif /*EDGE_H*/
