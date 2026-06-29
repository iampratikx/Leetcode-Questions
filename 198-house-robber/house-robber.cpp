class Solution {
    private:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i == 0) return nums[i];
        if(i < 1) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = solve(i - 2, nums, dp) + nums[i];
        int notpick = solve(i - 1, nums, dp) + 0;

        return dp[i] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
    }
};