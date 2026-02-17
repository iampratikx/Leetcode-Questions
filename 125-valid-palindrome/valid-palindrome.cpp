bool palindrom(int i,string &s,int n){
    if(i>=n/2){
        return true;
    }
    if(s[i] != s[n-i-1]){
        return false;;
    }
    return palindrom(i+1,s,n);
}
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(remove_if(s.begin(), s.end(),
                      [](char c) { return !isalnum(c); }),
            s.end());

        int n = s.size();
        return palindrom(0,s,n);
    }
};