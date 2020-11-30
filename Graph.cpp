/*
COP 4530 Programming Project 5

For Programming Project 5, you will be implementing an undirected weighted Graph ADT and
performing Dijkstra's Algorithm to find the shortest path between two vertices. Your graph can
be implemented using either an adjacency list, adjacency matrix, or an incidence matrix. Your
graph will implement methods that add and remove vertices, add and remove edges, and
calculate the shortest path. Each vertex in your graph will have a string label that will help
identify that vertex to you and the test file.
*/

#include "Graph.hpp"
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

//Creates and adds a vertex to the graph with label. No two vertices should have the same label.

void Graph::addVertex(std::string label) {
    for (unsigned int i = 0; i < vertices.size(); i++) {
        // check if the desired label exists already - if so do not do anything
        if (vertices.at(i) == label) { return; }
    }
    // after verifying it doesn't exist in the vector, add the vertex
     vertices.push_back(label);
};

//Removes the vertex with label from the graph. Also removes the edges between that vertex and the other vertices of the graph.

void Graph::removeVertex(std::string label) {
    for(unsigned int i = 0; i <  vertices.size(); i++) {
        if(vertices.at(i) == label) {
            // if the label exists, then remove it from the vector
             vertices.erase(vertices.begin() + i);
        
            for(unsigned int j = 0; j < graphComps.size(); j++) {
                Edge *tempEdge = new Edge();
                tempEdge = graphComps.at(j);
                
                if(tempEdge->u == label || tempEdge->v == label)
                    graphComps.erase(graphComps.begin() + j);
            }
        }
    }
};

/*Adds an edge of value weight to the graph between the vertex with label1 and the vertex with
label2. A vertex with label1 and a vertex with label2 must both exist, there must not already be
an edge between those vertices, and a vertex cannot have an edge to itself.*/

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
  bool checkA = false, checkB = false;
    // iterate and check if vector contains the labels -> flag them
    for(auto v : vertices) {
        if(v == label1) { checkA = true; }
        if(v == label2) { checkB = true; }      
    }
    // if both labels are in the vector 
    if(checkA && checkB) {
            Edge *edge = new Edge();
            edge->u = label1;
            edge->v = label2;
            edge->edgeWeight = weight;
            graphComps.push_back(edge);
    }
};

/*Removes the edge from the graph between the vertex with label1 and the vertex with label2. A
vertex with label1 and a vertex with label2 must both exist and there must be an edge between
those vertices*/

void Graph::removeEdge(std::string label1, std::string label2) {
   Edge* edge = new Edge();
//    iterate and delete the matching label 
   for(unsigned int i = 0; i < graphComps.size(); i++) {
       edge = graphComps[i];
       if(edge->u == label1 && edge->v == label2) {
           graphComps.erase(graphComps.begin()+i);
       }
   }
};

/*Calculates the shortest path between the vertex with startLabel and the vertex with endLabel
using Dijkstra's Algorithm. A vector is passed into the method that stores the shortest path
between the vertices. The return value is the sum of the edges between the start and end
vertices on the shortest path. */

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    std::priority_queue< std::pair<int, std::string>, std::vector <std::pair<int, std::string> >,
    std::greater<std::pair<int, std::string> > > priorityQueue;
    
    std::map<std::string,std::string> labeledVertices;
    std::map<std::string,int> weightMap;
    
    // initalize the dijkstra's table to empty strings, and infinity for the weights
    for (auto label : verticesVec) {
        labeledVertices[label] = EMPTY_STR;
        weightMap[label] = INF;
    }
    // first add the starting point to the priority queue
    priorityQueue.push(make_pair(0, startLabel));
    weightMap[startLabel] = 0;
    
    // do dijkstra's algo
    while (!priorityQueue.empty()) {
        std::string topLabel = priorityQueue.top().second;
        priorityQueue.pop();
      
        std::string curVertex;

        // checking with all it's adjacent neighbors and their weights...
        for (auto adjNeighbor : graphComps) {
            if(adjNeighbor->u == topLabel) { curVertex = adjNeighbor->v; }
            else if(adjNeighbor->v == topLabel) { curVertex = adjNeighbor->u; }
            else { continue; }

            // hold the temporary weight of current vertex
            int weight = adjNeighbor->edgeWeight;

            // do algo calculation
            if (weightMap[topLabel] + weight < weightMap[curVertex]) {
                labeledVertices[curVertex] = topLabel;
                weightMap[curVertex] = weightMap[topLabel] + weight;
                priorityQueue.push(make_pair(weightMap[curVertex], curVertex));
            }
        }
    }
    path.push_back(startLabel);
    // print the shortest path
    printShortestPath(labeledVertices, endLabel, path);
    return weightMap[endLabel];
};
