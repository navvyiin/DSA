class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum is in right half
                left = mid + 1;
            } 
            else if (nums[mid] < nums[right]) {
                // Minimum is in left half (including mid)
                right = mid;
            } 
            else {
                // nums[mid] == nums[right]
                // Cannot determine, shrink safely
                right--;
            }
        }

        return nums[left];
    }
}