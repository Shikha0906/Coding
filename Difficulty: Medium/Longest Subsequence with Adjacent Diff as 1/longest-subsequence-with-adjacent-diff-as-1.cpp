class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        unordered_map<int, int> dp;
        int maxLen = 0;

        for (int x : arr) {
            int len1 = dp.count(x - 1) ? dp[x - 1] : 0;
            int len2 = dp.count(x + 1) ? dp[x + 1] : 0;

            dp[x] = max(len1, len2) + 1;
            maxLen = max(maxLen, dp[x]);
        }

        return maxLen;
    }
};