class Solution {
public:
    string largestOddNumber(string s) {
        int len = s.length()-1;
        while(len>=0){
            int d = s[len] - '0';
            if((d % 2) != 0){
                return s.substr(0,len+1);
            }
            len--;
        }
        return "";
    }
};