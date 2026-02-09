class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int minele = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // duplicate ambiguity case
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                minele = min(minele, nums[mid]);
                low++;
                high--;
            }
            // left part sorted
            else if (nums[low] <= nums[mid]) {
                minele = min(minele, nums[low]);
                low = mid + 1;
            }
            // right part sorted, min in left
            else {
                minele = min(minele, nums[mid]);
                high = mid - 1;
            }
        }
        return minele;
    }
};
