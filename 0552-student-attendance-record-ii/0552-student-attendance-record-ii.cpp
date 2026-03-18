class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;

        // dp[a][l]: number of ways with 'a' absences used and ending with 'l' consecutive L's
        vector<vector<long long>> dp(2, vector<long long>(3, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            vector<vector<long long>> new_dp(2, vector<long long>(3, 0));

            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {
                    long long val = dp[a][l];
                    if (val == 0) continue;

                    // Add 'P' → reset late streak
                    new_dp[a][0] = (new_dp[a][0] + val) % MOD;

                    // Add 'A' → only if no absence yet
                    if (a == 0) {
                        new_dp[1][0] = (new_dp[1][0] + val) % MOD;
                    }

                    // Add 'L' → only if late streak < 2
                    if (l < 2) {
                        new_dp[a][l + 1] = (new_dp[a][l + 1] + val) % MOD;
                    }
                }
            }

            dp = new_dp;
        }

        long long ans = 0;
        for (int a = 0; a <= 1; a++) {
            for (int l = 0; l <= 2; l++) {
                ans = (ans + dp[a][l]) % MOD;
            }
        }

        return ans;
    }
};