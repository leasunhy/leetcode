// Date: 2016-07-30

// num & -num gives the least significant bit. It's the trick used in Fenwick Tree.
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && num == (num & -num & 0x55555555);
    }
};

