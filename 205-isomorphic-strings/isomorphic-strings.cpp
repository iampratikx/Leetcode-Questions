class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length()){
            return false;
        }

        map<char, char> mpp1, mpp2;

        for(int i = 0; i < s.length(); i++) {

            // agar dono me mapping nahi hai
            if(!mpp1.count(s[i]) && !mpp2.count(t[i])) {
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
            // agar mismatch mila
            else if(mpp1[s[i]] != t[i] || mpp2[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};