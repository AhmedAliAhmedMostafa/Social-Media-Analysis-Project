#include "..\header.h"
#include <iostream>
#include<fstream>
using namespace std; 
void clos_cent(ifstream &in)
{
	// create the graph given in above fugure 
    int V ,E; 
    in>>V>>E;
    Graph g(V); 
    for(int i=0;i<E;i++)
    {
        int src,dist,weight;
        in>>src>>dist>>weight;
        g.addEdge(src,dist,weight);
    }
    
    for(int i=0;i<V;i++)
    {
        //cout<<"======== closeness centrality from src ["<<i<<"] =============\n";
        g.shortestPath(i); 
    }
     
}