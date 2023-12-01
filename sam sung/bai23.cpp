#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

class BoruvkaMST {
private:
    vector<Edge> edges;
    int vertices;

public:
    BoruvkaMST(int V) : vertices(V) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    vector<Edge> findMST() {
        vector<Edge> result;

        while (result.size() < vertices - 1) {
            vector<int> cheapest(vertices, -1);

            for (const Edge& edge : edges) {
                int setU = findSet(cheapest, edge.u);
                int setV = findSet(cheapest, edge.v);

                if (setU != setV) {
                    if (cheapest[setU] == -1 || edges[cheapest[setU]].weight > edge.weight) {
                        cheapest[setU] = edge.u;
                    }
                    if (cheapest[setV] == -1 || edges[cheapest[setV]].weight > edge.weight) {
                        cheapest[setV] = edge.v;
                    }
                }
            }

            for (int i = 0; i < vertices; ++i) {
                if (cheapest[i] != -1) {
                    int setU = findSet(cheapest, i);
                    int setV = findSet(cheapest, cheapest[i]);

                    if (setU != setV) {
                        result.push_back(edges[cheapest[i]]);
                        unionSets(cheapest, setU, setV);
                    }
                }
            }
        }

        return result;
    }

private:
    int findSet(const vector<int>& cheapest, int i) {
        if (cheapest[i] == -1) {
            return i;
        }
        return findSet(cheapest, cheapest[i]);
    }

    void unionSets(vector<int>& cheapest, int x, int y) {
        int rootX = findSet(cheapest, x);
        int rootY = findSet(cheapest, y);
        cheapest[rootY] = rootX;
    }
};

int main() {
    BoruvkaMST boruvka(4);

    boruvka.addEdge(0, 1, 1);
    boruvka.addEdge(0, 2, 2);
    boruvka.addEdge(1, 2, 3);
    boruvka.addEdge(1, 3, 4);
    boruvka.addEdge(2, 3, 5);

    vector<Edge> mst = boruvka.findMST();

    cout << "Minimum Spanning Tree (Boruvka):\n";
    for (const Edge& edge : mst) {
        cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << endl;
    }

    return 0;
}

