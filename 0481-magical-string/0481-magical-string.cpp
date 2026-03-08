#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> s(n + 2);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int head = 2;
        int tail = 3;
        int num = 1;
        int count = 1;

        while (tail < n) {
            for (int i = 0; i < s[head] && tail < n; i++) {
                s[tail++] = num;
                if (num == 1) count++;
            }
            num = (num == 1) ? 2 : 1;
            head++;
        }

        return count;
    }
};