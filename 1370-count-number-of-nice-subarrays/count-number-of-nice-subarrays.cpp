class Solution {
    int solve(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int cnt = 0, sum = 0;
        int r = 0, l = 0;
        int n = nums.size();

        while(r < n) {
            sum = sum + nums[r] % 2;

            while(sum > goal) {
                sum = sum - nums[l] % 2;
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};