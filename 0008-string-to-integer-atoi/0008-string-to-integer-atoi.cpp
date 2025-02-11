class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        bool isNeg = false;
        int i = 0, n = s.size();
        bool mark = false;

        while(i < n && s[i] == ' ') i++;

        while(i < n && (s[i] == '-' || s[i] == '+') && !mark){
            isNeg = (s[i] == '-');
            mark = true;
            i++;
        }

        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
            
            if(num > INT_MAX){
                return isNeg ? INT_MIN : INT_MAX;
            }
            i++;
        }

        return isNeg? -num : num;
    }
};