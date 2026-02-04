int lowerbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int lbindex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) lbindex = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return lbindex;
}

int upperbound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int upindex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) upindex = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return upindex;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstindex = lowerbound(nums, target);
        int lastindex = upperbound(nums, target);
        return {firstindex, lastindex};
    }
};
