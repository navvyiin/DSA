class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto can = [&](int safe) {
            if (dist[0][0] < safe) return false;

            queue<pair<int,int>> qq;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            qq.push({0, 0});
            vis[0][0] = true;

            while (!qq.empty()) {
                auto [x, y] = qq.front();
                qq.pop();

                if (x == n - 1 && y == n - 1) return true;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        !vis[nx][ny] && dist[nx][ny] >= safe) {
                        vis[nx][ny] = true;
                        qq.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int lo = 0, hi = 2 * (n - 1), ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};