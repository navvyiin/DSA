from functools import lru_cache

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7

        @lru_cache(None)
        def dfs(r, c, moves):
            if r < 0 or r >= m or c < 0 or c >= n:
                return 1
            if moves == 0:
                return 0
            
            total = 0
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                total = (total + dfs(r + dr, c + dc, moves - 1)) % MOD
            
            return total
        
        return dfs(startRow, startColumn, maxMove)