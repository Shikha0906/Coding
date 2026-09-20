class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;

        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> top(n, vector<int>(n, 0));

        // Precompute consecutive 'X' counts for left and top directions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X') {
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                    top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
                }
            }
        }

        int max_size = 0;

        // Iterate from bottom-right corner upwards/leftwards
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int k = min(left[i][j], top[i][j]);

                // Check if all four sides have length at least k
                while (k > max_size) {
                    if (left[i - k + 1][j] >= k && top[i][j - k + 1] >= k) {
                        max_size = max(max_size, k);
                        break;
                    }
                    k--;
                }
            }
        }

        return max_size;
    }
};