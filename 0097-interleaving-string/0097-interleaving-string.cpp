#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        // Length check
        if (n + m != (int)s3.size())
            return false;

        // dp[j] = whether s1[0..i-1] and s2[0..j-1]
        // can form s3[0..i+j-1]
        vector<bool> dp(m + 1, false);

        // Base case: using only s2
        dp[0] = true;
        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill DP
        for (int i = 1; i <= n; i++) {
            // First column: using only s1
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= m; j++) {
                dp[j] =
                    (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m];
    }
};
