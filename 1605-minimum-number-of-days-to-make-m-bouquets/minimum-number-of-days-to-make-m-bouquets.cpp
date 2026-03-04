class Solution {
private:
    bool canItmake(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int bouquets  = 0;
        for(int i=0;i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            }
            else cnt = 0;
        }
        if(bouquets>=m) return true;
        else return false;
        
    }
    int maxii(vector<int>& bloomDay){
        int maxi = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long anss = (long long) m * k;
        if(bloomDay.size() < anss) return -1;
        int maxi = maxii(bloomDay);
        int low = 1;
        int high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canItmake(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
 
    }
};