class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        unordered_map<int, int> idx;
        for (int i = 0; i < m; i++)
            idx[vals[i]] = i;

        vector<int> fur(m);
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j + 1 < m && vals[j + 1] - vals[i] <= maxDiff)
                j++;
            fur[i] = j;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(m));
        up[0] = fur;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < m; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];
        }

        auto hops = [&](int a, int b) {
            if (a > b) swap(a, b);
            if (a == b) return 0;

            int cur = a;
            int ans = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                int nxt = up[k][cur];
                if (nxt < b) {
                    cur = nxt;
                    ans += (1 << k);
                }
            }

            if (fur[cur] == cur) return -1;
            return ans + 1;
        };

        vector<int> res;
        res.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                res.push_back(0);
                continue;
            }

            if (nums[u] == nums[v]) {
                res.push_back(1);
                continue;
            }

            res.push_back(hops(idx[nums[u]], idx[nums[v]]));
        }

        return res;
    }
};