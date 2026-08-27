class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();

        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Match target's prefix as far as possible.
        int matched = 0;

        while (matched < n) {
            int c = target.charAt(matched) - 'a';

            if (freq[c] == 0) {
                break;
            }

            freq[c]--;
            matched++;
        }

        /*
         * Try to make the string greater.
         *
         * Start at the rightmost possible position and move left.
         * When we move left, restore the character used by target[i].
         */
        for (int i = matched; i >= 0; i--) {
            if (i < matched) {
                freq[target.charAt(i) - 'a']++;
            }

            if (i == n) {
                continue;
            }

            int current = target.charAt(i) - 'a';

            // Choose the smallest available character > target[i].
            for (int c = current + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    StringBuilder ans = new StringBuilder();

                    // Prefix remains equal to target.
                    for (int j = 0; j < i; j++) {
                        ans.append(target.charAt(j));
                    }

                    // Make the first differing character larger.
                    ans.append((char) ('a' + c));
                    freq[c]--;

                    // Fill the suffix with the smallest possible order.
                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            ans.append((char) ('a' + x));
                            freq[x]--;
                        }
                    }

                    return ans.toString();
                }
            }
        }

        return "";
    }
}