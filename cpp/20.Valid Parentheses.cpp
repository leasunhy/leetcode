// Date: 2016-2-6

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ps;
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    ps.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if (!checkAndRemove(ps, c)) return false;
                    break;
            }
        }
        return ps.empty();
    }
private:
    bool checkAndRemove(std::stack<char>& ps, char c) {
        if (ps.empty()) return false;
        if (c == ')' && ps.top() != '(') return false;
        if (c == '}' && ps.top() != '{') return false;
        if (c == ']' && ps.top() != '[') return false;
        ps.pop();
        return true;
    }
};
