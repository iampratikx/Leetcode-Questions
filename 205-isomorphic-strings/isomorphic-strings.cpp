class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length()){
            return false;
        }

        map <char,char> mpp1,mpp2;
        for(int i=0; i<s.length(); i++){
            if(mpp1[s[i]] == 0 && mpp2[t[i]] == 0){
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
            if(mpp1[s[i]] != t[i] && mpp2[t[i]] != s[i]){
                return false;
            }
        }
        return true;

    }
};