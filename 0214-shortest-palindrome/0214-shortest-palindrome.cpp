class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        string t = s + "#" + rev;
        vector<int> lps(t.size(), 0);

        // Build LPS array (KMP prefix function)
        for (int i = 1; i < t.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && t[i] != t[j]) {
                j = lps[j - 1];
            }
            if (t[i] == t[j]) {
                j++;
            }
            lps[i] = j;
        }

        int palLen = lps.back(); // length of longest palindromic prefix
        string add = s.substr(palLen);
        reverse(add.begin(), add.end());

        return add + s;
    }
};