/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var minimumChanges = function(s, k) {
    const n = s.length;
    const INF = 1e9;

    // Precompute minimum changes for every substring.
    const cost = Array.from({ length: n }, () =>
        new Int32Array(n).fill(INF)
    );

    for (let left = 0; left < n; left++) {
        for (let right = left + 1; right < n; right++) {
            const len = right - left + 1;

            // Try every proper divisor of the substring length.
            for (let d = 1; d < len; d++) {
                if (len % d !== 0) continue;

                const groupSize = len / d;
                let changes = 0;

                // Check each residue group for palindrome symmetry.
                for (let offset = 0; offset < d; offset++) {
                    for (let t = 0; t < Math.floor(groupSize / 2); t++) {
                        const a = left + offset + t * d;
                        const b = left + offset + (groupSize - 1 - t) * d;

                        if (s[a] !== s[b]) {
                            changes++;
                        }
                    }
                }

                cost[left][right] = Math.min(
                    cost[left][right],
                    changes
                );
            }
        }
    }

    // DP[p][i] = minimum changes to partition first i characters
    // into exactly p semi-palindromic substrings.
    const dp = Array.from({ length: k + 1 }, () => {
        const row = new Int32Array(n + 1);
        row.fill(INF);
        return row;
    });

    dp[0][0] = 0;

    for (let p = 1; p <= k; p++) {
        for (let end = 2 * p; end <= n - 2 * (k - p); end++) {
            for (let start = 2 * (p - 1); start <= end - 2; start++) {
                if (dp[p - 1][start] === INF) continue;

                dp[p][end] = Math.min(
                    dp[p][end],
                    dp[p - 1][start] + cost[start][end - 1]
                );
            }
        }
    }

    return dp[k][n];
};