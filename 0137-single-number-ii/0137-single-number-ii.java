class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;

        // Check each of 32 bit positions
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;

            for (int num : nums) {
                bitSum += (num >> i) & 1;
            }

            // If bitSum % 3 is 1, this bit belongs to the single number
            if (bitSum % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
}