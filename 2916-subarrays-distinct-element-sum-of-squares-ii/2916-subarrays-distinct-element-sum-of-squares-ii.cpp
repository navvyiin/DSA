#include <bits/stdc++.h>
using namespace std;
struct Node {
    int cnt = 0;
    int sq_cnt = 0;
    int lazy = 0;
};
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
int last_seen[N];
Node tree[4 * N];
void apply(int node, int st, int end, int x) {
    int len = end - st + 1;
    tree[node].sq_cnt = (0LL + tree[node].sq_cnt + 2LL * x * tree[node].cnt + 1LL * x * x % MOD * len) % MOD;
    tree[node].cnt = (1LL * len * x + tree[node].cnt) % MOD;
    tree[node].lazy = (1LL * tree[node].lazy + x) % MOD;
}
void lazyPropogation(int node, int st, int end) {
    if (tree[node].lazy == 0) return;
    int x = tree[node].lazy;
    int mid = st + (end - st) / 2;
    apply(2 * node, st, mid, x);
    apply(2 * node + 1, mid + 1, end, x);
    tree[node].lazy = 0;
}
void merge(int node, int left, int right) {
    tree[node].cnt = (0LL + tree[left].cnt + tree[right].cnt) % MOD;
    tree[node].sq_cnt = (0LL + tree[left].sq_cnt + tree[right].sq_cnt) % MOD;
}
void update(int node, int st, int end, int ql, int qr) {
    if (qr < st || end < ql) return;
    if (ql <= st && end <= qr) {
        apply(node, st, end, 1);
        return;
    }
    lazyPropogation(node, st, end);
    int mid = st + (end - st) / 2;
    update(2 * node, st, mid, ql, qr);
    update(2 * node + 1, mid + 1, end, ql, qr);
    merge(node, 2 * node, 2 * node + 1);
}
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        fill(tree, tree + 4 * n + 1, Node());
        memset(last_seen, -1, sizeof(last_seen));
        for (int i = 0; i < n; i++) {
            int st = (last_seen[nums[i]] == -1 ? 0 : last_seen[nums[i]] + 1);
            last_seen[nums[i]] = i;
            update(1, 0, n - 1, st, i);
            ans = (1LL * tree[1].sq_cnt + ans) % MOD;
        }
        return ans;
    }
};