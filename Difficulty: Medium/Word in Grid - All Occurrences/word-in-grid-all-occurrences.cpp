#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();
        vector<vector<int>> result;

        // 8 possible directions: {row_change, col_change}
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Traverse each cell in lexicographical order (row major)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, check all 8 directions
                if (mat[i][j] == word[0]) {
                    bool found = false;

                    for (int dir = 0; dir < 8; dir++) {
                        int k;
                        int currX = i;
                        int currY = j;

                        // Check characters along the current direction
                        for (k = 0; k < len; k++) {
                            if (currX < 0 || currX >= n || currY < 0 || currY >= m || mat[currX][currY] != word[k]) {
                                break;
                            }
                            currX += dx[dir];
                            currY += dy[dir];
                        }

                        // If all characters matched in this direction
                        if (k == len) {
                            found = true;
                            break; // Stop checking other directions for this starting cell
                        }
                    }

                    if (found) {
                        result.push_back({i, j});
                    }
                }
            }
        }

        return result;
    }
};