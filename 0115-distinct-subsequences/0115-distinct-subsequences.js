var numDistinct = function(s, t) {
    const m = s.length;
    const n = t.length;

    // dp[j] = number of ways t[0..j-1] appears in s processed so far
    const dp = new Array(n + 1).fill(0);
    dp[0] = 1;  // empty t

    for (let i = 1; i <= m; i++) {
        // iterate backwards to avoid overwriting dp[j-1]
        for (let j = n; j >= 1; j--) {
            if (s[i - 1] === t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[n];
};