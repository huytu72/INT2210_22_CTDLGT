#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> adj[10001];
bool visited[10001];

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    //cout << u << " ";
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void connectedComponent() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            res++;
            dfs(i);
        }
    }
    cout << res;
}
int main() {
    input();
    connectedComponent();
    return 0;
}
