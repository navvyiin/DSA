from bisect import bisect_right

class Solution:
    def stoneGameV(self, stoneValue):
        n = len(stoneValue)

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        dp = [[0] * n for _ in range(n)]

        # left[i][j] =
        # max(dp[i][k] + sum(i..k)) for i <= k <= j
        left = [[0] * n for _ in range(n)]

        # right[i][j] =
        # max(dp[k][j] + sum(k..j)) for i <= k <= j
        right = [[0] * n for _ in range(n)]

        for i in range(n):
            left[i][i] = stoneValue[i]
            right[i][i] = stoneValue[i]

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1

                total = prefix[j + 1] - prefix[i]

                # Find largest t such that:
                #
                # sum(i..t-1) <= sum(t..j)
                #
                # 2 * prefix[t] <= prefix[i] + prefix[j+1]

                limit = (prefix[i] + prefix[j + 1]) // 2

                t = bisect_right(
                    prefix,
                    limit,
                    i + 1,
                    j + 1
                ) - 1

                best = 0

                # Left part is smaller or equal.
                if t >= i + 1:
                    best = left[i][t - 1]

                # Equal sums: Alice can choose either side.
                if t >= i + 1 and 2 * prefix[t] == prefix[i] + prefix[j + 1]:
                    best = max(best, right[t][j])

                # Right part is smaller.
                if t + 1 <= j:
                    best = max(best, right[t + 1][j])

                dp[i][j] = best

                # Update helper tables.
                left[i][j] = max(
                    left[i][j - 1],
                    dp[i][j] + total
                )

                right[i][j] = max(
                    right[i + 1][j],
                    dp[i][j] + total
                )

        return dp[0][n - 1]