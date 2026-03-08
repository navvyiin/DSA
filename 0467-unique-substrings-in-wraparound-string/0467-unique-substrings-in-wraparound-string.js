var findSubstringInWraproundString = function(s) {
    const dp = new Array(26).fill(0);
    let k = 0;

    for (let i = 0; i < s.length; i++) {
        if (i > 0 && (s.charCodeAt(i) - s.charCodeAt(i - 1) + 26) % 26 === 1) {
            k++;
        } else {
            k = 1;
        }

        const idx = s.charCodeAt(i) - 97;
        dp[idx] = Math.max(dp[idx], k);
    }

    return dp.reduce((a, b) => a + b, 0);
};