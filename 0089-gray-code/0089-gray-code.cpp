#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n;  // 2^n

        for (int i = 0; i < size; i++) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }
};