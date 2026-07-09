class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 ek baar already exist karta hai
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            // Agar (prefixSum - k) pehle mila hai,
            // to utni subarrays mil jayengi
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // Current prefix sum store karo
            mp[prefixSum]++;
        }

        return count;
    }
};