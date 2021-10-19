#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(int v)
{
    vertics = v;
    edge.resize(v);
    distance.resize(v, INT_MAX);
    isVisit.resize(v, false);

};

void Graph::generate_paths(double density, int minDist, int maxDist)
{
    int V = getVertics();
    for (int i = 0;i < V;i++)
    {
        for (int j = 0;j < i;j++)
        {
            double prob = ((double)rand()) / RAND_MAX;
            if (prob <= density)
            {
                int weight = ((int)rand()) % maxDist;
                addEdge(i, j, weight);
            }
        }
    }
};

void Graph::addEdge(int src, int dest, int weight)
{
    edge[src].push_back(node(dest, weight));
    edge[dest].push_back(node(src, weight));
};

//Ii use this function to visualize my map.
void Graph::printGraph()
{
    for (int i = 0;i < edge.size();i++)
    {
        cout << i << " --> ";
        for (int j = 0;j < edge[i].size();j++)
        {
            cout << edge[i][j].first << ", " << edge[i][j].second << " --> ";
        }
        cout << "end" << endl;
    }
};

vector<double> Graph::Dijkstra(int src)
{
    distance[src] = 0;
    isVisit[src] = true;
    Q.push(node(src, 0));

    while (!Q.empty())
    {
        node temp = Q.top();
        Q.pop();

        int dest = temp.first;
        int weight = temp.second;

        for (int i = 0;i < edge[dest].size(); i++)
        {
            int dest_2 = edge[dest][i].first;
            int weight_2 = edge[dest][i].second;


            // if we find another path with shorter distance and never visit before, then we go to the node, push the node into the queue, and update the distance
            if (distance[dest_2] > distance[dest] + weight_2 && !isVisit[dest_2])
            {
                distance[dest_2] = distance[dest] + weight_2;
                isVisit[dest_2] = true;
                Q.push(node(dest_2, distance[dest_2]));
            }
        }
    }

    return distance;
};

double Graph::avgShortestPath()
{
    vector<double> distance = getDistance();
    double sum = 0;
    int adjacent = 0;

    for (int i = 0;i < distance.size();i++)
    {
        if (distance[i] != (float)INT_MAX)
        {
            sum += distance[i];
            adjacent +=1 ;
        }
    }
    return sum / adjacent;
};