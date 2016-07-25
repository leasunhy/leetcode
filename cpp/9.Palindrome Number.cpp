// Date: 2016-07-26
// Checks if an int is a palindrome.
//   Solution: reverse half of the number and then compare it with the remainder.
//             In such way, we successfully avoid the problem of possible overflow.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev) || (x == rev / 10);
    }
};

