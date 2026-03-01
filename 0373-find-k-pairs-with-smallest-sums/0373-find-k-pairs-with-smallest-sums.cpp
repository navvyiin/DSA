#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: (sum, index in nums1, index in nums2)
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<>
        > pq;

        // Initialise with pairs (nums1[i], nums2[0])
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            pq.emplace((long long)nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            result.push_back({nums1[i], nums2[j]});

            // Move to next element in nums2 for the same nums1[i]
            if (j + 1 < nums2.size()) {
                pq.emplace((long long)nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};