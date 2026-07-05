class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2; i>=0; i--){
            for(int k = i; k>=0; k--){
                int d = triangle[i][k] + dp[i+1][k];
                int dg = triangle[i][k] + dp[i+1][k+1];
                dp[i][k] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};