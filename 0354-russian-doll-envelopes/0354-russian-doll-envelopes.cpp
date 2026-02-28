#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort by width ascending, height descending
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        // Longest Increasing Subsequence on heights
        vector<int> lis;
        for (const auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};