#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> depthLength; 
        depthLength[0] = 0;  // base length
        
        int maxLen = 0;
        int i = 0;
        int n = input.size();
        
        while (i < n) {
            int depth = 0;
            
            // Count depth (number of '\t')
            while (i < n && input[i] == '\t') {
                depth++;
                i++;
            }
            
            int start = i;
            bool isFile = false;
            
            // Read current name
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') {
                    isFile = true;
                }
                i++;
            }
            
            int nameLen = i - start;
            
            if (isFile) {
                maxLen = max(maxLen, depthLength[depth] + nameLen);
            } else {
                // +1 for '/'
                depthLength[depth + 1] = depthLength[depth] + nameLen + 1;
            }
            
            i++; // skip '\n'
        }
        
        return maxLen;
    }
};