class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();
        String ans = "";

        int[] ones = new int[n];
        int count = 0;

        // Store positions of all '1's
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                ones[count++] = i;
            }
        }

        if (count < k) {
            return "";
        }

        int minLen = Integer.MAX_VALUE;

        // Every shortest beautiful substring must start and end
        // at consecutive '1's among the sequence of 1s.
        for (int i = 0; i + k - 1 < count; i++) {
            int start = ones[i];
            int end = ones[i + k - 1];

            int len = end - start + 1;
            String cur = s.substring(start, end + 1);

            if (len < minLen) {
                minLen = len;
                ans = cur;
            } else if (len == minLen && cur.compareTo(ans) < 0) {
                ans = cur;
            }
        }

        return ans;
    }
}