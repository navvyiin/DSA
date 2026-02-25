class Solution {
public:
    bool canWinNim(int n) {
        // If n is a multiple of 4, the first player loses
        return n % 4 != 0;
    }
};