#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(vertices, 0);

        for (int i = 0; i < vertices; ++i) {
            for (int neighbor : adjList[i]) {
                inDegree[neighbor]++;
            }
        }
        stack<int> s;
        for (int i = 0; i < vertices; ++i) {
            if (inDegree[i] == 0) {
                s.push(i);
            }
        }
        vector<int> topOrder;
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            topOrder.push_back(u);

            for (int neighbor : adjList[u]) {
                if (--inDegree[neighbor] == 0) {
                    s.push(neighbor);
                }
            }
        }

        return topOrder;
    }

    bool hasUniquePath() {
        vector<int> topOrder = topologicalSort();
        for (int i = 0; i < topOrder.size() - 1; ++i) {
            int u = topOrder[i];
            int v = topOrder[i + 1];

            bool edgeExists = false;
            for (int neighbor : adjList[u]) {
                if (neighbor == v) {
                    edgeExists = true;
                    break;
                }
            }

            if (!edgeExists) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if (g.hasUniquePath()) {
        cout << "Tồn tại đường đi đi qua mỗi đỉnh đúng một lần.\n";
    } else {
        cout << "Không tồn tại đường đi đi qua mỗi đỉnh đúng một lần.\n";
    }

    return 0;
}
