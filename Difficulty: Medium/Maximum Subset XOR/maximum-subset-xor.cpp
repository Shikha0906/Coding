class Solution {
public:
    int maxSubsetXOR(vector<int>& arr) {
        int basis[21] = {0};

        // Build XOR basis
        for (int num : arr) {
            int x = num;

            for (int bit = 20; bit >= 0; bit--) {
                if ((x & (1 << bit)) == 0)
                    continue;

                if (basis[bit] == 0) {
                    basis[bit] = x;
                    break;
                }

                x ^= basis[bit];
            }
        }

        // Find maximum XOR
        int ans = 0;

        for (int bit = 20; bit >= 0; bit--) {
            if ((ans ^ basis[bit]) > ans) {
                ans ^= basis[bit];
            }
        }

        return ans;
    }
};