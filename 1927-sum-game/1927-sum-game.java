class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;
        int leftQ = 0;
        int rightQ = 0;

        for (int i = 0; i < half; i++) {
            char c = num.charAt(i);

            if (c == '?') {
                leftQ++;
            } else {
                leftSum += c - '0';
            }
        }

        for (int i = half; i < n; i++) {
            char c = num.charAt(i);

            if (c == '?') {
                rightQ++;
            } else {
                rightSum += c - '0';
            }
        }

        // Alice gets one extra move.
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        /*
         * Bob wins only if the fixed-digit difference can be
         * exactly cancelled by the '?' characters.
         */
        return leftSum - rightSum
                != 9 * (rightQ - leftQ) / 2;
    }
}