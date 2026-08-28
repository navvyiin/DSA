class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();

        int[] freq = new int[26];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // A palindrome can have at most one character
        // with an odd frequency.
        int oddChar = -1;
        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                oddChar = i;
            }
        }

        if (oddCount > 1) {
            return "";
        }

        int halfLen = n / 2;

        // Frequencies for the first half of the palindrome.
        int[] halfFreq = new int[26];

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        char middle = oddChar == -1 ? 0 : (char) ('a' + oddChar);

        /*
         * We need the smallest possible first half that is
         * >= target's first half, with the whole palindrome
         * being strictly greater than target.
         */
        for (int i = halfLen; i >= 0; i--) {
            int[] remaining = halfFreq.clone();

            // Match target's first half before position i.
            boolean possible = true;

            for (int j = 0; j < i; j++) {
                int c = target.charAt(j) - 'a';

                if (remaining[c] == 0) {
                    possible = false;
                    break;
                }

                remaining[c]--;
            }

            if (!possible) {
                continue;
            }

            // If i == halfLen, first half must be exactly equal
            // to target's first half.
            if (i == halfLen) {
                String firstHalf = target.substring(0, halfLen);

                boolean valid = true;
                int[] temp = halfFreq.clone();

                for (char c : firstHalf.toCharArray()) {
                    if (temp[c - 'a'] == 0) {
                        valid = false;
                        break;
                    }
                    temp[c - 'a']--;
                }

                if (!valid) {
                    continue;
                }

                String candidate = build(firstHalf, middle);

                if (candidate.compareTo(target) > 0) {
                    return candidate;
                }

                continue;
            }

            // Find the smallest available character greater than
            // target[i].
            int current = target.charAt(i) - 'a';
            int greater = -1;

            for (int c = current + 1; c < 26; c++) {
                if (remaining[c] > 0) {
                    greater = c;
                    break;
                }
            }

            if (greater == -1) {
                continue;
            }

            remaining[greater]--;

            StringBuilder firstHalf = new StringBuilder();

            // Equal prefix.
            firstHalf.append(target, 0, i);

            // First position where we become greater.
            firstHalf.append((char) ('a' + greater));

            // Smallest possible suffix.
            for (int c = 0; c < 26; c++) {
                while (remaining[c] > 0) {
                    firstHalf.append((char) ('a' + c));
                    remaining[c]--;
                }
            }

            return build(firstHalf.toString(), middle);
        }

        return "";
    }

    private String build(String firstHalf, char middle) {
        StringBuilder result = new StringBuilder();

        result.append(firstHalf);

        if (middle != 0) {
            result.append(middle);
        }

        for (int i = firstHalf.length() - 1; i >= 0; i--) {
            result.append(firstHalf.charAt(i));
        }

        return result.toString();
    }
}