class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        // Edge case: if m is greater than or equal to array size,
        // the bird can visit all trees.
        if (m >= n) {
            long long total_sum = 0;
            for (int val : arr) {
                total_sum += val;
            }
            return total_sum;
        }

        // Calculate sum for the first window of size m
        long long current_sum = 0;
        for (int i = 0; i < m; i++) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        // Slide the window across the circular array
        for (int i = 1; i < n; i++) {
            // Remove the element leaving the window: arr[i - 1]
            // Add the new element entering the window: arr[(i + m - 1) % n]
            current_sum = current_sum - arr[i - 1] + arr[(i + m - 1) % n];
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};