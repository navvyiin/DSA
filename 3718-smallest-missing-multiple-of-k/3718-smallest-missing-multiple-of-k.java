class Solution {
    public int missingMultiple(int[] nums, int k) {
        boolean[] present = new boolean[101];

        for (int num : nums) {
            if (num <= 100) {
                present[num] = true;
            }
        }

        int multiple = k;

        while (multiple <= 100 && present[multiple]) {
            multiple += k;
        }

        return multiple;
    }
}