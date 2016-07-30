// Date: 2016-07-30

class Solution {
public:
    int climbStairs(int n) {
        // fibonacci
        int a = 1, b = 2;
        for (int i = 1; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};

