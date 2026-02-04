#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;

    bool solve(const string &s1, const string &s2) {
        if (s1 == s2) return true;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.size();

        // Prune using character counts
        array<int, 26> count{};
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0)
                return memo[key] = false;
        }

        // Try all split positions
        for (int i = 1; i < n; i++) {
            // Case 1: no swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        memo.clear();
        return solve(s1, s2);
    }
};