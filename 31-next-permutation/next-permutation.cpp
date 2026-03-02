class Solution {
private:
    void reverseArr(vector<int>& nums,int s, int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: Find breakpoint
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        // If no breakpoint
        if(index == -1){
            reverseArr(nums,0,n-1);
            return;
        }

        // Step 2: Find just greater element
        for(int i=n-1; i>index; i--){
            if(nums[index]<nums[i]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        // Step 3: Reverse remaining part
        reverseArr(nums,index+1,n-1);
    }
};