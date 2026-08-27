class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Compute consecutive 1s in each column up to row i
        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j];
            for (int i = 1; i < n; ++i) {
                hist[i][j] = (mat[i][j] == 0) ? 0 : hist[i - 1][j] + 1;
            }
        }

        int max_area = 0;

        // Step 2 & 3: Sort each row and calculate the maximum rectangle area
        for (int i = 0; i < n; ++i) {
            // Count frequencies of height values (Counting Sort for O(m) row processing)
            vector<int> count(n + 1, 0);
            for (int j = 0; j < m; ++j) {
                count[hist[i][j]]++;
            }

            // Reconstruct sorted row in descending order
            int col_idx = 0;
            for (int h = n; h >= 0; --h) {
                while (count[h] > 0) {
                    hist[i][col_idx] = h;
                    col_idx++;
                    count[h]--;
                }
            }

            // Calculate area for row i
            for (int j = 0; j < m; ++j) {
                int area = hist[i][j] * (j + 1);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};