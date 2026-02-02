int binarySearchRecursion(vector<int>& nums,int low,int high, int target){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(target==nums[mid]){
        return mid;
    }
    if(target>nums[mid]){
        return binarySearchRecursion(nums,mid+1,high,target);
    }
    else{
        return binarySearchRecursion(nums,low,mid-1,target);
    }

}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        return binarySearchRecursion(nums,low,high,target);
    }
};