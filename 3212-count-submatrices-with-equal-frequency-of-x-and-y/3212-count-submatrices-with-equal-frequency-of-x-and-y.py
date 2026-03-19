class Solution:
    def numberOfSubmatrices(self, grid):
        m, n = len(grid), len(grid[0])
        
        # Convert grid to values
        val = [[0]*n for _ in range(m)]
        has_x = [[0]*n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'X':
                    val[i][j] = 1
                    has_x[i][j] = 1
                elif grid[i][j] == 'Y':
                    val[i][j] = -1
        
        # Prefix sum for X count
        prefixX = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                prefixX[i][j] = (
                    has_x[i-1][j-1]
                    + prefixX[i-1][j]
                    + prefixX[i][j-1]
                    - prefixX[i-1][j-1]
                )
        
        res = 0
        
        # Only submatrices starting at (0,0)
        colSum = [0]*n
        
        for bottom in range(m):
            for c in range(n):
                colSum[c] += val[bottom][c]
            
            curr = 0
            for c in range(n):
                curr += colSum[c]
                
                if curr == 0:
                    x_count = prefixX[bottom+1][c+1]
                    if x_count > 0:
                        res += 1
        
        return res