class Solution {
public:
    static const long long CAP = 1000001LL;

    long long combCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i);
            res /= i;
            if (res >= CAP) return CAP;
        }
        return (long long)res;
    }

    long long ways(vector<int>& cnt) {
        long long res = 1;
        int used = 0;
        for (int c : cnt) {
            if (c == 0) continue;
            res = min(CAP, res * combCap(used + c, c));
            if (res >= CAP) return CAP;
            used += c;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid;
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] & 1) mid.push_back(char('a' + i));
        }

        if (ways(half) < k) return "";

        string left;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long cnt = ways(half);

                if (cnt >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= cnt;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};