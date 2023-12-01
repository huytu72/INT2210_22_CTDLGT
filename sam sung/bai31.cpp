#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct Edge {
    int from, to;
    int weight;

    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjList;

    Graph(int V) : vertices(V), adjList(V + 1) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(u, v, weight);
    }

    vector<int> bellmanFord(int start) {
        vector<int> dist(vertices, numeric_limits<int>::max());
        dist[start] = 0;

        for (int i = 0; i < vertices - 1; ++i) {
            for (int u = 1; u <= vertices; ++u) {
                for (const Edge& edge : adjList[u]) {
                    int v = edge.to;
                    int weight = edge.weight;

                    if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }

    void reweightGraph(const vector<int>& pi) {
        for (int u = 1; u <= vertices; ++u) {
            for (Edge& edge : adjList[u]) {
                edge.weight += pi[u] - pi[edge.to];
            }
        }
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 4);
    g.addEdge(3, 6, 2);

    int startVertex = 1;
    vector<int> pi = g.bellmanFord(startVertex);
    g.reweightGraph(pi);


    return 0;
}

