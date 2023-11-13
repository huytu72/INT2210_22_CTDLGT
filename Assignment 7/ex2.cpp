#include <bits/stdc++.h>

using namespace std;

int knapsackDynamic(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 5, 7, 1, 4, 1};
    vector<int> values = {10, 5, 15, 7, 8, 9, 2};
    int capacity = 10;

    int result = knapsackDynamic(weights, values, capacity);

    cout << "Maximum total value: " << result << endl;

    return 0;
}

