class Solution {
public:

    void computeLPS(string &s, vector<int> &lps) {
        int n = s.size();

        lps[0] = 0;

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];

            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }

            if (s[i] == s[len]) {
                len++;
            }

            lps[i] = len;
        }
    }

    string compress(string s) {
        int n = s.size();

        if (n <= 1)
            return s;

        vector<int> lps(n);
        computeLPS(s, lps);

        stack<char> st;

        // Process prefixes from right to left
        for (int i = n - 1; i > 0; i--) {

            int len = i + 1;

            // Odd length cannot be divided into two equal halves
            if (len % 2 == 1) {
                st.push(s[i]);
                continue;
            }

            int longestPrefixSuffix = lps[i];

            // Smallest repeating block
            int blockLength = len - longestPrefixSuffix;

            bool canCompress = false;

            /*
               The prefix can be compressed if:
               1. It has enough repetition
               2. The whole prefix is made of repeating blocks
               3. Number of blocks is even
            */
            if (longestPrefixSuffix * 2 >= len &&
                len % blockLength == 0 &&
                (len / blockLength) % 2 == 0) {

                canCompress = true;
            }

            if (canCompress) {
                st.push('*');

                // Only process the first half
                i = len / 2;
            }
            else {
                st.push(s[i]);
            }
        }

        string ans;

        ans.push_back(s[0]);

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};