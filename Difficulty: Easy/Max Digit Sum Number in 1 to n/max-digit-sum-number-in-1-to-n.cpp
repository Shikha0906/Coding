class Solution {
private:
    int sumDigits(long long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int findMax(int n) {
        string s = to_string(n);
        long long maxNum = n;
        int maxSum = sumDigits(n);

        long long current = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                current = current * 10;
                continue;
            }

            // Create candidate by decrementing current digit by 1 and filling rest with 9
            long long candidate = current * 10 + (s[i] - '1');
            for (int j = i + 1; j < s.length(); j++) {
                candidate = candidate * 10 + 9;
            }

            int candidateSum = sumDigits(candidate);
            if (candidateSum > maxSum || (candidateSum == maxSum && candidate > maxNum)) {
                maxSum = candidateSum;
                maxNum = candidate;
            }

            current = current * 10 + (s[i] - '0');
        }

        return maxNum;
    }
};