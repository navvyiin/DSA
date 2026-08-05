class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        // Find all suspicious methods reachable from k
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        // If any non-suspicious method invokes a suspicious one,
        // removal is impossible.
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};