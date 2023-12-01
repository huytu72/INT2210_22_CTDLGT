#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    vector<pair<int, int>> primMST() {
        vector<pair<int, int>> result;
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                primUtil(i, result, visited);
            }
        }

        return result;
    }

private:
    void primUtil(int start, vector<pair<int, int>>& result, vector<bool>& visited) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        visited[start] = true;

        for (const auto& neighbor : adjList[start]) {
            pq.push(neighbor);
        }

        while (!pq.empty()) {
            int u = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            if (!visited[u]) {
                visited[u] = true;
                result.emplace_back(start, u);

                for (const auto& neighbor : adjList[u]) {
                    pq.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1, 7);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 3, 9);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 15);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 8);
    g.addEdge(4, 6, 9);
    g.addEdge(5, 6, 11);

    vector<pair<int, int>> primResult = g.primMST();

    cout << "Cac canh cua cay bao trum nho nhat:\n";
    for (const auto& edge : primResult) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}

