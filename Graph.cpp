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

//Creates and adds a vertex to the graph with label. No two vertices should have the same label.

void Graph::addVertex(std::string label) {
    for (unsigned int i = 0; i < vertices.size(); i++) {
        // if the label exists already, then don't add to the vertice vector.
        if (vertices.at(i) == label) { return; }
    }
    // otherwise, it doesn't exist already in the vector, so add it.
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


unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
   
   
};

void Graph::printShortestPath(std::map<std::string,std::string> labeledVertices, std::string endLabel , std::vector<std::string> &path) {
   if (labeledVertices[endLabel] == EMPTY_STR) { return; }
   printShortestPath(labeledVertices, labeledVertices[endLabel],path);
   path.push_back(endLabel);
};
