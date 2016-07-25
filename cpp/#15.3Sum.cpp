// Date: 2016-07-26

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                size_t l = i + 1, r = nums.size() - 1;
                int s = -nums[i];
                while (l < r) {
                    if (nums[l] + nums[r] == s) {
                        res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) ++l;
                        while (l < r && nums[r] == nums[r - 1]) --r;
                        ++l, --r;
                    } else if (nums[l] + nums[r] < s) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};

