class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] result = new long[k];
        long[] dp = new long[k];
        for (int num : nums) {
            int value = num % k;
            long[] next = new long[k];
            next[value] = 1;
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (r * value) % k;
                    next[newRemainder] += dp[r];
                }
            }
            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }
            dp = next;
        }
        return result;
    }
}