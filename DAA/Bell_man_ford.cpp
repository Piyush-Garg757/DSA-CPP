#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    for(int i = 1; i <= v - 1; i++) {
        for(auto ed : edges) {
            if(dist[ed.u] != INT_MAX && dist[ed.v] > dist[ed.u] + ed.w)
                dist[ed.v] = dist[ed.u] + ed.w;
        }
    }

    bool negCycle = false;
    for(auto ed : edges) {
        if(dist[ed.u] != INT_MAX && dist[ed.v] > dist[ed.u] + ed.w) {
            negCycle = true;
            break;
        }
    }

    if(negCycle) {
        cout << "Negative weight cycle detected";
    } else {
        cout << "Shortest distances from source:\n";
        for(int i = 0; i < v; i++)
            cout << "To " << i << " = " << dist[i] << endl;
    }
}