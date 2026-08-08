class Solution {
    int solve(vector<int>& nums, int k) {
        int cnt = 0;
        int r = 0, l = 0;
        int n = nums.size();
        map<int,int> mp;
        while(r < n) {
            mp[nums[r]]++;
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};