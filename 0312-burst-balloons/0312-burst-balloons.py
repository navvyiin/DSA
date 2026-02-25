class Solution:
    def maxCoins(self, nums):
        # Add virtual balloons with value 1 at both ends
        nums = [1] + nums + [1]
        n = len(nums)

        # dp[l][r]: max coins from bursting balloons between l and r (exclusive)
        dp = [[0] * n for _ in range(n)]

        # length is the distance between l and r
        for length in range(2, n):
            for left in range(0, n - length):
                right = left + length
                for k in range(left + 1, right):
                    coins = (
                        nums[left] * nums[k] * nums[right]
                        + dp[left][k]
                        + dp[k][right]
                    )
                    dp[left][right] = max(dp[left][right], coins)

        return dp[0][n - 1]