var pacificAtlantic = function(heights) {
    const m = heights.length;
    const n = heights[0].length;

    const pacific = Array.from({ length: m }, () => Array(n).fill(false));
    const atlantic = Array.from({ length: m }, () => Array(n).fill(false));

    const dirs = [[1,0],[-1,0],[0,1],[0,-1]];

    function dfs(r, c, visited) {
        visited[r][c] = true;

        for (let [dr, dc] of dirs) {
            const nr = r + dr;
            const nc = c + dc;

            if (
                nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]
            ) {
                dfs(nr, nc, visited);
            }
        }
    }

    for (let i = 0; i < m; i++) {
        dfs(i, 0, pacific);
        dfs(i, n - 1, atlantic);
    }

    for (let j = 0; j < n; j++) {
        dfs(0, j, pacific);
        dfs(m - 1, j, atlantic);
    }

    const result = [];

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push([i, j]);
            }
        }
    }

    return result;
};