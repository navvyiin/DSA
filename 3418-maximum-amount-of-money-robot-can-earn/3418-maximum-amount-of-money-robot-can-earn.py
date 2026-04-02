class Solution:
    def maximumAmount(self, coins):
        m, n = len(coins), len(coins[0])
        
        # dp[j][k]: max coins at column j with k neutralisations used
        dp = [[-10**15] * 3 for _ in range(n)]
        
        # initialize (0,0)
        for k in range(3):
            if coins[0][0] >= 0:
                dp[0][k] = coins[0][0]
            else:
                if k > 0:
                    dp[0][k] = 0
                else:
                    dp[0][k] = coins[0][0]
        
        # first row
        for j in range(1, n):
            for k in range(3):
                val = coins[0][j]
                if val >= 0:
                    dp[j][k] = dp[j-1][k] + val
                else:
                    take = dp[j-1][k] + val
                    skip = dp[j-1][k-1] if k > 0 else -10**15
                    dp[j][k] = max(take, skip)
        
        # rest of grid
        for i in range(1, m):
            new = [[-10**15] * 3 for _ in range(n)]
            
            # first column
            for k in range(3):
                val = coins[i][0]
                if val >= 0:
                    new[0][k] = dp[0][k] + val
                else:
                    take = dp[0][k] + val
                    skip = dp[0][k-1] if k > 0 else -10**15
                    new[0][k] = max(take, skip)
            
            for j in range(1, n):
                val = coins[i][j]
                for k in range(3):
                    best_prev = max(dp[j][k], new[j-1][k])
                    
                    if val >= 0:
                        new[j][k] = best_prev + val
                    else:
                        take = best_prev + val
                        skip = max(
                            dp[j][k-1] if k > 0 else -10**15,
                            new[j-1][k-1] if k > 0 else -10**15
                        )
                        new[j][k] = max(take, skip)
            
            dp = new
        
        return max(dp[n-1])