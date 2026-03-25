class Solution:
    def canPartitionGrid(self, grid):
        m, n = len(grid), len(grid[0])
        
        total_sum = sum(sum(row) for row in grid)
        
        # If total sum is odd, cannot split equally
        if total_sum % 2 != 0:
            return False
        
        target = total_sum // 2
        
        # Check horizontal cuts
        running_sum = 0
        for i in range(m - 1):
            running_sum += sum(grid[i])
            if running_sum == target:
                return True
        
        # Check vertical cuts
        col_sums = [0] * n
        for j in range(n):
            for i in range(m):
                col_sums[j] += grid[i][j]
        
        running_sum = 0
        for j in range(n - 1):
            running_sum += col_sums[j]
            if running_sum == target:
                return True
        
        return False