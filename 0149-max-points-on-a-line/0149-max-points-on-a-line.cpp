#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<long long, int> slopeCount;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0) {
                    dy = 1;  // vertical line
                } 
                else if (dy == 0) {
                    dx = 1;  // horizontal line
                } 
                else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    // Normalise sign
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }

                // Combine dy and dx into a single key
                long long key = ((long long)dy << 32) ^ dx;

                slopeCount[key]++;
                localMax = max(localMax, slopeCount[key]);
            }

            maxPointsOnLine = max(maxPointsOnLine, localMax + 1);
        }

        return maxPointsOnLine;
    }
};