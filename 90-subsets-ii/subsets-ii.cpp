class Solution {
public:

    void solve(int ind, vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        // base case
        if(ind == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // pick
        ds.push_back(nums[ind]);
        solve(ind + 1, nums, ds, ans);
        ds.pop_back();

        // not pick
        while(ind + 1 < nums.size() &&
              nums[ind] == nums[ind + 1]) {
            ind++;
        }

        solve(ind + 1, nums, ds, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};