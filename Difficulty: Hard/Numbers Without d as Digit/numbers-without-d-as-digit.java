import java.util.Arrays;

class Solution {
    private Integer[][][] dp;

    public int countWithout(int n, int d) {
        if (n <= 0) return 0;

        String s = String.valueOf(n);
        int len = s.length();

        // dp[index][tight][leading_zero]
        dp = new Integer[len][2][2];

        // Solve for [0, n] without digit d, then subtract 1 to exclude '0'
        return solve(s, d, 0, 1, 1) - 1;
    }

    private int solve(String s, int d, int idx, int tight, int leadingZero) {
        if (idx == s.length()) {
            return 1;
        }

        if (dp[idx][tight][leadingZero] != null) {
            return dp[idx][tight][leadingZero];
        }

        int limit = (tight == 1) ? (s.charAt(idx) - '0') : 9;
        int count = 0;

        for (int digit = 0; digit <= limit; digit++) {
            // Skip the digit 'd' ONLY if it's an actual digit of the number,
            // NOT a leading padding zero.
            if (digit == d && !(leadingZero == 1 && digit == 0)) {
                continue;
            }

            int nextTight = (tight == 1 && digit == limit) ? 1 : 0;
            int nextLeadingZero = (leadingZero == 1 && digit == 0) ? 1 : 0;

            count += solve(s, d, idx + 1, nextTight, nextLeadingZero);
        }

        return dp[idx][tight][leadingZero] = count;
    }
}