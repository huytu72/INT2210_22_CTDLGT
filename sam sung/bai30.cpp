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

    Graph(int V) : vertices(V + 1), adjList(V + 1) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
    }

    vector<int> longestPath(int start) {
        priority_queue<pair<int, int>> pq;
        vector<int> dist(vertices, numeric_limits<int>::min());

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) {
                continue;
            }

            for (const Edge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] + weight > dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 5, 1);
    vector<int> longestDistances = g.longestPath(startVertex);

    cout << "Longest distances from vertex " << startVertex << " to other vertices:\n";
    for (int i = 1; i <= V; ++i) {
        cout << "Vertex " << i << ": " << longestDistances[i] << endl;
    }

    return 0;
}

