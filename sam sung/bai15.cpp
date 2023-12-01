#include <iostream>
#include <vector>
#include <queue>

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

        queue<int> q;
        for (int i = 0; i < vertices; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (int neighbor : adjList[u]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != vertices) {
            cout << "Do thi co chu trinh, khong the sap xep topo.\n";
            return vector<int>();
        }

        return result;
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> topOrder = g.topologicalSort();

    if (!topOrder.empty()) {
        cout << "Thu tu to po: ";
        for (int vertex : topOrder) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
