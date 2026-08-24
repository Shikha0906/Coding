class Solution {
private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int prefixStrings(int n) {
        long long MOD = 1e9 + 7;
        long long C = 1;

        for (int i = 1; i <= n; i++) {
            long long num = 2 * (2 * i - 1);
            long long den = i + 1;
            C = (C * num) % MOD;
            C = (C * modInverse(den)) % MOD;
        }

        return C;
    }
};