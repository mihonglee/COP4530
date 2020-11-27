//compiled and edited by Collin Chimbwanda for Group project


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>
#include <queue>
#include <limits.h>
#include <map>
#include "Graph.hpp"

using namespace std;

typedef std::pair<int, std::string> iPair;
Edge::Edge()
{
    vertexA = "";
    vertexB = "";
    lineweight = 0;
}

Edge::~Edge(){}

//adding vertex label
void Graph::addVertex(std::string label)
{
    for(auto B : vertexlist)
        if(B == label)
            return;
    
    vertexlist.push_back(label);
}

//function to add an edge
void Graph::addEdge(std::string labelA, std::string labelB, unsigned long weight)
{
    unsigned int i;
       
    bool flagA,flagB;
    flagA = false;
    flagB = false;
    
    //iterating through the vertex list
    for(i = 0; i < vertexlist.size(); ++i)
    {
        if(vertexlist.at(i) == labelA)
            flagA = true;
        
        if(vertexlist.at(i) == labelB)
            flagB = true;
    }
    
    //If both boolen expressions are true then label the vertices
    if(flagA == true && flagB == true)
    {
        Edge *E = new Edge();
        E->vertexA = labelA;
        E->vertexB = labelB;
        E->lineweight = weight;
        vertice.push_back(E);
        return;
    }
}

//function to remove an edge
void Graph::removeEdge(std::string labelA, std::string labelB)
{
    unsigned int i;
    Edge *E = new Edge();
    
    //iterating through and if the vertex matches the label then erase
    for(i = 0; i < vertice.size(); i++)
    {
        E = vertice.at(i);
        if(E->vertexA == labelA && E->vertexB == labelB)
        {
            vertice.erase(vertice.begin()+i);
            return;
        }
    }
    
    return;
}

//funtion to print the paths
void Graph::printPath(map<string,string> parent, string endLabel , vector<string> &path)
{
    if (parent[endLabel] == "NONE")
        return;
    printPath(parent, parent[endLabel],path);
    path.push_back(endLabel);
}

//printing the shortest path onto the screen
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    priority_queue< pair<int, string>, vector <pair<int, string>> , greater<pair<int, string>> > pq;
    map<string,int> distance;
    map<string,string> parent;
    
    for (const auto label : vertexlist)
    {
        distance[label] = INT_MAX;
        parent[label] = "NONE";
    }
    
    pq.push(make_pair(0, startLabel));
    distance[startLabel] = 0;
    
    //while loop if the priority queue is not empty
    while (!pq.empty())
    {
        string A = pq.top().second;
        pq.pop();
      
        list< pair<int, string> >::iterator i;
        string B;
        
        for (auto x : vertice)
        {
            if(x->vertexA == A)
                B = x->vertexB;
            else if(x->vertexB == A)
                B = x->vertexA;
            else
                continue;
            
            int weight = x->lineweight;
            
            if (distance[B] > distance[A] + weight)
            {
                parent[B] = A;
                distance[B] = distance[A] + weight;
                pq.push(make_pair(distance[B], B));
            }
        }
    }
    
    path.push_back(startLabel);
    printPath(parent,endLabel,path);
       
    return distance[endLabel];
};

//Removes the vertex with label from the graph and the edge between that vertex and the other vertices
void Graph::removeVertex(std::string label)
{
    unsigned int i;
    Edge *E = new Edge();
    for(i = 0; i < vertexlist.size(); i++)
    {
        if(vertexlist.at(i) == label)
        {
            vertexlist.erase(vertexlist.begin()+i);
        
            for(i = 0; i < vertice.size(); i++)
            {
                E = vertice.at(i);
                
                if(E->vertexA == label || E->vertexB == label)
                    vertice.erase(vertice.begin()+i);
            }
        }
    }

    return;
}
