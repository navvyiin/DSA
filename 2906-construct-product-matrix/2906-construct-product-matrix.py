class Solution:
    def constructProductMatrix(self, grid):
        MOD = 12345
        n, m = len(grid), len(grid[0])
        size = n * m
        
        # Flatten grid
        arr = []
        for row in grid:
            arr.extend(row)
        
        # Prefix products
        prefix = [1] * size
        for i in range(1, size):
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD
        
        # Suffix products
        suffix = [1] * size
        for i in range(size - 2, -1, -1):
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD
        
        # Build result
        result = [[0] * m for _ in range(n)]
        for i in range(size):
            val = (prefix[i] * suffix[i]) % MOD
            result[i // m][i % m] = val
        
        return result