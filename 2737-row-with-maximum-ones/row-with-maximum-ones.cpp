class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxCount = 0;
        int rowIndex = 0;

        for(int i = 0; i < n; i++){
            
            int countOnes = 0;
            
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1)
                    countOnes++;
            }

            if(countOnes > maxCount){
                maxCount = countOnes;
                rowIndex = i;
            }
        }

        return {rowIndex, maxCount};
    }
};
