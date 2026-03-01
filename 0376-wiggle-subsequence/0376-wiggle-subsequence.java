class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        if (n < 2) return n;

        int up = 1;    // longest wiggle subsequence ending with a positive difference
        int down = 1;  // longest wiggle subsequence ending with a negative difference

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
            // if equal, do nothing
        }
        return Math.max(up, down);
    }
}