class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        vector<int> freq(26, 0);

        // count characters of s
        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // subtract using t
        for(int i = 0; i < t.length(); i++) {
            freq[t[i] - 'a']--;

            // agar kisi ka count negative ho gaya → mismatch
            if(freq[t[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};