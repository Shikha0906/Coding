class Solution {
public:
    long long countLessEqual(vector<int>& arr, int X) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = (long long)arr[i] + arr[j] + arr[k];

                if (sum <= X) {
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }

        return count;
    }

    long long countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        return countLessEqual(arr, r) -
               countLessEqual(arr, l - 1);
    }
};