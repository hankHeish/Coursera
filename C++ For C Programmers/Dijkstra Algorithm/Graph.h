#ifndef DIJKSTRA_ALGORITHM_GRAPH_H
#define DIJKSTRA_ALGORITHM_GRAPH_H
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    Graph() {}
    Graph(int v);

    int getVertics() { return vertics; }
    vector<double> getDistance() { return distance; }

    void generate_paths(double density, int min_dist, int max_dist);
    void addEdge(int src, int dest, int weight);
    void printGraph();

    // Dijkstra Algorithm
    vector<double> Dijkstra(int source);
    double avgShortestPath();

private:
    int  vertics;
    typedef pair<int, int> node;
    vector<vector<node>> edge;
    struct myComp
    {
        constexpr bool operator() (pair<int, int> const &a, pair<int, int> const &b) const noexcept
        {
            return a.second > b.second;
        }
    };

    // Dijkstra Algorithm
    priority_queue<node, vector<node>, myComp> Q;
    vector<double> distance;
    vector<bool> isVisit;
};

#endif //DIJKSTRA_ALGORITHM_GRAPH_H
