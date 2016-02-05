// Date: 2016-2-5

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> indices;
        for (size_t i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            auto iter = indices.find(target - num);
            if (iter != indices.end())
                return {iter->second + 1, i + 1};
            indices[num] = i;
        }
    }
};

