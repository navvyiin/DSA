class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1))
                    continue;

                int best = -1;
                long long cnt = 0;

                vector<pair<int, int>> prev = {
                    {i + 1, j},
                    {i, j + 1},
                    {i + 1, j + 1}
                };

                for (auto &[x, y] : prev) {
                    if (x >= n || y >= n || dp[x][y] == -1)
                        continue;

                    if (dp[x][y] > best) {
                        best = dp[x][y];
                        cnt = ways[x][y];
                    } else if (dp[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9')
                    val = board[i][j] - '0';

                dp[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if (dp[0][0] == -1)
            return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};