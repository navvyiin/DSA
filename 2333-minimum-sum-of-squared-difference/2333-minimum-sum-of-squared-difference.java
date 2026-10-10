class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int[] freq = new int[100001];
        long operations = (long) k1 + k2;
        long totalDiff = 0;
        for (int i = 0; i < nums1.length; i++) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            freq[diff]++;
            totalDiff += diff;
        }
        if (operations >= totalDiff) {
            return 0;
        }
        for (int diff = 100000; diff > 0 && operations > 0; diff--) {
            int reduce = (int) Math.min(freq[diff], operations);
            freq[diff] -= reduce;
            freq[diff - 1] += reduce;
            operations -= reduce;
        }
        long answer = 0;
        for (int diff = 1; diff <= 100000; diff++) {
            answer += (long) diff * diff * freq[diff];
        }
        return answer;
    }
}