#include <map>
#include <vector>
using namespace std;

class SummaryRanges {
    // key = interval start, value = interval end
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        if (intervals.empty()) {
            intervals[value] = value;
            return;
        }

        // Find the first interval with start > value
        auto it = intervals.upper_bound(value);

        int start = value, end = value;

        // Check left interval
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= value) {
                // value already covered
                return;
            }
            if (prev->second + 1 == value) {
                start = prev->first;
                end = prev->second;
                intervals.erase(prev);
            }
        }

        // Check right interval
        if (it != intervals.end() && it->first == value + 1) {
            end = it->second;
            intervals.erase(it);
        }

        intervals[start] = max(end, value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto &p : intervals) {
            result.push_back({p.first, p.second});
        }
        return result;
    }
};