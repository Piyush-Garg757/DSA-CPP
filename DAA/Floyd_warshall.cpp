#include <bits/stdc++.h>
using namespace std;

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    vector<vector<int>> dist(v, vector<int>(v));

    cout << "Enter adjacency matrix (use 1e9 for INF):\n";
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> dist[i][j];

    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                if(dist[i][k] < 1e9 && dist[k][j] < 1e9)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << "All-pairs shortest path matrix:\n";
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}