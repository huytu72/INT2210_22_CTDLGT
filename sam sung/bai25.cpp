#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);

    vector<Edge> lazyPrimMST(int start) {
        vector<Edge> result;
        vector<bool> inMST(vertices, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            int key = pq.top().first;
            pq.pop();

            if (inMST[u]) {
                continue;
            }

            inMST[u] = true;
            result.emplace_back(u, key);

            for (const Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                if (!inMST[v]) {
                    pq.push({weight, v});
                }
            }
        }

        return result;
    }
};

int main() {
    int V = 1000000;
    Graph g(V);

    for (int i = 0; i < V - 1; ++i) {
        g.addEdge(i, i + 1, rand() % 100 + 1);
    }

    int startVertex = 0;
    vector<Edge> mst = g.lazyPrimMST(startVertex);

    cout << "Minimum Spanning Tree (Lazy Prim):\n";
    for (const Edge& edge : mst) {
        cout << "Edge: " << edge.to << " Weight: " << edge.weight << endl;
    }

    return 0;
}

