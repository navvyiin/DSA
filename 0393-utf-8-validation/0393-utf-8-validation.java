class Solution {
    public boolean validUtf8(int[] data) {
        int remainingBytes = 0;

        for (int num : data) {
            num = num & 0xFF; // ensure only last 8 bits are used

            if (remainingBytes == 0) {
                // Count leading 1s
                if ((num >> 7) == 0b0) {
                    continue; // 1-byte character
                }

                int mask = 0b10000000;
                while ((num & mask) != 0) {
                    remainingBytes++;
                    mask >>= 1;
                }

                // For multi-byte char, remainingBytes must be 2 to 4
                if (remainingBytes < 2 || remainingBytes > 4) {
                    return false;
                }

                // We already processed the first byte
                remainingBytes--; 
            } else {
                // Must be continuation byte: starts with 10
                if ((num >> 6) != 0b10) {
                    return false;
                }
                remainingBytes--;
            }
        }

        return remainingBytes == 0;
    }
}