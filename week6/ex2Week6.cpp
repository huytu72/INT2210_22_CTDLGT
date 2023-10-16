#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int INF = INT_MAX;

int dijkstra(int n, int m, int X, int Y, vector<pair<int, int>> edges) {
    // danh sách kề
    unordered_map<int, vector<pair<int, int>>> graph;
    for (auto edge : edges) {
        graph[edge.first].push_back({edge.second, 1}); // các cạnh có trọng số là 1
    }

    // khoảng cách ngắn nhất từ điểm đầu đến các điểm khác
    vector<int> dist(n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, X}); // khoảng cách từ điểm xuất phát đến nó là 0
    dist[X] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u == Y) {
            return dist[Y];
        }

        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (u_dist + weight < dist[v]) {
                dist[v] = u_dist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return -1; // nếu không có đường đi từ X đến Y
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    int result = dijkstra(n, m, X, Y, edges);
    cout << result << endl;

    return 0;
}
