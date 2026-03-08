#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
private:
    vector<vector<int>> rects;
    vector<long long> prefix;
    long long total = 0;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (auto& r : rects) {
            long long count = (long long)(r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            total += count;
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        long long k = rand() % total;
        int idx = lower_bound(prefix.begin(), prefix.end(), k + 1) - prefix.begin();

        auto& r = rects[idx];
        int x = r[0] + rand() % (r[2] - r[0] + 1);
        int y = r[1] + rand() % (r[3] - r[1] + 1);

        return {x, y};
    }
};