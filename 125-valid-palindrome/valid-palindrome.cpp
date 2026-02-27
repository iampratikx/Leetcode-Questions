class Solution {
private:
    bool valid(char s){
        if((s >='a' && s <='z' ) || (s >='A' && s <='Z') || (s >='0' && s <='9')){
            return true;
        }
        else{
            return false;
        }
    }
    char uperTolower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9')){
            return ch;
        }
        else{
            char temp  = ch - 'A' + 'a';
            return temp;
        }
    }
    bool Palindrome(string temp){
        int s = 0;
        int e = temp.length() - 1;
        while(s<e){
            if(temp[s] != temp[e]){
                return false;
            }
            else{
                s++,e--;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i<s.length(); i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for(int i = 0; i<temp.length(); i++){
            temp[i] = uperTolower(temp[i]);
        }
        return Palindrome(temp);
    }
};