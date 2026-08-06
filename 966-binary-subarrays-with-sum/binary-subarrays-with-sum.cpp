class Solution {
    int solve(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int cnt = 0, sum = 0;
        int r = 0, l = 0;
        int n = nums.size();

        while(r < n) {
            sum = sum + nums[r];

            while(sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};