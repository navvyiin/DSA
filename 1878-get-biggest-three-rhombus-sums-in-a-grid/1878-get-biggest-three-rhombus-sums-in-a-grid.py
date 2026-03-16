class Solution:
    def getBiggestThree(self, grid):
        m, n = len(grid), len(grid[0])
        res = set()

        for i in range(m):
            for j in range(n):
                res.add(grid[i][j])  # area 0 rhombus

                max_k = min(i, j, m - 1 - i, n - 1 - j)
                for k in range(1, max_k + 1):
                    s = 0
                    x, y = i - k, j

                    # top -> right
                    for d in range(k):
                        s += grid[x + d][y + d]

                    # right -> bottom
                    for d in range(k):
                        s += grid[x + k + d][y + k - d]

                    # bottom -> left
                    for d in range(k):
                        s += grid[x + 2 * k - d][y - d]

                    # left -> top
                    for d in range(k):
                        s += grid[x + k - d][y - k + d]

                    res.add(s)

        return sorted(res, reverse=True)[:3]