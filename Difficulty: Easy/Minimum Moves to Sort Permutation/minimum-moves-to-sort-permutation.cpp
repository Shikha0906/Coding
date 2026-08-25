class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        // Stores 1-based index or 0-based position of each element
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        int maxLen = 1;
        int currentLen = 1;

        // Check consecutive elements in value order
        for (int i = 1; i < n; i++) {
            if (pos[i + 1] > pos[i]) {
                currentLen++;
            } else {
                currentLen = 1;
            }
            maxLen = max(maxLen, currentLen);
        }

        return n - maxLen;
    }
};