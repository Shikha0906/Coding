class Solution {
    public int findMinCost(String s1, String s2, int costS1, int costS2) {
        int m = s1.length();
        int n = s2.length();

        // DP table to store LCS lengths
        int[][] dp = new int[m + 1][n + 1];

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];

        // Calculate cost based on deletions required
        int cost1 = (m - lcsLength) * costS1;
        int cost2 = (n - lcsLength) * costS2;

        return cost1 + cost2;
    }
}