import java.util.*;

class Solution {

    // Main problem: only positive numbers
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;  // one way to make sum 0: choose nothing

        for (int t = 1; t <= target; t++) {
            for (int num : nums) {
                if (t - num >= 0) {
                    dp[t] += dp[t - num];
                }
            }
        }
        return dp[target];
    }
}