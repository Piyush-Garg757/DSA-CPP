#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    }
                    else if (neighbor != parent[node])
                    {
                        vector<int> path1, path2;

                        for (int curr1 = node; curr1 != -1; curr1 = parent[curr1])
                            path1.push_back(curr1);
                        for (int curr2 = neighbor; curr2 != -1; curr2 = parent[curr2])
                            path2.push_back(curr2);

                        reverse(path1.begin(), path1.end());
                        reverse(path2.begin(), path2.end());

                        int lca = -1, len = min(path1.size(), path2.size());
                        for (int i = 0; i < len; i++)
                        {
                            if (path1[i] == path2[i])
                                lca = path1[i];
                            else
                                break;
                        }

                        vector<int> cycle;
                        for (int temp = node; temp != lca; temp = parent[temp])
                            cycle.push_back(temp);
                        cycle.push_back(lca);

                        vector<int> tempPath;
                        for (int temp = neighbor; temp != lca; temp = parent[temp])
                            tempPath.push_back(temp);
                        reverse(tempPath.begin(), tempPath.end());

                        for (int x : tempPath)
                            cycle.push_back(x);
                        cycle.push_back(node);

                        cout << "Cycle Detected\nCycle: ";
                        for (int x : cycle)
                            cout << x << " ";
                        cout << endl;

                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;01
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (!detectCycle(V, adj))
        cout << "No Cycle\n";
}