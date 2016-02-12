// Date: 2016-2-13

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int i = 0; i < 9; ++i)
            if (!isValid(board, i, i + 1, 0, 9))
                return false;

        // columns
        for (int j = 0; j < 9; ++j)
            if (!isValid(board, 0, 9, j, j + 1))
                return false;

        // boxes
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!isValid(board, i * 3, i * 3 + 3, j * 3, j * 3 + 3))
                    return false;

        return true;
    }
    
private:
    bool isValid(const vector<vector<char>>& board, int starti, int endi, int startj, int endj) {
        unordered_set<char> s;
        for (size_t i = starti; i < endi; ++i) {
            for (size_t j = startj; j < endj; ++j) {
                char c = board[i][j];
                if (c != '.' && s.find(c) != s.end())
                    return false;
                s.insert(c);
            }
        }
        return true;
    }
};

