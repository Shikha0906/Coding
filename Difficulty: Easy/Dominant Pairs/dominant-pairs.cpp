#include <vector>
#include <algorithm>

class Solution {
public:
    int dominantPairs(std::vector<int> &arr) {
        int n = arr.size();
        int mid = n / 2;

        // Sort first half and second half independently
        std::sort(arr.begin(), arr.begin() + mid);
        std::sort(arr.begin() + mid, arr.end());

        int count = 0;
        int j = mid;

        // Two-pointer search
        for (int i = 0; i < mid; ++i) {
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            count += (j - mid);
        }

        return count;
    }
};