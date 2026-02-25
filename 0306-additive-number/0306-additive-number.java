class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();

        // First number ends at i, second at j
        for (int i = 1; i <= n - 2; i++) {
            // No leading zero for first number
            if (num.charAt(0) == '0' && i > 1) break;

            for (int j = i + 1; j <= n - 1; j++) {
                // No leading zero for second number
                if (num.charAt(i) == '0' && j - i > 1) break;

                String a = num.substring(0, i);
                String b = num.substring(i, j);

                if (isValidSequence(a, b, j, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isValidSequence(String a, String b, int index, String num) {
        while (index < num.length()) {
            String sum = addStrings(a, b);

            if (!num.startsWith(sum, index)) {
                return false;
            }

            index += sum.length();
            a = b;
            b = sum;
        }
        return true;
    }

    // String-based addition to avoid integer overflow
    private String addStrings(String x, String y) {
        StringBuilder sb = new StringBuilder();
        int i = x.length() - 1, j = y.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = (i >= 0) ? x.charAt(i--) - '0' : 0;
            int d2 = (j >= 0) ? y.charAt(j--) - '0' : 0;

            int sum = d1 + d2 + carry;
            sb.append(sum % 10);
            carry = sum / 10;
        }

        return sb.reverse().toString();
    }
}