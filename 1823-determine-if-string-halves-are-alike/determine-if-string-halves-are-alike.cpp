class Solution {
    bool isVowels(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
public:
    bool halvesAreAlike(string s) {
        int i = 0, j = s.length() / 2;
        int countA = 0, countB = 0;
        while(i < s.length()/2){
            if(isVowels(s[i])) countA++;
            if(isVowels(s[j])) countB++;

            i++;
            j++;
        }
        return countA == countB;
    }
};