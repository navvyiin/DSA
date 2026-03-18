import java.util.*;

class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        long num = Long.parseLong(n);

        // Edge case: single digit
        if (len == 1) return String.valueOf(num - 1);

        Set<Long> candidates = new HashSet<>();

        // Edge cases like 999 -> 1001, 1000 -> 999
        candidates.add((long)Math.pow(10, len - 1) - 1);
        candidates.add((long)Math.pow(10, len) + 1);

        long prefix = Long.parseLong(n.substring(0, (len + 1) / 2));

        for (long i = prefix - 1; i <= prefix + 1; i++) {
            String firstHalf = String.valueOf(i);
            StringBuilder sb = new StringBuilder(firstHalf);

            // Build palindrome
            String secondHalf;
            if (len % 2 == 0) {
                secondHalf = new StringBuilder(firstHalf).reverse().toString();
            } else {
                secondHalf = new StringBuilder(firstHalf.substring(0, firstHalf.length() - 1)).reverse().toString();
            }

            sb.append(secondHalf);
            candidates.add(Long.parseLong(sb.toString()));
        }

        long closest = -1;

        for (long cand : candidates) {
            if (cand == num) continue;

            if (closest == -1 ||
                Math.abs(cand - num) < Math.abs(closest - num) ||
                (Math.abs(cand - num) == Math.abs(closest - num) && cand < closest)) {
                closest = cand;
            }
        }

        return String.valueOf(closest);
    }
}