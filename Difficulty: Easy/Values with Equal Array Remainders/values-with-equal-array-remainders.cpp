#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int sameMod(std::vector<int> &arr) {
        int n = arr.size();

        // Find the overall GCD of differences
        int g = 0;
        for (int i = 1; i < n; ++i) {
            g = std::gcd(g, std::abs(arr[i] - arr[0]));
        }

        // If g is still 0, all elements are identical
        if (g == 0) {
            return -1;
        }

        // Count all divisors of g
        int divisor_count = 0;
        for (int i = 1; i * i <= g; ++i) {
            if (g % i == 0) {
                if (i * i == g) {
                    divisor_count += 1;
                } else {
                    divisor_count += 2;
                }
            }
        }

        return divisor_count;
    }
};