
//#include "pch.h"

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <limits> // for numeric_limits
#include <iomanip>
#include <set>
#include <utility> // for pair
#include <algorithm>

#include <iterator>

using namespace std;

typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = std::numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;


void DijkstraComputePaths(vertex_t source,
    const adjacency_list_t &adjacency_list,
    std::vector<weight_t> &min_distance,
    std::vector<vector<vertex_t>> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
            neighbor_iter != neighbors.end();
            neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u <= min_distance[v]) {

                if (distance_through_u == min_distance[v]) {
                    previous[v].push_back(u);

                }

                else {
                    vertex_queue.erase(std::make_pair(min_distance[v], v));

                    min_distance[v] = distance_through_u;
                    if (previous[v].size() == 1){

                        previous[v][0] = u; // modify don't push



                    }
                    else {
                        previous[v].push_back(u); // you push at first only
                    }

                    vertex_queue.insert(std::make_pair(min_distance[v], v));
                }
            }

        }
    }
}






list<vertex_t> DijkstraGetShortestPathTo(vertex_t src , vertex_t dist
 ,vector<weight_t>minDist,vector<vector<vertex_t>> &previous,vector<vector<vertex_t>> &NEXT, vector<vector<vertex_t>> NEXTbyValue)
{

    list<vertex_t> path;
    //vector<vertex_t> causedAproblem;
    int problemNodeCount =  0;
    int flag = 0;


    while (src != dist && minDist[src]<=minDist[dist]){  //&&NEXT[src].size()!=0) { // optimize later


        if (previous[src].size() == 0 && NEXT[src].size() == 0) { path.clear(); return path;  }


        if (NEXT[src].size() == 1) {


            vertex_t temp = src;
            src = NEXT[src][0];
            if (minDist[src] >= minDist[dist] && src != dist) {// you are aheading in a wrong path



                //if(path.size()>0) NEXT = NEXTbyValue;


                problemNodeCount++;
                src = temp; //from which i had the wrong path


                while (NEXT[src].size() == 1) {

                    if (previous[src].size() == 0)break; //happens to be the source

                    src = previous[src][0];


                }

                if (previous[src].size() == 0) {
                    NEXT = NEXTbyValue;
                    flag = 1;  }

                if (flag) {
                    for (size_t l = 0; l < problemNodeCount; l++)
                    {
                        NEXT[src].erase(NEXT[src].begin());
                    }
                    flag = 0;
                }

                else NEXT[src].erase(NEXT[src].begin());



                if (previous[src].size() == 0)path.clear();

                continue;

            }
            else {

                path.push_back(temp);

            }
        }
        else {

            int temp = src;
            if (NEXT[src].size() == 0 && src != dist) {// then it's a node outside of the shortest path

                src = previous[src][0];
                NEXT[src].erase(NEXT[src].begin());
                continue;
            }

            src = NEXT[src][0];

            if (NEXT[src].size() == 0 && src !=dist) {// then it's a node outside of the shortest path
                src = temp;
                NEXT[temp].erase(NEXT[temp].begin());
                continue;
            }


            if (minDist[src] >= minDist[dist] && src != dist) { // you are aheading in a wrong path




                problemNodeCount++;
                //if (path.size() > 0) NEXT = NEXTbyValue;

                src = temp;

                while (NEXT[src].size() == 1) {
                    //NEXT[src].erase(NEXT[src].begin());
                    if (previous[src].size() == 0)break; //happens to be the source

                    src = previous[src][0];
                }

                if (previous[src].size() == 0) {
                    NEXT = NEXTbyValue;
                    flag = 1; }

                if (flag) {
                    for (size_t l = 0; l < problemNodeCount; l++)
                    {
                        NEXT[src].erase(NEXT[src].begin());
                    }
                    flag = 0;
                }

                else NEXT[src].erase(NEXT[src].begin());


                if(previous[src].size()==0)path.clear();


                continue;

            }

            else {
                path.push_back(temp);
                NEXT[temp].erase(NEXT[temp].begin()); // as temp[next].size > 1

            }


        }

    }


    if(src != dist && NEXT[src].size() == 0) { path.clear(); return path; }

    if(src==dist) path.push_back(dist);

    return path;
}


int main()
{



    vector<bool> parentDiscovered;
    vector<int> parentDiscoveredOUTPUT;

    vector<string> paths;

    size_t n, m;
    cin >> n >> m;

    adjacency_list_t adjacency_list(n);



    for (size_t i = 0; i < m; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;

        adjacency_list[x].push_back(neighbor(y, weight));
        adjacency_list[y].push_back(neighbor(x, weight));


    }






    std::vector<weight_t> min_distance;
    std::vector<vector<vertex_t>> previous;
    std::vector<vector<vertex_t>> NEXT;


    for (size_t i = 0; i < n - 1; i++)
    {


        DijkstraComputePaths(i, adjacency_list, min_distance, previous);

        NEXT.clear();
        NEXT.resize(n);

        for (size_t q = 0; q < previous.size(); q++)
        {
            for (size_t j = 0; j < previous[q].size(); j++)
            {
                NEXT[previous[q][j]].push_back(q);
            }



        }

        auto NEXT_COPY(NEXT);


        for (size_t j = i + 1; j < n; j++)
        {
            NEXT = NEXT_COPY;

            while (true) {



                //test for problems

                list<vertex_t> path = DijkstraGetShortestPathTo(i, j, min_distance, previous,NEXT, NEXT);



                string s = "";

                for (list<vertex_t>::iterator it = path.begin(); it != path.end(); it++)
                {
                    s += to_string(*it);

                }


                //the Condition
                if ((paths.size() > 0 && !(s.compare(paths.back()))) || s.length() == 0) break;

                paths.push_back(s);

            }

        }
    }



    vector<string> interMediatePathCount;

    char node;
    //num
    vector<int>num;
    stack<string> last;
    //dum
    vector<int>dum;
    stack<string> last2;

    for (int p = 0; p < n; p++)
    {



        interMediatePathCount.clear();
        num.clear();
        dum.clear();
        while (!last.empty())
            last.pop();
        while (!last2.empty())
            last2.pop();


    node = '0' + p;

    //  node = '0';
        for (vector<string>::iterator it = paths.begin(); it != paths.end(); it++)
        {

            for (int i = 0; i < (*it).length(); i++)
            {
                if (((*it)[i] == node) && (i != 0 && i != (*it).length() - 1)) { // intermediate node


                    interMediatePathCount.push_back(*it);


                }
            }
        }


        //num

        for (int loopCount = 0; loopCount < interMediatePathCount.size(); loopCount++) {


            string temp = interMediatePathCount[loopCount];
            if (last.size() > 0 && (temp[0] == last.top()[0] && temp[temp.length() - 1] == last.top()[last.top().length() - 1]))continue;
            last.push(temp);
            num.push_back(0);
            for (vector<string>::iterator it = interMediatePathCount.begin(); it != interMediatePathCount.end(); it++)
            {

                if ((*it)[0] == temp[0] && (*it)[(*it).length() - 1] == temp[temp.length() - 1]) {

                    num.back()++;
                }


            }

        }

        //dum

        for (vector<string>::iterator it = interMediatePathCount.begin(); it != interMediatePathCount.end(); it++)
        {

            char firstChar = (*it)[0];
            char lastChar = (*it)[(*it).length() - 1];

            if (last2.size() > 0 && (firstChar == last2.top()[0] && lastChar == last2.top()[last2.top().length() - 1]))continue;

            last2.push(*it);
            dum.push_back(0);

            for (vector<string>::iterator itt = paths.begin(); itt != paths.end(); itt++)
            {
                if ((*itt)[0] == firstChar && (*itt)[(*itt).length() - 1] == lastChar) {


                    dum.back()++;


                }
            }


        }

        float result = 0;

        int i = 0;
        for (vector<int>::iterator it = dum.begin(); it != dum.end(); it++)
        {

            result += ((float)num[i] / (float)*(it));
            i++;
        }
        //cout << "The betweenness centrality g(" << node << ") = " << fixed<< setprecision(12)<<result << endl;

        cout <<fixed << setprecision(12) << result << endl;
    }

    return 0;
}
