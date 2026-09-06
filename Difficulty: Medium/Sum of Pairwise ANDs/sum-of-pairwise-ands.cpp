class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long totalSum = 0;
        int n = arr.size();

        // Check each bit position from 0 to 31
        for (int k = 0; k < 32; k++) {
            long long count = 0;

            // Count numbers with the k-th bit set
            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << k)) {
                    count++;
                }
            }

            // Calculate pairs formed by these numbers
            long long pairs = (count * (count - 1)) / 2;

            // Add contribution of the k-th bit to total sum
            totalSum += pairs * (1LL << k);
        }

        return totalSum;
    }
};