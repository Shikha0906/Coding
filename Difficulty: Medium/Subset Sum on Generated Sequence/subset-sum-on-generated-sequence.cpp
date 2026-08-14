class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> S = {s};
        long long sum = s;

        for (int a : arr) {
            long long val = sum + a;
            S.push_back(val);
            sum += val;
            if (val > x) break;
        }

        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] <= x) x -= S[i];
        }

        return x == 0;
    }
};