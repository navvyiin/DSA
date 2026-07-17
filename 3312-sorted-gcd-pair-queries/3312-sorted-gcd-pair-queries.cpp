class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int MAXV = 50000;

        vector<int> freq(MAXV + 1, 0);
        for (int x : nums) freq[x]++;

        vector<int> cntDiv(MAXV + 1, 0);
        for (int d = 1; d <= MAXV; d++) {
            for (int m = d; m <= MAXV; m += d)
                cntDiv[d] += freq[m];
        }

        vector<long long> exact(MAXV + 1, 0);

        for (int d = MAXV; d >= 1; d--) {
            long long c = cntDiv[d];
            exact[d] = c * (c - 1) / 2;
            for (int m = d + d; m <= MAXV; m += d)
                exact[d] -= exact[m];
        }

        vector<long long> pref(MAXV + 1, 0);
        for (int i = 1; i <= MAXV; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};