var minCut = function(s) {
    const n = s.length;
    const dp = new Array(n).fill(0);

    // Worst case: cut before every character
    for (let i = 0; i < n; i++) {
        dp[i] = i;
    }

    for (let center = 0; center < n; center++) {

        // Odd-length palindromes
        expand(center, center);

        // Even-length palindromes
        expand(center, center + 1);
    }

    function expand(left, right) {
        while (left >= 0 && right < n && s[left] === s[right]) {
            if (left === 0) {
                dp[right] = 0;
            } else {
                dp[right] = Math.min(dp[right], dp[left - 1] + 1);
            }
            left--;
            right++;
        }
    }

    return dp[n - 1];
};