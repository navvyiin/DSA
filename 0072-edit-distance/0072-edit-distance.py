class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        # dp[j] = edit distance for word1[:i] -> word2[:j]
        dp = list(range(n + 1))

        for i in range(1, m + 1):
            prev_diag = dp[0]
            dp[0] = i

            for j in range(1, n + 1):
                temp = dp[j]

                if word1[i - 1] == word2[j - 1]:
                    dp[j] = prev_diag
                else:
                    dp[j] = 1 + min(
                        dp[j],       # delete
                        dp[j - 1],   # insert
                        prev_diag    # replace
                    )

                prev_diag = temp

        return dp[n]