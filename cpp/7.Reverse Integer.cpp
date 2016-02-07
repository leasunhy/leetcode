// Date: 2016-2-6

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int res = 0;
        while (x != 0) {
            if (res > 214748364) return 0;  // overflow
            res *= 10;
            if (res < 0) return 0;  // overflow
            res += x % 10;
            if (res < 0) return 0;  // overflow
            x /= 10;
        }
        return res * sign;
    }
};
