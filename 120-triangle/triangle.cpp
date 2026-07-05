class Solution {
    int f(int i, int j, int n, vector<vector<int>>& arr, vector<vector<int>> &dp){
        if(i == n-1) return arr[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = arr[i][j] + f(i+1, j, n, arr, dp);
        int dg = arr[i][j] + f(i+1, j+1, n, arr, dp);

        return dp[i][j] = min(down, dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        return f(0,0,n,triangle,dp);
    }
};