#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for(int x : adj[u]) {
        if(!vis[x]) dfs(x, adj, vis);
    }
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(v);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int s;
    cout << "Enter starting vertex: ";
    cin >> s;

    vector<int> vis(v, 0);

    cout << "DFS traversal: ";
    dfs(s, adj, vis);
}