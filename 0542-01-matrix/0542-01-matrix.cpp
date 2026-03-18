class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        // Initialize queue with all 0 cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Multi-source BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto &d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
};