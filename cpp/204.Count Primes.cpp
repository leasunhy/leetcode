// Date: 2016-03-15

#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        bool *sieve = new bool[n];
        for (int i = 2; i < n; ++i)
            sieve[i] = true;
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!sieve[i]) continue;
            count += 1;
            for (int j = 2 * i; j < n; j += i)
                sieve[j] = false;
        }
        delete [] sieve;
        return count;
    }
};
