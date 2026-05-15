
class Solution {
public:

    int findMin(vector<int>& nums) {

        int n = nums.size();

        // Agar sirf 1 element hai
        if(n == 1) {
            return nums[0];
        }

        int s = 0, e = n - 2;

        // Array already sorted hai
        if(nums[0] < nums[n - 1]) {
            return nums[0];
        }

        while(s <= e) {

            int mid = s + (e - s) / 2;

            // Rotation point mila
            if(nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // Left side sorted hai
            if(nums[mid] >= nums[0]) {
                s = mid + 1;
            }

            // Minimum left side me hai
            else {
                e = mid - 1;
            }
        }

        return -1;
    }
};
/*
class Solution {
public:

    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        // Binary Search
        while(left < right) {

            int mid = left + (right - left) / 2;

            // Minimum right side me hai
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Minimum mid ya left side me hai
            else {
                right = mid;
            }
        }

        // left == right -> minimum element
        return nums[left];
    }
};
*/