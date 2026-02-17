class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifts = 0;

        // Find common prefix
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shifts++;
        }

        // Restore prefix to original position
        return left << shifts;
    }
};