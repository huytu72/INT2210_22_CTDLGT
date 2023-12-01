#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int vertices;
    vector<vector<int>> dist;

    Graph(int V) : vertices(V), dist(V, vector<int>(V, INF)) {}

    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
        dist[v][u] = weight;
    }

    void preprocess() {
        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int shortestDistance(int u, int v) {
        return dist[u][v];
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(4, 0, 50);

    g.preprocess();

    int u = 1, v = 3;
    int distance = g.shortestDistance(u, v);

    cout << "Shortest distance between vertex " << u << " and " << v << ": " << distance << endl;

    return 0;
}

