// Date: 2016-3-15

#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        for (auto c : s)
            ms[c] += 1;
        for (auto c : t)
            mt[c] += 1;
        return ms == mt;
    }
};
