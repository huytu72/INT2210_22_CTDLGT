#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS(int v, unordered_map<int, bool>& visited) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    bool isConnected() {
        unordered_map<int, bool> visited;

        auto it = adjList.begin();
        int startVertex = it->first;

        DFS(startVertex, visited);

        for (it = adjList.begin(); it != adjList.end(); it++) {
            if (visited[it->first] == false) {
                return false;
            }
        }

        return true;
    }

    int inOutDegreeDifference(int v) {
        return adjList[v].size() - getInDegree(v);
    }

    int getInDegree(int v) {
        int inDegree = 0;

        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            for (int neighbor : it->second) {
                if (neighbor == v) {
                    inDegree++;
                }
            }
        }

        return inDegree;
    }

    void findEulerianCycle() {
        if (!isConnected()) {
            cout << "Khong ton tai chu trinh Euler.\n";
            return;
        }

        stack<int> currentPath;
        list<int> eulerianCycle;

        auto it = adjList.begin();
        int currentVertex = it->first;

        currentPath.push(currentVertex);

        while (!currentPath.empty()) {
            if (inOutDegreeDifference(currentPath.top()) == 0) {
                eulerianCycle.push_back(currentPath.top());
                currentPath.pop();
            } else {
                int nextVertex = adjList[currentPath.top()].front();
                currentPath.push(nextVertex);
                adjList[currentPath.top()].pop_front();
            }
        }

        cout << "Chu trinh Euler: ";
        for (int vertex : eulerianCycle) {
            cout << vertex << " -> ";
        }
        cout << "End\n";
    }
};

int main() {
    Graph g;

    g.findEulerianCycle();

    return 0;
}
