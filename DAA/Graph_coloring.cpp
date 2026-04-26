#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>>& g, vector<int>& color, int c, int v) {
    for(int k = 0; k < v; k++)
        if(g[node][k] && color[k] == c) return false;
    return true;
}

bool solve(int node, vector<vector<int>>& g, int m, vector<int>& color, int v) {
    if(node == v) return true;

    for(int c = 1; c <= m; c++) {
        if(isSafe(node, g, color, c, v)) {
            color[node] = c;
            if(solve(node + 1, g, m, color, v)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    vector<vector<int>> g(v, vector<int>(v));
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> g[i][j];

    int m;
    cout << "Enter number of colors: ";
    cin >> m;

    vector<int> color(v, 0);

    if(solve(0, g, m, color, v)) {
        cout << "Coloring:\n";
        for(int i = 0; i < v; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    } else {
        cout << "No solution exists";
    }
}