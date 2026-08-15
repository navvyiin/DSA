class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;

        for (int num : nums)
            x ^= num;

        // If XOR of the entire array is non-zero,
        // take the whole array.
        if (x != 0)
            return nums.size();

        // If total XOR is zero, remove one element
        // that is non-zero. The remaining XOR becomes
        // equal to that element, hence non-zero.
        for (int num : nums) {
            if (num != 0)
                return nums.size() - 1;
        }

        // All elements are zero.
        return 0;
    }
};