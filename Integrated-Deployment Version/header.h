#include <list>
#include <vector>
#include <queue>
#include<iostream>
#include <utility>
#include <set>
using namespace std; 
class Graph 
{ 
    int V;    // No. of vertices 
    list< pair<int, int> > *adj; 
public: 
    Graph(int V);  // Constructor  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
    // prints shortest path from s 
    void shortestPath(int s);
}; 
void deg_cent(ifstream &input);
void clos_cent(ifstream &in);