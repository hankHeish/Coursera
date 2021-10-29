//
// Created by 謝明翰 on 2021/10/22.
//

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include <vector>

using namespace std;

class Graph {
private:
    int vertics;
    vector<int> parent;
    typedef pair<int, int> node;
    vector<pair<int, node>> graph, setMST;

public:
    Graph() {}

    Graph(int v) { vertics = v; };

    void addEdge(int start, int end, int weight);

    void printGrapah();

    // Kruskal Algorithm
    int find(int k);

    void KruskalMST();

    void MSTCost();

};

#endif //MST_GRAPH_H
