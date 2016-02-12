// Date: 2016-2-12

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        for (size_t i = 0; i != nums.size(); ++i) {
            if (val != nums[i])
                nums[cur++] = nums[i];
        }
        return cur;
    }
};
