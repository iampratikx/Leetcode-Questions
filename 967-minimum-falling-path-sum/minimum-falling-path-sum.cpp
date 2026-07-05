class Solution {
    int f(int i, int j, int n, int m, vector<vector<int>>& arr,
          vector<vector<int>>& dp) {

        if (j < 0 || j >= m) return 1e9;
        if (i == 0) return arr[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int up = arr[i][j] + f(i - 1, j, n, m, arr, dp);
        int leftDiagonal = arr[i][j] + f(i - 1, j - 1, n, m, arr, dp);
        int rightDiagonal = arr[i][j] + f(i - 1, j + 1, n, m, arr, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            mini = min(mini, f(n - 1, j, n, m, matrix, dp));
        }

        return mini;
    }
};