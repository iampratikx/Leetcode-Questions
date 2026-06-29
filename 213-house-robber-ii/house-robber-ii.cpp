class Solution {
public:
    vector<int> dp;
    int helper(vector<int> & nums, int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + helper(nums,i+2);
        int leave = helper(nums,i+1);

        return dp[i] = max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        vector<int > temp1;
        vector<int > temp2;
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0)
                temp1.push_back(nums[i]);   // first house remove

            if(i != n-1)
                temp2.push_back(nums[i]);   // last house remove
        }
        dp.assign(temp1.size(), -1);
        int ans1 = helper(temp1,0);

        dp.assign(temp2.size(), -1);
        int ans2 = helper(temp2,0);

        return max(ans1, ans2);
    }
};