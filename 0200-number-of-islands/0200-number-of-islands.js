var numIslands = function(grid) {
    if (!grid || grid.length === 0) return 0;

    const m = grid.length;
    const n = grid[0].length;
    let count = 0;

    function dfs(r, c) {
        // boundary check or water check
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] === "0") {
            return;
        }

        // mark current land as visited
        grid[r][c] = "0";

        // explore neighbours
        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === "1") {
                count++;
                dfs(i, j);
            }
        }
    }

    return count;
};