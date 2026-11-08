var countServers = function(grid) {
    const rows = grid.map(row => row.reduce((a, b) => a + b));
    const cols = grid[0].map((_, j) => grid.reduce((sum, row) => sum + row[j], 0));
    let ans = 0;
    for (const [i, row] of grid.entries())
        for (const [j, server] of row.entries())
            if (server && rows[i] + cols[j] > 2) ans++;
    return ans;
};