// Date: 2016-03-15

#include <map>
using std::map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s2t;
        map<char, char> t2s;
        for (size_t i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];
            if ((s2t.find(c1) != s2t.end() && s2t[c1] != c2) ||
                (t2s.find(c2) != t2s.end() && t2s[c2] != c1))
                return false;
            s2t[c1] = c2;
            t2s[c2] = c1;
        }
        return true;
    }
};
