class Solution {
    void dfs(int row, int col, int color, vector<vector<int>>& grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int initialCol = grid[row][col];
        grid[row][col] = color;
        queue<pair<int,int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == initialCol &&
                !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = color;
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr,sc,color,image,vis);
        return image;
    }
};