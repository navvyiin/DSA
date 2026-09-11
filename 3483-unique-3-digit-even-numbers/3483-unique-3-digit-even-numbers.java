class Solution {
    public int totalNumbers(int[] digits) {
        int count = 0;
        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {
                    if (canForm(digits, a, b, c)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    private boolean canForm(int[] digits, int a, int b, int c) {
        int[] need = new int[10];
        need[a]++;
        need[b]++;
        need[c]++;
        int[] have = new int[10];
        for (int digit : digits) {
            have[digit]++;
        }
        for (int i = 0; i < 10; i++) {
            if (need[i] > have[i]) {
                return false;
            }
        }
        return true;
    }
}