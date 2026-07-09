class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& arr,
          int m, int n, vector<vector<vector<int>>>& dp) 
    {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e8;
        }

        if(i == n - 1) {
            if(j1 == j2)
                return arr[i][j1];
            else
                return arr[i][j1] + arr[i][j2];
        }

        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
            
        int maxi = -1e8;   //  Har recursive call ka apna local maximum

        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {

                if(j1 == j2) {
                    maxi = max(maxi,
                               arr[i][j1] +
                               f(i + 1, j1 + dj1, j2 + dj2,
                                 arr, m, n, dp));  
                }
                else {
                    maxi = max(maxi,
                               arr[i][j1] + arr[i][j2] +
                               f(i + 1, j1 + dj1, j2 + dj2,
                                 arr, m, n, dp));  
                }
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m, -1)));
        // Agar memoization karoge to dp 3D hona chahiye: dp[n][m][m]

        return f(0, 0, m - 1, grid, m, n, dp);
        //  Robot 2 ko last column (m-1) se start karna hai.
    }
};