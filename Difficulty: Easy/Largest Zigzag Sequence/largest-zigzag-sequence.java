class Solution {
    public int zigzagSequence(int[][] mat) {
        int n = mat.length;

        int[][] dp = new int[n][n];

        // First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {

            // Find largest and second largest
            // value in the previous row
            int max1 = Integer.MIN_VALUE;
            int max2 = Integer.MIN_VALUE;
            int maxIndex = -1;

            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] > max1) {
                    max2 = max1;
                    max1 = dp[i - 1][j];
                    maxIndex = j;
                } else if (dp[i - 1][j] > max2) {
                    max2 = dp[i - 1][j];
                }
            }

            // Current row
            for (int j = 0; j < n; j++) {
                if (j == maxIndex) {
                    dp[i][j] = mat[i][j] + max2;
                } else {
                    dp[i][j] = mat[i][j] + max1;
                }
            }
        }

        // Maximum value in the last row
        int ans = Integer.MIN_VALUE;

        for (int j = 0; j < n; j++) {
            ans = Math.max(ans, dp[n - 1][j]);
        }

        return ans;
    }
}