// Date: 2016-2-12

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {};
        if (numRows == 1) return {{1}};
        auto previous = generate(numRows - 1);
        auto& prevRow = previous[numRows - 2];
        vector<int> thisRow(numRows);
        thisRow[0] = thisRow[numRows - 1] = 1;
        for (size_t i = 1; i < numRows - 1; ++i)
            thisRow[i] = prevRow[i - 1] + prevRow[i];
        previous.push_back(thisRow);
        return previous;
    }
};
