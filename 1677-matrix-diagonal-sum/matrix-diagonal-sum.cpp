long long leftDiagonal(vector<vector<int>>& mat,int row, int col){
    long long priSum = 0;
    int i = 0, j = 0;
    while(i < row && j < col){
        priSum = priSum + mat[i][j];
        i++;
        j++;
    }
    return priSum;
}
long long rightDiagonal(vector<vector<int>>& mat,int row, int col){
    long long secNum = 0;
    int i = 0, j = col - 1;
    while(i < row && j >= 0){
        secNum = secNum + mat[i][j];
        i++;
        j--;
    }
    return secNum;
}
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        long long finalSum;
        if(row%2!=0){
            finalSum = leftDiagonal(mat,row,col) + rightDiagonal(mat,row,col)-
            mat[(row-1)/2][(row-1)/2];
        }
        else finalSum = leftDiagonal(mat,row,col) + rightDiagonal(mat,row,col);
        return (int)finalSum;
    }
};
