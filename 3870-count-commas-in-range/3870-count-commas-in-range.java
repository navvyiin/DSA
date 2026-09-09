class Solution {
    public int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        if (n <= 99999) {
            return n - 999;
        }
        return n - 999;
    }
}