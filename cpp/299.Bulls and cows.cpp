// Date: 2016-3-15


#include <sstream>
#include <vector>

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        std::vector<int> used(secret.size());
        for (size_t i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                A += 1;
                used[i] = 1;
            }
        }
        for (size_t i = 0; i < guess.size(); ++i) {
            if (used[i] == 1) continue;
            for (size_t j = 0; j < secret.size(); ++j) {
                if (guess[i] != secret[j] || used[j]) continue;
                B += 1;
                used[j] = 2;
                break;
            }
        }
        std::stringstream ss;
        ss << A << "A" << B << "B";
        return ss.str();
    }
};
