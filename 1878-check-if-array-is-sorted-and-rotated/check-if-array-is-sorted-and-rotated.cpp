class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(nums[n-1] > nums[0]) count++;
        int i = 0;
        while(i < n-1){
            if(nums[i] > nums[i+1]){
                count++;
            }
            i++;
        }
        return count <= 1;
    }
};
