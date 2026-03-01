class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            if (res < 0) right = mid - 1;
            else left = mid + 1;
        }
        return -1; // unreachable
    }
};