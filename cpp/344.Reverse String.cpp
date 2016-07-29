// Date: 2016-07-29

#include <algorithm>

class Solution {
public:
    string reverseString(string s) {
        string res = s;
        std::reverse(res.begin(), res.end());
        return res;
    }
};

