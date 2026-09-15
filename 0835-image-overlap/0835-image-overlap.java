class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int maxOverlap = 0;
        for (int dr = -(n - 1); dr <= n - 1; dr++) {
            for (int dc = -(n - 1); dc <= n - 1; dc++) {
                int overlap = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int ni = i + dr;
                        int nj = j + dc;
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n &&
                            img1[i][j] == 1 &&
                            img2[ni][nj] == 1) {
                            overlap++;
                        }
                    }
                }
                maxOverlap = Math.max(maxOverlap, overlap);
            }
        }
        return maxOverlap;
    }
}