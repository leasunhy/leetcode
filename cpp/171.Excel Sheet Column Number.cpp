// Date: 2016-07-29

class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        int res = s.back() - 'A' + 1;
        int base = 26;
        for (int i = s.size() - 2; i >= 0; --i) {
            res += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return res;
    }
};

