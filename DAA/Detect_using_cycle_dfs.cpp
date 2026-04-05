#include <bits/stdc++.h>
using namespace std;

vector<int> parent, cycle;

bool dfs(int node, int par, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    parent[node] = par;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != par)
        {
            for (int curr = node; curr != neighbor; curr = parent[curr])
                cycle.push_back(curr);
            cycle.push_back(neighbor);
            cycle.push_back(node);
            return true;
        }
    }
    return false;
}

bool detectCycle(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    parent.assign(V, -1);
    for (int i = 0; i < V; i++)
        if (!visited[i] && dfs(i, -1, adj, visited))
            return true;
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (detectCycle(V, adj))
    {
        cout << "Cycle Detected\nCycle: ";
        for (int node : cycle)
            cout << node << " ";
    }
    else
        cout << "No Cycle\n";
}