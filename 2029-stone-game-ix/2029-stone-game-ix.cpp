class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            cnt[x % 3]++;

        int a = cnt[1];
        int b = cnt[2];
        int zero = cnt[0];

        // No stones with remainder 1 or 2.
        if (a == 0 && b == 0)
            return false;

        // If there are no 0-mod-3 stones, Alice wins
        // when the counts of 1s and 2s are not too unbalanced.
        if (zero % 2 == 0) {
            return a > 0 && b > 0;
        }

        // With an odd number of 0-mod-3 stones,
        // the larger group must exceed the smaller by at least 3.
        return abs(a - b) > 2;
    }
};