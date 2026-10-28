var minCost = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const MAX = 1024;
    const dp = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => new Uint8Array(MAX))
    );
    dp[0][0][grid[0][0]] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) continue;
            const val = grid[i][j];
            const cur = dp[i][j];
            if (i > 0) {
                const top = dp[i - 1][j];
                for (let x = 0; x < MAX; x++) {
                    if (top[x]) {
                        cur[x ^ val] = 1;
                    }
                }
            }
            if (j > 0) {
                const left = dp[i][j - 1];
                for (let x = 0; x < MAX; x++) {
                    if (left[x]) {
                        cur[x ^ val] = 1;
                    }
                }
            }
        }
    }
    for (let x = 0; x < MAX; x++) {
        if (dp[m - 1][n - 1][x]) {
            return x;
        }
    }
    return 0;
};