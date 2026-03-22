class Solution {
private:
    string reverseWord(string ch){
        int s = 0;
        int e = ch.length()-1;
        while(s<=e){
            swap(ch[s],ch[e]);
            s++;
            e--;
        }
        return ch;
    }
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            ans += reverseWord(temp) + " ";
        }
        ans.pop_back();
        return ans;
    }
};