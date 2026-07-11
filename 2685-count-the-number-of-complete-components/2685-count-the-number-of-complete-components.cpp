class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            vector<int> comp;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);

                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            int sz = comp.size();
            int edgeCount = 0;

            for (int u : comp)
                edgeCount += adj[u].size();

            edgeCount /= 2;

            if (edgeCount == sz * (sz - 1) / 2)
                ans++;
        }

        return ans;
    }
};