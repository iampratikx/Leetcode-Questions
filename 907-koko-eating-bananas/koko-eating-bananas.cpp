class Solution {
private:
    long long totalTime(vector<int>& piles, int mid){
        long long totalH = 0;

        for(int i = 0; i < piles.size(); i++){
            totalH += (long long)(piles[i] + mid - 1) / mid;
        }

        return totalH;
    }

    int maxii(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long reqTime = 0;  
        int high = maxii(piles);
        int low = 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            reqTime = totalTime(piles, mid);

            if(reqTime <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};