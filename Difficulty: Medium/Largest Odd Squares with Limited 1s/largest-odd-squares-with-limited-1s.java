import java.util.*;

class Solution {
    public List<Integer> largestSquare(int[][] mat, int[][] queries, int k) {
        int n = mat.length;
        int m = mat[0].length;

        // Build 2D prefix sum
        int[][] prefix = new int[n + 1][m + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] =
                    mat[i][j]
                    + prefix[i][j + 1]
                    + prefix[i + 1][j]
                    - prefix[i][j];
            }
        }

        List<Integer> ans = new ArrayList<>();

        for (int[] query : queries) {
            int r = query[0];
            int c = query[1];

            // Maximum possible radius
            int maxRadius = Math.min(
                Math.min(r, n - 1 - r),
                Math.min(c, m - 1 - c)
            );

            // Check 1 x 1 square
            if (mat[r][c] > k) {
                ans.add(-1);
                continue;
            }

            int low = 0;
            int high = maxRadius;
            int best = 0;

            // Binary search for largest valid radius
            while (low <= high) {
                int radius = low + (high - low) / 2;

                int r1 = r - radius;
                int c1 = c - radius;
                int r2 = r + radius;
                int c2 = c + radius;

                // Count 1s in current square
                int ones = prefix[r2 + 1][c2 + 1]
                         - prefix[r1][c2 + 1]
                         - prefix[r2 + 1][c1]
                         + prefix[r1][c1];

                if (ones <= k) {
                    best = radius;
                    low = radius + 1;
                } else {
                    high = radius - 1;
                }
            }

            // radius -> side length
            ans.add(2 * best + 1);
        }

        return ans;
    }
}