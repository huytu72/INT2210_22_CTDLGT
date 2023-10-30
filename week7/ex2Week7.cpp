#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    ifstream inFile("connection.txt");
    int n, m;
    inFile >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        inFile >> edges[i].u >> edges[i].v >> edges[i].cost;
    }
    inFile.close();

    sort(edges.begin(), edges.end());

    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int totalCost = 0;
    vector<Edge> resultEdges;

    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            totalCost += edge.cost;
            resultEdges.push_back(edge);
            unionSets(edge.u, edge.v);
        }
    }

    ofstream outFile("connection.out");
    outFile << totalCost << endl;
    for (const Edge& edge : resultEdges) {
        outFile << edge.u << " " << edge.v << " " << edge.cost << endl;
    }
    outFile.close();

    return 0;
}

