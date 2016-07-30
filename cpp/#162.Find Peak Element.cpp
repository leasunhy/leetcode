// Date: 2016-07-30

// find a peak element that is larger than its immediate neighbors.
//   This solution uses binary search.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1, len = nums.size();
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

