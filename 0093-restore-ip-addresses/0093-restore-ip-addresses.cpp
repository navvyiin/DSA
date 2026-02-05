class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int index, int parts,
                   string& current, vector<string>& result) {

        // If 4 parts are used
        if (parts == 4) {
            // Valid only if entire string is consumed
            if (index == s.size()) {
                result.push_back(current.substr(0, current.size() - 1)); // remove last dot
            }
            return;
        }

        // Prune: too many or too few characters left
        int remaining = s.size() - index;
        if (remaining < (4 - parts) || remaining > 3 * (4 - parts))
            return;

        int value = 0;
        for (int i = index; i < s.size() && i < index + 3; i++) {
            value = value * 10 + (s[i] - '0');

            if (value > 255) break;

            // Leading zero check
            if (i > index && s[index] == '0') break;

            int len_before = current.size();
            current += s.substr(index, i - index + 1) + '.';

            backtrack(s, i + 1, parts + 1, current, result);

            current.resize(len_before); // backtrack
        }
    }
};