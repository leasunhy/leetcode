// Date: 2016-03-16

#include <numeric>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int x, int y){ return x ^ y; });
    }
};
