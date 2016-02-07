// Date: 2016-2-7

#include <numeric>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return std::accumulate(strs.begin() + 1, strs.end(), strs.front(), commonPrefix);
    }
private:
    static string commonPrefix(const string& s1, const string& s2) {
        string res;
        for (size_t i = 0; i < s1.size() && i < s2.size(); ++i) {
            if (s1[i] != s2[i]) break;
            res.push_back(s1[i]);
        }
        return res;
    }
};
