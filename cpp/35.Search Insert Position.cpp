// Date: 2017-07-10

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return target > nums[0];

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = nums[mid];
            if (value == target)
                return mid;
            else if (value < target)
                left = mid + 1;
            else
                right = mid - 1; 
        }
        return left;
    }
};
