#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int p, vector<vector<int>>& adj, vector<int>& vis, vector<int>& par, vector<int>& cycle) {
    vis[u] = 1;

    for(int x : adj[u]) {
        if(!vis[x]) {
            par[x] = u;
            if(dfs(x, u, adj, vis, par, cycle)) return true;
        }
        else if(x != p) {
            int cur = u;
            cycle.push_back(x);
            while(cur != x) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(x);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    return false;
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

    vector<int> vis(v, 0), par(v, -1), cycle;

    for(int i = 0; i < v; i++) {
        if(!vis[i] && dfs(i, -1, adj, vis, par, cycle)) break;
    }

    if(cycle.empty()) {
        cout << "No cycle";
    } else {
        cout << "Cycle: ";
        for(int x : cycle) cout << x << " ";
    }
}