#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int,int>>> adj(v);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++) {
        int u, w, wt;
        cin >> u >> w >> wt;
        adj[u].push_back({w, wt});
        adj[w].push_back({u, wt});
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto x : adj[u]) {
            int vtx = x.first, wt = x.second;
            if(dist[vtx] > dist[u] + wt) {
                dist[vtx] = dist[u] + wt;
                pq.push({dist[vtx], vtx});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < v; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}