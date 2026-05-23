class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> ds;
        findComb(0,n,candidates,target,ans,ds);
        return ans;

    }
    void findComb(int i,int n, vector<int>& arr, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(i == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //pick element
        if(target >= arr[i]){
            ds.push_back(arr[i]);
            findComb(i,n,arr,target-arr[i],ans,ds);
            ds.pop_back();
        }
        findComb(i+1,n,arr,target,ans,ds);
    }
};