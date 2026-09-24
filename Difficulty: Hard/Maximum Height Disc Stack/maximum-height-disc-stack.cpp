#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int bit[1005][1005];
    int maxR = 1000, maxH = 1000;

    void update(int r, int h, int val) {
        for (int i = r; i <= maxR; i += i & -i) {
            for (int j = h; j <= maxH; j += j & -j) {
                bit[i][j] = max(bit[i][j], val);
            }
        }
    }

    int query(int r, int h) {
        int max_val = 0;
        for (int i = r; i > 0; i -= i & -i) {
            for (int j = h; j > 0; j -= j & -j) {
                max_val = max(max_val, bit[i][j]);
            }
        }
        return max_val;
    }

public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();
        vector<pair<pair<int, int>, int>> discs(n);

        for (int i = 0; i < n; i++) {
            discs[i] = {{r[i], h[i]}, i};
        }

        // Sort by radius, then height
        sort(discs.begin(), discs.end());

        // Reset Fenwick Tree array
        for (int i = 0; i <= maxR; i++) {
            for (int j = 0; j <= maxH; j++) {
                bit[i][j] = 0;
            }
        }

        int totalMax = 0;

        // Process discs group by group with strictly smaller radius
        int i = 0;
        while (i < n) {
            int j = i;
            // Find all discs with the exact same radius
            while (j < n && discs[j].first.first == discs[i].first.first) {
                j++;
            }

            vector<pair<pair<int, int>, int>> current_dp;
            for (int k = i; k < j; k++) {
                int radius = discs[k].first.first;
                int height = discs[k].first.second;

                // Query for strictly smaller radius (radius - 1) and height (height - 1)
                int max_prev = query(radius - 1, height - 1);
                int dp_val = max_prev + height;

                current_dp.push_back({{radius, height}, dp_val});
                totalMax = max(totalMax, dp_val);
            }

            // Batch update BIT after calculating all discs of current radius
            // to enforce strict inequality on radius
            for (auto &p : current_dp) {
                update(p.first.first, p.first.second, p.second);
            }

            i = j;
        }

        return totalMax;
    }
};