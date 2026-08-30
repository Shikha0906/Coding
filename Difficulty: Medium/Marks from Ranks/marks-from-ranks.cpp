class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        vector<long long> pref(n);

        // Step 1: Compute prefix sum of elements count in each interval
        long long current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += (r[i] - l[i] + 1);
            pref[i] = current_sum;
        }

        // Step 2: Process each rank query using Binary Search
        vector<int> ans;
        ans.reserve(rank.size());

        for (int target_rank : rank) {
            // Find the first interval where pref[idx] >= target_rank
            int idx = lower_bound(pref.begin(), pref.end(), target_rank) - pref.begin();

            long long prev_count = (idx > 0) ? pref[idx - 1] : 0;
            int offset = target_rank - prev_count - 1;

            ans.push_back(l[idx] + offset);
        }

        return ans;
    }
};