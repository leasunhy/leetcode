// Date: 2016-03-15

class Solution {
public:
    int addDigits(int num) {
        return num ? (num % 9 ? num % 9 : 9) : 0;
    }
};
