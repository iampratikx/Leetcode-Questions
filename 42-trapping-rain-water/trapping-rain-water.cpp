class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while(l < r){
            lmax = max(lmax,h[l]);
            rmax = max(rmax,h[r]);

            if(lmax < rmax){
                ans += lmax - h[l];
                l++;
            }
            else{
                ans += rmax - h[r];
                r--;
            }
        }
        return ans;
    }
};

/* 
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
*/