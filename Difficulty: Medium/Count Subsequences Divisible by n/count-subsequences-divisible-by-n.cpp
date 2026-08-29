class Solution {
public:
    int countSubsequences(string& s, int n) {
        int MOD = 1e9 + 7;
        int len = s.length();

        // dp[r] will store the count of subsequences with remainder r modulo n
        vector<int> dp(n, 0);

        for (char c : s) {
            int digit = c - '0';
            vector<int> next_dp = dp;

            // 1. Include current digit into existing subsequences
            for (int r = 0; r < n; r++) {
                if (dp[r] > 0) {
                    int next_rem = (r * 10 + digit) % n;
                    next_dp[next_rem] = (next_dp[next_rem] + dp[r]) % MOD;
                }
            }

            // 2. Start a new single-digit subsequence
            int single_rem = digit % n;
            next_dp[single_rem] = (next_dp[single_rem] + 1) % MOD;

            dp = next_dp;
        }

        // Remainder 0 corresponds to subsequences divisible by n
        return dp[0];
    }
};