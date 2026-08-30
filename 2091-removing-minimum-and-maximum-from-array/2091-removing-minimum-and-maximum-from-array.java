class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        int left = Math.min(minIndex, maxIndex);
        int right = Math.max(minIndex, maxIndex);

        // Both from the front
        int front = right + 1;

        // Both from the back
        int back = n - left;

        // Minimum from front, maximum from back
        int mixed = (left + 1) + (n - right);

        return Math.min(front, Math.min(back, mixed));
    }
}