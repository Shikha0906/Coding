class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        // Pre-process positions of each character in s
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string result = "";

        for (const string &word : d) {
            int w_len = word.length();
            int r_len = result.length();

            // Optimization 1: Skip if word cannot beat the current result
            if (w_len < r_len || (w_len == r_len && word >= result)) {
                continue;
            }

            // Optimization 2: Fast subsequence check via Binary Search
            int current_idx = -1;
            bool is_possible = true;

            for (char c : word) {
                const auto &indices = pos[c - 'a'];
                auto it = upper_bound(indices.begin(), indices.end(), current_idx);

                if (it == indices.end()) {
                    is_possible = false;
                    break;
                }
                current_idx = *it;
            }

            if (is_possible) {
                result = word;
            }
        }

        return result;
    }
};