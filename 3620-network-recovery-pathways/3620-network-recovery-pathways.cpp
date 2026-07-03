class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> g(n);
        vector<int> indegree(n);
        vector<int> costs;

        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            costs.push_back(e[2]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto &[v, w] : g[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        auto check = [&](int x) {
            const long long INF = (1LL << 60);
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, w] : g[u]) {
                    if (w < x) continue;
                    if (v != 0 && v != n - 1 && !online[v]) continue;
                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }

            return dist[n - 1] <= k;
        };

        int ans = -1;
        int lo = 0, hi = (int)costs.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};