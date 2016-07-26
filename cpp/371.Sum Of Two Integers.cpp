// Date: 2016-07-26

class Solution {
public:
    int getSum(int aa, int bb) {
        unsigned a = (unsigned)aa, b = (unsigned)bb;
        int c = 2, res = a ^ b;
        while (c) {
            if ((a & 1) && (b & 1)) {
                int toadd = c;
                while (res & toadd) {
                    res &= ~toadd;
                    toadd <<= 1;
                }
                res |= toadd;
            }
            cout << c << " : " << res << endl;
            a >>= 1, b >>= 1, c <<= 1;
        }
        return res;
    }
};

