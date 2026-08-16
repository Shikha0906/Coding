class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return arr[0];

        int negCount = 0;
        int zeroCount = 0;
        int maxNeg = -11;
        int minPos = 11;

        long long product = 1;

        for (int x : arr) {
            if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x);
                product *= x;
            }
            else if (x == 0) {
                zeroCount++;
            }
            else {
                minPos = min(minPos, x);
                product *= x;
            }
        }

        // No negative numbers
        if (negCount == 0) {
            if (zeroCount > 0)
                return 0;
            return minPos;
        }

        // Odd number of negative numbers
        if (negCount % 2 == 1) {
            return (int)product;
        }

        // Even number of negative numbers:
        // Remove the negative number closest to zero
        product = 1;
        bool skipped = false;

        for (int x : arr) {
            if (x == maxNeg && !skipped) {
                skipped = true;
                continue;
            }

            if (x != 0)
                product *= x;
        }

        return (int)product;
    }
};