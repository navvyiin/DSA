class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        string half = "", mid = "";
        for (int i = 0; i < 26; i++) {
            half.append(cnt[i] / 2, char('a' + i));
            if (cnt[i] % 2) mid = char('a' + i);
        }

        string ans = half;
        reverse(half.begin(), half.end());
        ans += mid;
        ans += half;

        return ans;
    }
};