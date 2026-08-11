class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Store all numbers for quick lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Find the smallest missing integer >= sum
        int x = sum;

        while (st.count(x)) {
            x++;
        }

        return x;
    }
};