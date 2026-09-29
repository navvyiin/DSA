class Solution {
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }
        int maxBalance = m + n;
        boolean[][][] dp = new boolean[m][n][maxBalance + 1];
        dp[0][0][1] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int balance = 0; balance <= maxBalance; balance++) {
                    if (!dp[i][j][balance]) {
                        continue;
                    }
                    if (i + 1 < m) {
                        int nextBalance = balance +
                                (grid[i + 1][j] == '(' ? 1 : -1);
                        if (nextBalance >= 0) {
                            dp[i + 1][j][nextBalance] = true;
                        }
                    }
                    if (j + 1 < n) {
                        int nextBalance = balance +
                                (grid[i][j + 1] == '(' ? 1 : -1);
                        if (nextBalance >= 0) {
                            dp[i][j + 1][nextBalance] = true;
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
}