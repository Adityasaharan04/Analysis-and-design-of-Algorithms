//shortest path
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Since the graph is undirected
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 4);

    int src = 0; // Source vertex
    g.dijkstra(src);

    return 0;
}
