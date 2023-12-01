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

    int dijkstraShortestPath(int start, const vector<int>& S, const vector<int>& T) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(vertices, numeric_limits<int>::max());

        for (int s : S) {
            pq.push({0, s});
            dist[s] = 0;
        }

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

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int minDistanceToT = numeric_limits<int>::max();
        for (int t : T) {
            minDistanceToT = min(minDistanceToT, dist[t]);
        }

        return minDistanceToT;
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

    vector<int> S = {1, 3};
    vector<int> T = {4, 5};

    int shortestPath = g.dijkstraShortestPath(1, S, T);

    cout << "Shortest path: " << shortestPath << endl;

    return 0;
}

