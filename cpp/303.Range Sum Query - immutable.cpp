// Date: 2016-3-15

class NumArray {
public:
    vector<long long> prefixSum;
    NumArray(vector<int> &nums) : prefixSum(nums.size()) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            prefixSum[i] = (sum += nums[i]);
    }

    int sumRange(int i, int j) {
        return i == 0 ? prefixSum[j] : (prefixSum[j] - prefixSum[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
