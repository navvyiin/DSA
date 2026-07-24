class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<char>> dp(4, vector<char>(MAXX, 0));
        dp[0][0] = 1;

        for (int v : nums) {
            for (int k = 2; k >= 0; --k) {
                for (int x = 0; x < MAXX; ++x) {
                    if (dp[k][x]) {
                        dp[k + 1][x ^ v] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for (int x = 0; x < MAXX; ++x) {
            if (dp[1][x] || dp[3][x]) ans++;
        }

        return ans;
    }
};