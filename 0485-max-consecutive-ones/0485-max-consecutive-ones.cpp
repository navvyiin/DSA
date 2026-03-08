#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int maximum = 0;

        for (int num : nums) {
            if (num == 1) {
                current++;
                maximum = max(maximum, current);
            } else {
                current = 0;
            }
        }

        return maximum;
    }
};