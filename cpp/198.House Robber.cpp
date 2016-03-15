// Date: 2016-03-15

#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> robbed(n);
        robbed[0] = nums[0];
        vector<int> notrobbed(n);
        for (int i = 1; i < n; ++i) {
            robbed[i] = notrobbed[i - 1] + nums[i];
            notrobbed[i] = std::max(robbed[i - 1], notrobbed[i - 1]);
        }
        return std::max(robbed[n - 1], notrobbed[n - 1]);
    }
};
