#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int findPar(int x, vector<int>& p) {
    if(p[x] == x) return x;
    return p[x] = findPar(p[x], p);
}

void unionSet(int a, int b, vector<int>& p, vector<int>& r) {
    a = findPar(a, p);
    b = findPar(b, p);
    if(a != b) {
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
    }
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(v), rank(v, 0);
    for(int i = 0; i < v; i++) parent[i] = i;

    int cost = 0;
    cout << "Edges in MST:\n";

    for(auto &ed : edges) {
        if(findPar(ed.u, parent) != findPar(ed.v, parent)) {
            cout << ed.u << " - " << ed.v << " : " << ed.w << endl;
            cost += ed.w;
            unionSet(ed.u, ed.v, parent, rank);
        }
    }

    cout << "Total cost: " << cost;
}