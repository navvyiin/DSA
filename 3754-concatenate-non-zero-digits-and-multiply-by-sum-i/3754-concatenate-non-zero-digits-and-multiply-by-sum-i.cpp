class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string s = to_string(n);
        long long x = 0, sum = 0;

        for (char c : s) {
            if (c != '0') {
                x = x * 10 + (c - '0');
                sum += c - '0';
            }
        }

        return x * sum;
    }
};