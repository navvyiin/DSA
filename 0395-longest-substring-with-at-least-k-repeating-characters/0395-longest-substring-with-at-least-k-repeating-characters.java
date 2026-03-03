class Solution {
    public int longestSubstring(String s, int k) {
        return divideAndConquer(s, 0, s.length(), k);
    }

    private int divideAndConquer(String s, int start, int end, int k) {
        if (end - start < k) {
            return 0;
        }

        int[] freq = new int[26];
        for (int i = start; i < end; i++) {
            freq[s.charAt(i) - 'a']++;
        }

        for (int mid = start; mid < end; mid++) {
            if (freq[s.charAt(mid) - 'a'] < k) {
                int midNext = mid + 1;
                while (midNext < end && freq[s.charAt(midNext) - 'a'] < k) {
                    midNext++;
                }

                int left = divideAndConquer(s, start, mid, k);
                int right = divideAndConquer(s, midNext, end, k);
                return Math.max(left, right);
            }
        }

        return end - start;
    }
}