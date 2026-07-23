class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, l=0, r=0;
        int n = s.length();
        vector<int> mp(256, -1);
        while(r < n) {
            if(mp[s[r]] != -1) {
                if(mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
            }
            int len = r-l+1;
            maxlen = max(maxlen, len);
            mp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};