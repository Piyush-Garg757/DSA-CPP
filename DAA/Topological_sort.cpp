#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(v);
    vector<int> indeg(v, 0);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        indeg[w]++;
    }

    queue<int> q;
    for(int i = 0; i < v; i++)
        if(indeg[i] == 0) q.push(i);

    vector<int> topo;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int x : adj[u]) {
            indeg[x]--;
            if(indeg[x] == 0) q.push(x);
        }
    }

    if(topo.size() != v) {
        cout << "Cycle detected, topological sort not possible";
    } else {
        cout << "Topological order: ";
        for(int x : topo) cout << x << " ";
    }
}