#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    string s;

    vector<string> dfs(int start) {
        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> result;

        // Base case: reached end of string
        if (start == s.length()) {
            result.push_back("");
            return memo[start] = result;
        }

        // Try all possible prefixes
        for (int len = 1; start + len <= s.length(); len++) {
            string word = s.substr(start, len);

            if (dict.count(word)) {
                vector<string> suffixes = dfs(start + len);

                for (const string& suffix : suffixes) {
                    if (suffix.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + suffix);
                    }
                }
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();

        return dfs(0);
    }
};