#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include "Edge.hpp"
#include <iostream>
#include <string>
#include <map>

class Graph : public GraphBase {
public:
    Graph() {

    };
    ~Graph() {
       
    };
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

private:
    friend class Edge;
    std::vector<std::string> vertices;
    std::vector<Edge*> graphComps;
};

#endif
