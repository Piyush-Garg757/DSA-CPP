#include <bits/stdc++.h>
using namespace std;

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
    queue<int> q;

    q.push(s);
    vis[s] = 1;

    cout << "BFS traversal: ";

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int x : adj[u]) {
            if(!vis[x]) {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
}