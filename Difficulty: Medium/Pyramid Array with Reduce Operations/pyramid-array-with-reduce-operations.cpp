#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int formPyramid(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        // Calculate maximum left-increasing heights
        left[0] = std::min(arr[0], 1);
        for (int i = 1; i < n; ++i) {
            left[i] = std::min(arr[i], left[i - 1] + 1);
        }

        // Calculate maximum right-decreasing heights
        right[n - 1] = std::min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = std::min(arr[i], right[i + 1] + 1);
        }

        // Find the maximum peak height possible
        long long max_peak = 0;
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            total_sum += arr[i];
            long long possible_peak = std::min(left[i], right[i]);
            max_peak = std::max(max_peak, possible_peak);
        }

        // Minimum cost is total sum minus sum of max pyramid elements (which is max_peak^2)
        return total_sum - (max_peak * max_peak);
    }
};