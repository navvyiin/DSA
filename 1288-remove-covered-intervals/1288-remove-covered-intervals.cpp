class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0, maxEnd = 0;

        for (auto &it : intervals) {
            if (it[1] > maxEnd) {
                count++;
                maxEnd = it[1];
            }
        }

        return count;
    }
};