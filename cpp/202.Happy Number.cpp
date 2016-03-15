// Date: 2016-03-15

#include <set>
using std::set;

class Solution {
public:
    bool isHappy(int n) {
        set<int> occured;
        while (true) {
            int s = sumOfDigitSquared(n);
            if (s == 1)
                return true;
            else if (!occured.insert(s).second)
                return false;
            n = s;
        }
    }
private:
    int sumOfDigitSquared(int n) {
        int sum = 0;
        while (n != 0) {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
};
