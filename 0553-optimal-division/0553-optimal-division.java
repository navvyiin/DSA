class Solution {
    public String optimalDivision(int[] nums) {
        int n = nums.length;
        
        if (n == 1) {
            return String.valueOf(nums[0]);
        }
        
        if (n == 2) {
            return nums[0] + "/" + nums[1];
        }
        
        StringBuilder sb = new StringBuilder();
        sb.append(nums[0]).append("/(");
        
        for (int i = 1; i < n; i++) {
            sb.append(nums[i]);
            if (i != n - 1) {
                sb.append("/");
            }
        }
        
        sb.append(")");
        return sb.toString();
    }
}