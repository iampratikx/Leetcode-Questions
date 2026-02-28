class Solution {
private:
    int charToroman(char ch){
        if (ch == 'I') return 1;
        else if (ch == 'V') return 5;
        else if (ch == 'X') return 10;
        else if (ch == 'L') return 50;
        else if (ch == 'C') return 100;
        else if (ch == 'D') return 500;
        else if (ch == 'M') return 1000;
        else return 0;
    }
public:
    int romanToInt(string s) {
        int number = 0;

        for(int i=0; i<s.length(); i++){
            
            if(i+1 < s.length() && charToroman(s[i]) < charToroman(s[i+1])){
                number = number + charToroman(s[i+1]) - charToroman(s[i]);
                i++;
            }
            else{
                number = number + charToroman(s[i]);
            }
        }
        return number;
    }
};