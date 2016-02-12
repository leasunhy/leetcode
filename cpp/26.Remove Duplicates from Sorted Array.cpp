// Date: 2016-2-12

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 1, cur = 0;
        while (i != nums.size()) {
            while (i != nums.size() && nums[i] == nums[cur]) ++i;
            if (i == nums.size()) break;
            nums[++cur] = nums[i];
        }
        return cur + 1;
    }
};

