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

    vector<int> key(v, INT_MAX), par(v, -1);
    vector<int> vis(v, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto x : adj[u]) {
            int vtx = x.first, wt = x.second;
            if(!vis[vtx] && wt < key[vtx]) {
                key[vtx] = wt;
                par[vtx] = u;
                pq.push({key[vtx], vtx});
            }
        }
    }

    int cost = 0;
    cout << "Edges in MST:\n";
    for(int i = 1; i < v; i++) {
        cout << par[i] << " - " << i << " : " << key[i] << endl;
        cost += key[i];
    }

    cout << "Total cost: " << cost;
}