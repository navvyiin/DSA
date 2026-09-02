class Solution {
    public boolean uniformArray(int[] nums1) {
        boolean hasOdd = false;
        boolean hasEven = false;
        for (int num : nums1) {
            if (num % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
            }
        }
        if (!hasOdd || !hasEven) {
            return true;
        }
        if (hasOdd) {
            int oddCount = 0;
            for (int num : nums1) {
                if (num % 2 != 0) {
                    oddCount++;
                }
            }
            if (oddCount >= 1) {
                return true;
            }
        }
        return false;
    }
}