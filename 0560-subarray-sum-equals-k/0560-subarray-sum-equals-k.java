import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> prefixCount = new HashMap<>();
        prefixCount.put(0, 1);

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            if (prefixCount.containsKey(sum - k)) {
                count += prefixCount.get(sum - k);
            }

            prefixCount.put(sum, prefixCount.getOrDefault(sum, 0) + 1);
        }

        return count;
    }
}