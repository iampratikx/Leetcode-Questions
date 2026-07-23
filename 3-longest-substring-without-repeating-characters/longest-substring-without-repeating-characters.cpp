class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for(int i=0;i<s.length(); i++) {
            vector<int> arr(256,0);
            int len = 0;
            for(int j=i; j<s.length(); j++) {
                if(arr[s[j]] != 1) {
                    len++;
                    maxlen = max(len,maxlen);
                    arr[s[j]] = 1;
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};