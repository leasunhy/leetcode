// Date: 2016-07-30

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

