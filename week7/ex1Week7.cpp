#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void topologicalSort(int n, unordered_map<int, vector<int>>& graph, vector<int>& indegree) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    ofstream outFile("jobs.out");
    for (int job : result) {
        outFile << job << " ";
    }
    outFile.close();
}

int main() {
    ifstream inFile("jobs.txt");
    int n, m;
    inFile >> n >> m;

    unordered_map<int, vector<int>> graph;
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        inFile >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    inFile.close();

    topologicalSort(n, graph, indegree);

    return 0;
}

