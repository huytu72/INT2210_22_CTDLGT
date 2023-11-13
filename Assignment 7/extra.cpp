#include <bits/stdc++.h>

using namespace std;

int LCS(const vector<int>& a, const vector<int>& b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int m, n;
    cout << "Nhap do dai day a: ";
    cin >> m;
    cout << "Nhap do dai day b: ";
    cin >> n;

    vector<int> a(m);
    cout << "Nhap cac phan tu cua day a: ";
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    cout << "Nhap cac phan tu cua day b: ";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int result = LCS(a, b);
    cout << "Do dai cua day con chung dai nhat: " << result << endl;

    return 0;
}

