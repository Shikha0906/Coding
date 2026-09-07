#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int dp[101][102][102];

    int solve(int i, int inc, int dec, vector<int>& arr) {
        if (i == arr.size()) return 0;
        if (dp[i][inc][dec] != -1) return dp[i][inc][dec];

        // Choice 1: Do not include arr[i] in any subsequence
        int ans = solve(i + 1, inc, dec, arr);

        // Choice 2: Add arr[i] to the strictly increasing subsequence
        if (arr[i] > inc) {
            ans = max(ans, 1 + solve(i + 1, arr[i], dec, arr));
        }

        // Choice 3: Add arr[i] to the strictly decreasing subsequence
        if (arr[i] < dec) {
            ans = max(ans, 1 + solve(i + 1, inc, arr[i], arr));
        }

        return dp[i][inc][dec] = ans;
    }

public:
    int minCount(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        int maxIncluded = solve(0, 0, 101, arr);
        return arr.size() - maxIncluded;
    }
};