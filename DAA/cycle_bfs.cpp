#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, vector<vector<int>>& adj, vector<int>& vis, vector<int>& par, vector<int>& cycle) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    par[s] = -1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int x : adj[u]) {
            if(!vis[x]) {
                vis[x] = 1;
                par[x] = u;
                q.push(x);
            }
            else if(x != par[u]) {
                vector<int> path1, path2;
                int a = u, b = x;

                while(a != -1) {
                    path1.push_back(a);
                    a = par[a];
                }
                while(b != -1) {
                    path2.push_back(b);
                    b = par[b];
                }

                reverse(path1.begin(), path1.end());
                reverse(path2.begin(), path2.end());

                int i = 0;
                while(i < path1.size() && i < path2.size() && path1[i] == path2[i]) i++;

                for(int j = path1.size() - 1; j >= i; j--) cycle.push_back(path1[j]);
                for(int j = i - 1; j < path2.size(); j++) cycle.push_back(path2[j]);

                return true;
            }
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
        if(!vis[i] && bfs(i, adj, vis, par, cycle)) break;
    }

    if(cycle.empty()) {
        cout << "No cycle";
    } else {
        cout << "Cycle: ";
        for(int x : cycle) cout << x << " ";
    }
}