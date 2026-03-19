class Solution {
private:
    int lowerbound(vector<int> &arr,int n, int x){
        sort(arr.begin(),arr.end());
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high -low)/2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxCount = 0;
        int rowIndex = 0;

        for(int i = 0; i < n; i++){
            
            int countOnes = m - lowerbound(mat[i],m,1);
            if(countOnes > maxCount){
                maxCount = countOnes;
                rowIndex = i;
            }
        }
        return {rowIndex, maxCount};
    }
};
