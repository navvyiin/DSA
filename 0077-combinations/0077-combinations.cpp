#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cur;
        cur.reserve(k);

        dfs(1, n, k, cur, result);
        return result;
    }

private:
    inline void dfs(int start, int n, int k,
                    vector<int>& cur,
                    vector<vector<int>>& result) {
        if (cur.size() == k) {
            result.push_back(cur);
            return;
        }

        int need = k - cur.size();
        for (int i = start; i <= n - need + 1; ++i) {
            cur.push_back(i);
            dfs(i + 1, n, k, cur, result);
            cur.pop_back();
        }
    }
};