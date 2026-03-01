class Solution {
    public int getMoneyAmount(int n) {
        // dp[l][r] = minimum cost to guarantee a win in range [l, r]
        int[][] dp = new int[n + 2][n + 2];

        // length is the size of the interval
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = Integer.MAX_VALUE;

                // try every possible guess x in [l, r]
                for (int x = l; x <= r; x++) {
                    int cost = x + Math.max(
                        x - 1 >= l ? dp[l][x - 1] : 0,
                        x + 1 <= r ? dp[x + 1][r] : 0
                    );
                    dp[l][r] = Math.min(dp[l][r], cost);
                }
            }
        }
        return dp[1][n];
    }
}