// Date: 2016-2-12

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        vector<int> prev(rowIndex + 1, 0);
        prev[0] = prev[1] = 1;
        vector<int> cur(rowIndex + 1, 0);
        cur[0] = cur[1] = 1;
        for (int i = 2; i <= rowIndex; ++i) {
            cur.swap(prev);
            for (int j = 1; j <= i; ++j)
                cur[j] = prev[j] + prev[j - 1];
        }
        return cur;
    }
};
