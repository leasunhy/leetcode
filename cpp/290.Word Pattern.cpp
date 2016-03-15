// Date: 2016-3-15

#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> p2s;
        map<string, char> s2p;
        if (pattern.size() != count(str.begin(), str.end(), ' ') + 1)
            return false;
        size_t lastIndex = 0;
        size_t spaceIndex = str.find_first_of(' ', 0);
        for (size_t i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            string token = str.substr(lastIndex, spaceIndex == string::npos ? string::npos : spaceIndex - lastIndex);
            if (token.empty()) return false;

            if (p2s.find(p) != p2s.end() && p2s[p] != token) return false;
            if (s2p.find(token) != s2p.end() && s2p[token] != p) return false;
            p2s[p] = token;
            s2p[token] = p;

            if (spaceIndex == string::npos)
                break;

            lastIndex = spaceIndex + 1;
            spaceIndex = str.find_first_of(' ', lastIndex);
        }
        return true;
    }
};
