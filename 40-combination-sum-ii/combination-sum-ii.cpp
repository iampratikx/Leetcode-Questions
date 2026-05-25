class Solution {
public:
void findComb(int idx,vector<int>& arr, int target, vector<int>&ds, vector<vector<int>> &ans ){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int j = idx; j<arr.size(); j++){
            if(target < arr[j]){
                break;
            }
            if(j>idx && arr[j] == arr[j-1]){
                continue;
            }
            ds.push_back(arr[j]);
            findComb(j+1, arr, target- arr[j], ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;

        findComb(0, candidates, target, ds, ans);
        return ans;
    }
};
