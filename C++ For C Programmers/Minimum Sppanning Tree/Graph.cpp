#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::addEdge(int start, int end, int weight) {
    node temp = node(start, end);
    graph.push_back(pair<int, node>(weight, temp));
};

void Graph::printGrapah() {
    for (int i = 0; i < graph.size(); i++) {
        int w = graph[i].first;

        node temp = graph[i].second;
        int start = temp.first;
        int end = temp.second;

        cout << "start:" << start << " end:" << end << ", weight:" << w << endl;
    }
};

int Graph::find(int k) {
    while (k != parent[k])
        k = parent[k];

    return k;
};

void Graph::KruskalMST() {
    int edge_count = 0;
    sort(graph.begin(), graph.end());

    parent.resize(vertics);
    for (int i = 0; i < vertics; i++)
        parent[i] = i;

    cout << "Searching MST..." << endl;
    for (int i = 0; i < graph.size(); i++) {
        int parent_u, parent_v;

        parent_u = find(graph[i].second.first);
        parent_v = find(graph[i].second.second);

        if (edge_count == vertics - 1) break;

        if (parent_u != parent_v) {
            setMST.push_back(graph[i]);
            parent[parent_u] = parent[parent_v];

            edge_count += 1;
        }
    }

};

void Graph::MSTCost() {
    double totalCost = 0;

    for (int i = 0; i < setMST.size(); i++) {
        cout << setMST[i].second.first << "<-->" << setMST[i].second.second << ", w:" << setMST[i].first << endl;
        totalCost += setMST[i].first;
    }
    cout << "MST count: " << setMST.size() << endl;
    cout << "average cost: " << totalCost / setMST.size();
};