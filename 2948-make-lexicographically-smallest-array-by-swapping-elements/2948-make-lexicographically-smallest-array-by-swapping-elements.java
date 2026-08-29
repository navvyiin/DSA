import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;

        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices by the values in nums.
        Arrays.sort(indices, (a, b) -> Integer.compare(nums[a], nums[b]));

        int groupStart = 0;

        while (groupStart < n) {
            int groupEnd = groupStart;

            // Values belong to the same connected group when
            // every consecutive difference is <= limit.
            while (groupEnd + 1 < n &&
                   (long) nums[indices[groupEnd + 1]] - nums[indices[groupEnd]] <= limit) {
                groupEnd++;
            }

            // Collect indices and values in this group.
            List<Integer> positions = new ArrayList<>();
            List<Integer> values = new ArrayList<>();

            for (int i = groupStart; i <= groupEnd; i++) {
                positions.add(indices[i]);
                values.add(nums[indices[i]]);
            }

            // To get the lexicographically smallest array,
            // put the smallest values at the smallest indices.
            Collections.sort(positions);
            Collections.sort(values);

            for (int i = 0; i < positions.size(); i++) {
                nums[positions.get(i)] = values.get(i);
            }

            groupStart = groupEnd + 1;
        }

        return nums;
    }
}