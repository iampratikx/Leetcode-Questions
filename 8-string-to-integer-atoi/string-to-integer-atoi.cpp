class Solution {
public:
    int myAtoi(string s) {

        if(s.length() == 0) return 0;

        int i = 0;

        // remove spaces
        while(i < s.size() && s[i] == ' ') {
            i++;
        }

        s = s.substr(i);

        if(s.length() == 0) return 0;

        int sign = 1;
        long result = 0;

        i = 0;

        // sign handling
        if(s[0] == '-') {
            sign = -1;
            i++;
        }
        else if(s[0] == '+') {
            i++;
        }

        // skip leading zeroes
        while(i < s.size() && s[i] == '0') {
            i++;
        }

        // number conversion
        if(i < s.size() && s[i] >= '0' && s[i] <= '9') {

            while(i < s.size() && s[i] >= '0' && s[i] <= '9') {

                int num = s[i] - '0';

                result = result * 10 + num;

                // overflow handling
                if(sign == 1 && result > INT_MAX)
                    return INT_MAX;

                if(sign == -1 && -result < INT_MIN)
                    return INT_MIN;

                i++;
            }

            return result * sign;
        }

        return 0;
    }
};