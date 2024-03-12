//UNION FIND DETECT CYCLE
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each node is initially its own parent
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]); // Path compression
    }

    void unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv])
                swap(pu, pv);
            parent[pv] = pu;
            if (rank[pu] == rank[pv])
                rank[pu]++;
        }
    }
};

bool hasCycle(vector<pair<int, int>>& edges, int V) {
    UnionFind uf(V);
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        int pu = uf.find(u);
        int pv = uf.find(v);
        if (pu == pv) // Both vertices are in the same set, forming a cycle
            return true;
        uf.unionSets(u, v);
    }
    return false;
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}}; // Edges of the graph

    if (hasCycle(edges, V))
        cout << "Graph contains a cycle.\n";
    else
        cout << "Graph does not contain a cycle.\n";

    return 0;
}
