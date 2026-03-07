class Solution:
    def minSwaps(self, grid):
        n = len(grid)
        
        trailing = []
        for row in grid:
            count = 0
            for x in reversed(row):
                if x == 0:
                    count += 1
                else:
                    break
            trailing.append(count)
        
        swaps = 0
        
        for i in range(n):
            needed = n - i - 1
            j = i
            
            while j < n and trailing[j] < needed:
                j += 1
            
            if j == n:
                return -1
            
            while j > i:
                trailing[j], trailing[j-1] = trailing[j-1], trailing[j]
                swaps += 1
                j -= 1
        
        return swaps