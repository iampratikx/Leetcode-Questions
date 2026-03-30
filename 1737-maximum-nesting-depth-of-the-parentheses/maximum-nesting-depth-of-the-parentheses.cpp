class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int result = 0;
        int n = s.length();
        for (int i =0; i<n; i++){
            if(s[i] == '('){
                curr++;
                if(curr > result) result = curr;
            }
            else if(s[i] == ')'){
                curr--;
            }
        }
        return result;
    }
};