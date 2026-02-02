#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();
        int i = 0;

        while (i < n) {
            // Skip consecutive slashes
            while (i < n && path[i] == '/') {
                i++;
            }
            if (i >= n) break;

            int start = i;
            while (i < n && path[i] != '/') {
                i++;
            }

            string part = path.substr(start, i - start);

            if (part == ".") {
                continue;
            } else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(part);
            }
        }

        // Build result
        if (stack.empty()) return "/";

        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        return result;
    }
};