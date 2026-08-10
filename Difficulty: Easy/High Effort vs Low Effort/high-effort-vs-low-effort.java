class Solution {
    public int maxTask(int[] high, int[] low) {
        int n = high.length;

        if (n == 0) return 0;

        int prev2 = 0;
        int prev1 = Math.max(high[0], low[0]);

        for (int i = 1; i < n; i++) {
            int curr = Math.max(
                prev1 + low[i],
                prev2 + high[i]
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}