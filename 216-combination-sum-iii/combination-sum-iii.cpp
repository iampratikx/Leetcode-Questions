class Solution {
    void CombSum(int idx,
                 vector<int>& arr,
                 vector<vector<int>>& ans,
                 vector<int>& ds,
                 int sum,
                 int group,
                 int s) {

        // GALTI 1:
        // tumne pehle "=" lagaya tha
        // if(group = ds.size())
        // yaha comparison ke liye "==" lagega

        if (group == ds.size()) {

            // agar size k ke equal ho gayi
            // aur sum bhi equal hai to answer me push karo
            if (s == sum) {
                ans.push_back(ds);
            }
            return;
        }

        // array khatam ho gaya
        if (idx == arr.size()) {
            return;
        }

        // GALTI 2:
        // tumhari pruning condition galat thi
        // if(arr[idx] < s && sum < s)

        // actual me hame current sum check karna tha
        // agar sum target se bada ho gaya to return
        if (s > sum) return;

        // GALTI 3:
        // tum "i" use kar rahe the
        // but recursion me variable "idx" hai

        // PICK
        ds.push_back(arr[idx]);

        CombSum(idx + 1,
                 arr,
                 ans,
                 ds,
                 sum,
                 group,
                 s + arr[idx]);

        ds.pop_back();

        // NOT PICK
        CombSum(idx + 1,
                 arr,
                 ans,
                 ds,
                 sum,
                 group,
                 s);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        vector<int> arr(9);

        // GALTI 4:
        // tum arr[i] = i kar rahe the
        // usse 0-8 ban raha tha

        // question me 1-9 chahiye
        for (int i = 0; i < 9; i++) {
            arr[i] = i + 1;
        }

        CombSum(0, arr, ans, ds, n, k, 0);

        return ans;
    }
};