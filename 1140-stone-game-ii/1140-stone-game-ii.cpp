class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // dp[i][M] = maximum stones the current player can obtain
        // starting from index i with the current M.
        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                } else {
                    for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
                        dp[i][M] = max(
                            dp[i][M],
                            suffix[i] - dp[i + X][max(M, X)]
                        );
                    }
                }
            }
        }

        return dp[0][1];
    }
};