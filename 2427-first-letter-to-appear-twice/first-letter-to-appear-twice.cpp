class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mpp;
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(mpp[s[i]] == 1){
                return s[i];
            }
            else{
                mpp[s[i]]++;
            }
        }
        return -1;
    }
};