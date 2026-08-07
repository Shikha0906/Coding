class Solution {
    public int countFriendsPairings(int n) {
        int mod = 1000000007;

        if (n <= 2) return n;

        long prev2 = 1; // f(1)
        long prev1 = 2; // f(2)

        for (int i = 3; i <= n; i++) {
            long curr = (prev1 + ((long)(i - 1) * prev2) % mod) % mod;
            prev2 = prev1;
            prev1 = curr;
        }

        return (int) prev1;
    }
}