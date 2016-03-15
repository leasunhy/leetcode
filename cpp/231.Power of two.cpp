// Date: 2016-03-15

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (-n & n) == n;
    }
};
