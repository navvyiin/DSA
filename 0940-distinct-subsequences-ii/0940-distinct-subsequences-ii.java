class Solution {
    public int distinctSubseqII(String s) {
        final int MOD = 1_000_000_007;
        long[] dp = new long[26];
        long total = 0;
        for (char c : s.toCharArray()) {
            int idx = c - 'a';
            long newCount = (total + 1) % MOD;
            total = (total + newCount - dp[idx] + MOD) % MOD;
            dp[idx] = newCount;
        }
        return (int) total;
    }
}