// Date: 2016-07-29

#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        size_t i = 0, j = 0;
        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i, ++j;
                while (i < nums1.size() && nums1[i - 1] == nums1[i]) ++i;
                while (j < nums2.size() && nums2[j - 1] == nums2[j]) ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};

