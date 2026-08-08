class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int cnt = 0;
        int sIdx = -1;

        unordered_map<char, int> mp;

        for(char ch : t) {
            mp[ch]++;
        }

        while(r < s.size()) {

            if(mp[s[r]] > 0)
                cnt++;

            mp[s[r]]--;

            while(cnt == t.size()) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIdx = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};