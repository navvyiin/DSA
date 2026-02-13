#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; ++i) {
            int curr = nums[i];

            // If current number is negative, swap
            if (curr < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            result = max(result, maxProd);
        }

        return result;
    }
};