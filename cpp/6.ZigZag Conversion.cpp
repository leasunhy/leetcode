// Date: 2016-2-5

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ans;
        ans.push_back(s[0]);
        int distance = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i) {
            int offset = i * 2;
            for (int j = i; j < s.length(); j += offset) {
                if (offset != 0)
                    ans.push_back(s[j]);
                offset = distance - offset;
            }
        }
        return ans;
    }
};

