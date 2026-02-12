class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i]!=nums[j]){
                i++;
               nums[i]=nums[j];
               
            }
        }
        nums.resize(i+1);
        return(nums.size());
    }
};