#include <vector>
using std::vector;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> occurence(256, -1);
        int len = 0;
        int current_start = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (occurence[c] >= current_start) {
                if (i - current_start > len)
                    len = i - current_start;
                current_start = occurence[c] + 1;
            }
            occurence[c] = i;
        }
        if (s.length() - current_start > len)
            len = s.length() - current_start;
        return len;
    }
};

