// Date: 2016-2-12

#include <sstream>

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        std::stringstream ss;
        size_t i = 0;
        while (i < prev.size()) {
            char c = prev[i];
            size_t j = i + 1;
            while (j < prev.size() && prev[j] == c)
                ++j;
            ss << j - i << c;
            i = j;
        }
        return ss.str();
    }
};
