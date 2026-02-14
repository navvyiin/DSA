#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;

        if (s.length() < 10) {
            return result;
        }

        for (int i = 0; i <= s.length() - 10; i++) {
            string sub = s.substr(i, 10);
            count[sub]++;
            if (count[sub] == 2) {
                result.push_back(sub);
            }
        }

        return result;   // ← THIS must always be present
    }
};