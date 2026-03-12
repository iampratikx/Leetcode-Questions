class Solution {
private:
    int findDays(vector<int>& weights, int cap, int n){
        int load = 0;
        int cnt = 1;
        for(int i = 0 ; i < n; i++){
            if(load + weights[i] > cap ){
                cnt = cnt + 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return cnt;
    }
    int maxi(vector<int>& weights, int n){
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(weights[i], maxi);
        }
        return maxi;
    }
    int sumW(vector<int>& weights, int n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
        }
        return sum;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n =  weights.size();
        int low = maxi(weights,n), high = sumW(weights,n);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int ndays = findDays( weights, mid, n);
            if(ndays <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};