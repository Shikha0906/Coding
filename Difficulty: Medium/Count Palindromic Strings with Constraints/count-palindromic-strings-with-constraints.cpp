class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long totalCount = 0;

        for (int len = 1; len <= n; ++len) {
            int m = (len + 1) / 2; // Number of distinct characters needed

            // If we need more characters than available in alphabet k, 0 valid strings
            if (m > k) continue; 

            long long ways = 1;
            for (int i = 0; i < m; ++i) {
                ways = (ways * (k - i)) % MOD;
            }

            totalCount = (totalCount + ways) % MOD;
        }

        return totalCount;
    }
};