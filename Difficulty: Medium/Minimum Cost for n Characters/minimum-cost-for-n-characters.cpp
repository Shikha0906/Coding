class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        if (n == 0) return 0;

        vector<long long> dp(n + 1, 0);
        dp[1] = i;

        for (int k = 2; k <= n; k++) {
            if (k % 2 == 0) {
                dp[k] = min(dp[k - 1] + i, dp[k / 2] + c);
            } else {
                dp[k] = min(dp[k - 1] + i, dp[(k + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};