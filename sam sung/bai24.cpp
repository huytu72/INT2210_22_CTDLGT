#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class BoruvkaMST {
private:
    struct Subset {
        int parent;
        int rank;
        int head;

        Subset() : parent(-1), rank(0), head(-1) {}
    };

    vector<Edge> edges;
    int vertices;
    vector<Subset> subsets;

public:
    BoruvkaMST(int V) : vertices(V) {
        subsets.resize(vertices);
        for (int i = 0; i < vertices; ++i) {
            subsets[i].head = i;
        }
    }

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    vector<Edge> findMST() {
        vector<Edge> result;

        while (result.size() < vertices - 1) {
            vector<int> cheapest(vertices, -1);

            for (const Edge& edge : edges) {
                int setU = findSet(edge.u);
                int setV = findSet(edge.v);

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
                    int setU = findSet(cheapest[i]);
                    int setV = findSet(cheapest[findHead(cheapest[i])]);

                    if (setU != setV) {
                        result.push_back(edges[cheapest[i]]);
                        mergeSets(setU, setV);
                    }
                }
            }
        }

        return result;
    }

private:
    int findSet(int i) {
        if (subsets[i].parent != -1) {
            return findSet(subsets[i].parent);
        }
        return i;
    }

    int findHead(int i) {
        return subsets[i].head;
    }

    void mergeSets(int x, int y) {
        int rootX = findSet(x);
        int rootY = findSet(y);

        if (rootX != rootY) {
            subsets[rootY].parent = rootX;

            int tailX = subsets[rootX].head;
            int tailY = subsets[rootY].head;

            subsets[rootY].head = tailX;
            subsets[tailX].head = tailY;
        }
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

    cout << "Minimum Spanning Tree (Boruvka with Doubly Linked Circular List):\n";
    for (const Edge& edge : mst) {
        cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << endl;
    }

    return 0;
}

