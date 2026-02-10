class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        # Copy the last row as initial DP state
        dp = triangle[-1][:]

        # Build from bottom to top
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])

        return dp[0]