// Date: 2016-03-15

#include <set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> occurence;
        for (auto n : nums)
            if (!occurence.insert(n).second)
                return true;
        return false;
    }
};
