class Solution {
    public int minInsertions(String s) {
        int insertions = 0;
        int rightNeeded = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                if (rightNeeded % 2 == 1) {
                    insertions++;
                    rightNeeded--;
                }
                rightNeeded += 2;
            } else {
                rightNeeded--;
                if (rightNeeded < 0) {
                    insertions++;
                    rightNeeded = 1;
                }
            }
        }
        return insertions + rightNeeded;
    }
}