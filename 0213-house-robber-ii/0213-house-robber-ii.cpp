class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        int money1 = robLinear(nums, 0, n - 2);

        // Case 2: exclude first house
        int money2 = robLinear(nums, 1, n - 1);

        return max(money1, money2);
    }

private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};