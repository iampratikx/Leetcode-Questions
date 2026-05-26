class Solution {
    void recurrPermutation(vector<int> &ds, vector<vector<int>>&ans, vector<int> freq, vector<int>& nums){
        if(nums.size() == ds.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurrPermutation(ds,ans,freq,nums);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        recurrPermutation(ds,ans,freq,nums);
        return ans;
    }
};