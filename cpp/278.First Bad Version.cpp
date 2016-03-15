// Date: 2016-03-15

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))
            return 1;
        long long left = 1, right = n, mid;
        while (right - left > 1)
            if (isBadVersion(mid = (left + right) / 2))
                right = mid;
            else
                left = mid;
        return right;
    }
};

