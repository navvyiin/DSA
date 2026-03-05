class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }

private:
    long countSteps(long n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};