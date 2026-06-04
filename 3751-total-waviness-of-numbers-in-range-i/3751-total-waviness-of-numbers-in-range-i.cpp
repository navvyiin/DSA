class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[12][11][11][2];
    bool vis[12][11][11][2];

    Node dfs(int pos, int p1, int p2, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][p1 + 1][p2 + 1][started]) {
            return dp[pos][p1 + 1][p2 + 1][started];
        }

        int limit = tight ? (s[pos] - '0') : 9;
        Node res{0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, -1, -1, false, ntight);
                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
            } else {
                long long add = 0;

                if (p2 != -1) {
                    if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) {
                        add = 1;
                    }
                }

                Node nxt = dfs(pos + 1, d, p1, true, ntight);

                res.cnt += nxt.cnt;
                res.sum += nxt.sum + add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][p1 + 1][p2 + 1][started] = true;
            dp[pos][p1 + 1][p2 + 1][started] = res;
        }

        return res;
    }

    long long calc(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, -1, -1, false, true).sum;
    }

    long long totalWaviness(int num1, int num2) {
        return calc(num2) - calc((long long)num1 - 1);
    }
};