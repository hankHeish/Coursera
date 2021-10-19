#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <climits>
#include <cstdlib>
#include "Graph.h"

using namespace std;

int main() {

    srand(time(0));

    // generate the map with 50 vertics with 20% dense.
    Graph G(50);
    G.generate_paths(0.2, 1, 10);
    // G.printGraph();

    vector<double> shortest_path = G.Dijkstra(0);
    double avg_dist = G.avgShortestPath();

    cout << "Average steps for Graph with Density 20% is: " << avg_dist << endl;


    return 0;
}
