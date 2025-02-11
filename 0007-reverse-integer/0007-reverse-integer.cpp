class Solution {
public:
    int reverse(int x) {
        long long num = 0;

        while(x != 0) {
            int digit = x % 10;
            x /= 10;

            num = num * 10 + digit;

            if(num > INT_MAX || num < INT_MIN) return 0;
        }

        return (int)num;
    }
};