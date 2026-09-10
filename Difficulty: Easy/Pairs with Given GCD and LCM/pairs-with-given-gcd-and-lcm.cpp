#include <numeric>

class Solution {
  public:
    int pairCount(int x, int y) {
        if (y % x != 0) return 0;

        int k = y / x;
        int count = 0;

        for (int p = 1; p * p <= k; p++) {
            if (k % p == 0) {
                int q = k / p;
                if (std::gcd(p, q) == 1) {
                    if (p == q) {
                        count += 1;
                    } else {
                        count += 2;
                    }
                }
            }
        }

        return count;
    }
};