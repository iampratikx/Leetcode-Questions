class Solution {
private:
    vector<int> leftMax(vector<int>& height,int n){
        vector<int> lMax(n);
        int maxi = height[0];
        for(int i = 0; i<n; i++){
            maxi = max(maxi,height[i]);
            lMax[i] = maxi;
        }
        return lMax;
    }
    vector<int> rightMax(vector<int>& height, int n){
        vector<int> rMax(n);
        int maxi = height[n-1];
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi,height[i]);
            rMax[i] = maxi;
        }
        return rMax;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> leftMaxarr;
        vector<int> rightMaxarr;

        leftMaxarr = leftMax(height,n);
        rightMaxarr = rightMax(height,n);
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += min(leftMaxarr[i],rightMaxarr[i]) - height[i];
        }
        return sum;
    }
};