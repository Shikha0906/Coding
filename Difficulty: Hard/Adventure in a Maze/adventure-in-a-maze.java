import java.util.*;

class Solution {

    public ArrayList<Integer> findWays(int[][] matrix) {
        int n = matrix.length;
        int MOD = 1000000007;

        long[][] paths = new long[n][n];
        int[][] adventure = new int[n][n];

        // Exit cell
        paths[n - 1][n - 1] = 1;
        adventure[n - 1][n - 1] = matrix[n - 1][n - 1];

        // Bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == n - 1 && j == n - 1) {
                    continue;
                }

                long totalPaths = 0;
                int bestAdventure = -1;

                // Right
                if ((matrix[i][j] == 1 || matrix[i][j] == 3)
                        && j + 1 < n) {

                    totalPaths = (totalPaths + paths[i][j + 1]) % MOD;

                    if (paths[i][j + 1] > 0) {
                        bestAdventure = Math.max(
                            bestAdventure,
                            adventure[i][j + 1]
                        );
                    }
                }

                // Down
                if ((matrix[i][j] == 2 || matrix[i][j] == 3)
                        && i + 1 < n) {

                    totalPaths = (totalPaths + paths[i + 1][j]) % MOD;

                    if (paths[i + 1][j] > 0) {
                        bestAdventure = Math.max(
                            bestAdventure,
                            adventure[i + 1][j]
                        );
                    }
                }

                paths[i][j] = totalPaths;

                // Only calculate Adventure if a valid path exists
                if (bestAdventure != -1) {
                    adventure[i][j] = matrix[i][j] + bestAdventure;
                }
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();

        // No path from Entry to Exit
        if (paths[0][0] == 0) {
            ans.add(0);
            ans.add(0);
        } else {
            ans.add((int) paths[0][0]);
            ans.add(adventure[0][0]);
        }

        return ans;
    }
}