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

    vector<pair<int, int>> repeatedCyclePrim() {
        vector<pair<int, int>> result;
        vector<bool> inTree(vertices, false);
        for (int i = 0; i < vertices; ++i) {
            if (!inTree[i]) {
                repeatedCyclePrimUtil(i, result, inTree);
            }
        }

        return result;
    }

private:
    void repeatedCyclePrimUtil(int start, vector<pair<int, int>>& result, vector<bool>& inTree) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(vertices, numeric_limits<int>::max());
        vector<int> parent(vertices, -1);

        pq.push(make_pair(0, start));
        key[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inTree[u] = true;

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inTree[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        for (int i = 0; i < vertices; ++i) {
            if (parent[i] != -1) {
                int weight = numeric_limits<int>::max();

                for (const auto& neighbor : adjList[i]) {
                    if (neighbor.first == parent[i]) {
                        weight = neighbor.second;
                        break;
                    }
                }

                if (weight != numeric_limits<int>::max()) {
                    result.emplace_back(parent[i], i);
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

    vector<pair<int, int>> repeatedCyclePrimResult = g.repeatedCyclePrim();

    cout << "Cac canh cua cay bao trum nhieu lan nhat nhat:\n";
    for (const auto& edge : repeatedCyclePrimResult) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}

