var uniquePaths = function(grid) {
    const MOD = 1000000007;
    const m = grid.length;
    const n = grid[0].length;
    const right = new Uint32Array(m * n);
    const down = new Uint32Array(m * n);
    right[0] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const idx = i * n + j;

            if (grid[i][j] === 1) {
                if (i + 1 < m) {
                    const next = idx + n;
                    down[next] = (down[next] + right[idx]) % MOD;
                }
                if (j + 1 < n) {
                    const next = idx + 1;
                    right[next] = (right[next] + down[idx]) % MOD;
                }
            } else {
                const ways = (right[idx] + down[idx]) % MOD;
                if (j + 1 < n) {
                    const next = idx + 1;
                    right[next] = (right[next] + ways) % MOD;
                }
                if (i + 1 < m) {
                    const next = idx + n;
                    down[next] = (down[next] + ways) % MOD;
                }
            }
        }
    }
    const last = m * n - 1;
    return (right[last] + down[last]) % MOD;
};