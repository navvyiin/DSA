class Solution {
public:
    struct Node {
        int len;
        int pref[26], suff[26], best[26];

        Node() {
            len = 0;
            memset(pref, 0, sizeof(pref));
            memset(suff, 0, sizeof(suff));
            memset(best, 0, sizeof(best));
        }
    };

    Node merge(Node &a, Node &b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        for (int c = 0; c < 26; c++) {
            res.pref[c] = a.pref[c];
            if (a.pref[c] == a.len)
                res.pref[c] += b.pref[c];

            res.suff[c] = b.suff[c];
            if (b.suff[c] == b.len)
                res.suff[c] += a.suff[c];

            res.best[c] = max(a.best[c], b.best[c]);
            res.best[c] = max(res.best[c], a.suff[c] + b.pref[c]);
        }

        return res;
    }

    vector<int> tree;
    string s;
    int n;

    // Segment tree stores the longest uniform substring.
    // Since there are only 26 characters, each node stores
    // prefix, suffix and best length for every character.

    vector<Node> seg;

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node].len = 1;
            int c = s[l] - 'a';
            seg[node].pref[c] = 1;
            seg[node].suff[c] = 1;
            seg[node].best[c] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            seg[node] = Node();
            seg[node].len = 1;

            int c = ch - 'a';
            seg[node].pref[c] = 1;
            seg[node].suff[c] = 1;
            seg[node].best[c] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);
            s[idx] = ch;

            int longest = 0;

            for (int c = 0; c < 26; c++)
                longest = max(longest, seg[1].best[c]);

            ans.push_back(longest);
        }

        return ans;
    }
};