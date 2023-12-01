#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findShortestPath(vector<vector<int>>& matrix) {
    int N = matrix.size();

    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][0] = matrix[0][0];

    for (int j = 1; j < N; ++j) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }


    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[N - 1][N - 1];
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int shortestPath = findShortestPath(matrix);

    cout << "Độ dài đường đi ngắn nhất: " << shortestPath << endl;

    return 0;
}

