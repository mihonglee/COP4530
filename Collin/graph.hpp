//edited and compiled by Collin Chimbwanda for Final Project 

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <tuple>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include "GraphBase.hpp"

using namespace std;

class Edge{

    public:
         Edge(); //Constructor
        ~Edge(); //Deconstructor

        string distance1;
        string distance2;
        unsigned long lineWeight;

};

class Graph : public GraphBase {
    friend class Edge;

    public:

     void decidePath(map<string, string> startLabel, string endLabel, vector<string> &path);
     void addVertex(std::string label);
     void removeVertex(std::string label);
     void addEdge(std::string label1, std::string label2, unsigned long weight);
     void removeEdge(std::string label1, std::string label2);
     unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

    // private:
         vector<string> vertex;
        vector<Edge*> vertexEdge;
        vector<string> pathway;
    
};

#endif
