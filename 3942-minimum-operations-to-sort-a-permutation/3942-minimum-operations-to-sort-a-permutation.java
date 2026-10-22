class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int zeroIndex = -1;
        boolean sorted = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
            }
            if (nums[i] == 0) {
                zeroIndex = i;
            }
        }

        if (sorted) {
            return 0;
        }

        boolean ascending = true;
        boolean descending = true;

        for (int i = 0; i < n; i++) {
            int current = nums[i];
            int next = nums[(i + 1) % n];

            if (next != (current + 1) % n) {
                ascending = false;
            }

            if (next != (current - 1 + n) % n) {
                descending = false;
            }
        }

        int ans = Integer.MAX_VALUE;

        if (ascending) {
            int rotations = zeroIndex;
            ans = Math.min(rotations, n - rotations + 2);
        }

        if (descending) {
            int rotations = n - 1 - zeroIndex;
            ans = Math.min(ans, Math.min(rotations, n - rotations) + 1);
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}