class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        // left[i]: length of the contiguous block ending at i
        vector<int> left(n);
        // right[i]: length of the contiguous block starting at i
        vector<int> right(n);

        for (int i = 0; i < n; i++) {
            left[i] = (i > 0 && s[i] == s[i - 1]) ? left[i - 1] + 1 : 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            right[i] = (i + 1 < n && s[i] == s[i + 1]) ? right[i + 1] + 1 : 1;
        }

        vector<int> ans(m, -1);

        int blockSize = sqrt(n);

        vector<tuple<int, int, int, int>> longQueries;
        longQueries.reserve(m);

        auto bruteForce = [&](int l, int r) {
            int i = l;
            int best = 0;
            int prev = -1;

            while (i <= r) {
                int start = i;
                while (i <= r && s[i] == s[start]) i++;

                if (s[start] == '0') {
                    int len = i - start;
                    if (prev != -1)
                        best = max(best, prev + len);
                    prev = len;
                }
            }

            return best;
        };

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (r - l + 1 <= blockSize) {
                ans[i] = cnt1 + bruteForce(l, r);
            } else {
                longQueries.emplace_back(l / blockSize, l, r, i);
            }
        }

        sort(longQueries.begin(), longQueries.end(),
             [](const auto &a, const auto &b) {
                 if (get<0>(a) != get<0>(b))
                     return get<0>(a) < get<0>(b);
                 return get<2>(a) < get<2>(b);
             });

        deque<int> zeroBlocks;

        int L = 0, R = 0;
        int bestGain = 0;

        for (int i = 0; i < (int)longQueries.size(); i++) {
            auto [bid, l, r, idx] = longQueries[i];

            if (i == 0 || bid != get<0>(longQueries[i - 1])) {
                L = (bid + 1) * blockSize - 1;
                R = (bid + 1) * blockSize;

                zeroBlocks.clear();
                bestGain = 0;
            }

            while (R <= r) {
                int len = min(right[R], r - R + 1);

                if (s[R] == '0') {
                    if (!zeroBlocks.empty() && s[R - 1] == '0')
                        zeroBlocks.back() += len;
                    else
                        zeroBlocks.push_back(len);

                    if (zeroBlocks.size() >= 2)
                        bestGain = max(bestGain,
                                       zeroBlocks.back() +
                                           zeroBlocks[zeroBlocks.size() - 2]);
                }

                R += len;
            }

            int savedBest = bestGain;
            int savedFront = zeroBlocks.empty() ? -1 : zeroBlocks.front();
            int added = 0;

            while (L >= l) {
                int len = min(left[L], L - l + 1);

                if (s[L] == '0') {
                    if (!zeroBlocks.empty() && s[L + 1] == '0')
                        zeroBlocks.front() += len;
                    else {
                        zeroBlocks.push_front(len);
                        added++;
                    }

                    if (zeroBlocks.size() >= 2)
                        bestGain = max(bestGain,
                                       zeroBlocks[0] + zeroBlocks[1]);
                }

                L -= len;
            }

            ans[idx] = cnt1 + bestGain;

            L = (bid + 1) * blockSize - 1;
            bestGain = savedBest;

            while (added--)
                zeroBlocks.pop_front();

            if (!zeroBlocks.empty() && savedFront != -1)
                zeroBlocks.front() = savedFront;
        }

        return ans;
    }
};