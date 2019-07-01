 
#include <list>
#include <vector>
#include <queue>
#include<iostream>
#include <utility>
#include <set>
#include <iomanip>
#include"..\header.h"
using namespace std; 
# define INF 0x3f3f3f3f 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
    // Create a set to store vertices that are being 
    // prerocessed 
    set< pair<int, int> > setds; 
  
    // distances as infinite (INF) 
    vector<int> dist(V, INF); 
  
    // Insert source itself in Set and initialize its 
    // distance as 0. 
    setds.insert(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!setds.empty()) 
    { 
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
    double cntral_sum = 0.0; 
    for (int i = 0; i < V; ++i) 
        {
            if(dist[i]!=0)
                cntral_sum += dist[i];
        }
    //printf("closeness centrality from src[ %d ] = %f\n",src,(V-1.0)/cntral_sum);
    cout<<std::setprecision(12)<<(V-1.0)/cntral_sum<<"\n";
}