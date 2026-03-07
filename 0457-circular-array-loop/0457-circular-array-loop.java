class Solution {

    private int next(int[] nums, int i) {
        int n = nums.length;
        int next = ((i + nums[i]) % n + n) % n; 
        return next;
    }

    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            boolean dir = nums[i] > 0;

            while (true) {
                slow = next(nums, slow);
                if (nums[slow] == 0 || (nums[slow] > 0) != dir) break;

                fast = next(nums, fast);
                if (nums[fast] == 0 || (nums[fast] > 0) != dir) break;

                fast = next(nums, fast);
                if (nums[fast] == 0 || (nums[fast] > 0) != dir) break;

                if (slow == fast) {
                    if (slow == next(nums, slow)) break;
                    return true;
                }
            }

            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == dir) {
                int nxt = next(nums, j);
                nums[j] = 0;
                j = nxt;
            }
        }

        return false;
    }
}