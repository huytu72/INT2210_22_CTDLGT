#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int vertices;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int V) : vertices(V) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(weight, make_pair(u, v));
    }

    vector<pair<int, pair<int, int>>> boruvkaMST() {
        vector<pair<int, pair<int, int>>> result;
        vector<int> parent(vertices, -1);

        while (result.size() < vertices - 1) {
            vector<int> cheapest(vertices, -1);

            for (const auto& edge : edges) {
                int setU = find(parent, edge.second.first);
                int setV = find(parent, edge.second.second);

                if (setU != setV) {
                    if (cheapest[setU] == -1 || edge.first < edges[cheapest[setU]].first) {
                        cheapest[setU] = edge.second.second;
                    }
                    if (cheapest[setV] == -1 || edge.first < edges[cheapest[setV]].first) {
                        cheapest[setV] = edge.second.first;
                    }
                }
            }

            for (int i = 0; i < vertices; ++i) {
                if (cheapest[i] != -1) {
                    int setU = find(parent, edges[cheapest[i]].second.first);
                    int setV = find(parent, edges[cheapest[i]].second.second);

                    if (setU != setV) {
                        result.push_back(edges[cheapest[i]]);
                        unionSets(parent, setU, setV);
                    }
                }
            }
        }

        return result;
    }

private:
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int setX = find(parent, x);
        int setY = find(parent, y);
        parent[setX] = setY;
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

    vector<pair<int, int>> boruvkaResult = g.boruvkaMST();

    cout << "Cac canh cua cay bao trum min:\n";
    for (const auto& edge : boruvkaResult) {
        cout << edge.second.first << " - " << edge.second.second << endl;
    }

    return 0;
}

