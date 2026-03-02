class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i=0; i<n; i++){
            if(maxIndex<i){
                return false;
            }
            maxIndex = max(i + nums[i],maxIndex);
        }
        return true;
    }
};