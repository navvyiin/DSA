#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";

        for (char c : s) {
            if (c != '-') clean += toupper(c);
        }

        int first = clean.size() % k;
        string result = "";
        int i = 0;

        if (first > 0) {
            result += clean.substr(0, first);
            i = first;
        }

        while (i < clean.size()) {
            if (!result.empty()) result += '-';
            result += clean.substr(i, k);
            i += k;
        }

        return result;
    }
};