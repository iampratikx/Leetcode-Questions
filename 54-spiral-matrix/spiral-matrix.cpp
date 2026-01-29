class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total  = row*col;
        int count = 0;
        // index
        int StartingRow = 0;
        int StartingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        while(count<total){
            // print Starting Row
            for(int i = StartingCol; count<total && i<=endingCol; i++){
                ans.push_back(matrix[StartingRow][i]);
                count++;
            }
            StartingRow++;
            for(int i = StartingRow; count<total && i<=endingRow; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            for(int i = endingCol; count<total && i>=StartingCol; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            for(int i = endingRow; count<total && i>=StartingRow; i--){
                ans.push_back(matrix[i][StartingCol]);
                count++;
            }
            StartingCol++;

        }  
        return ans; 
    }
};