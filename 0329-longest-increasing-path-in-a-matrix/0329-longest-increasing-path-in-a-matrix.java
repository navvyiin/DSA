class Solution {
    private int[][] matrix;
    private int[][] memo;
    private int m, n;
    private final int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;

        this.matrix = matrix;
        m = matrix.length;
        n = matrix[0].length;
        memo = new int[m][n];

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];

        int best = 1;
        for (int[] d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {
                best = Math.max(best, 1 + dfs(ni, nj));
            }
        }

        memo[i][j] = best;
        return best;
    }
}