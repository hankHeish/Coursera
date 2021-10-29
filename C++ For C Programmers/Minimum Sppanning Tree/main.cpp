#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;

int main() {
    ifstream fin;
    fin.open("/Users/Heishminghan/C++ For C Programmers/MST/map.txt");

    int u, v, w, V;
    int path_count = 0;
    if (!fin.is_open()) {
        cout << "Failed Open!!!";
    } else {
        fin >> V;
        // cout << V << endl;
        Graph G(V);

        while (!fin.eof()) {
            fin >> u >> v >> w;
            G.addEdge(u, v, w);
            path_count += 1;
        }
        cout << "Total paths:" << path_count << endl;
        // G.printGrapah();
        G.KruskalMST();
        G.MSTCost();
    }

    return 0;
}
