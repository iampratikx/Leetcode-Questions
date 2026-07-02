class Solution {
    private:
    int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>>&mat){
        if(i>=0 && j>=0 && mat[i][j] == 1) return 0;
        if(i<0 || j<0){
            return 0;
        }
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1,j,dp,mat);
        int left = f(i,j-1,dp,mat);
        return dp[i][j] = (up + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();

        vector<vector<int>> dp(i,vector<int>(j,-1));
        return f(i-1,j-1,dp,obstacleGrid);
    }
};