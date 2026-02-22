#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        long long m = 1;  // 1, 10, 100, ...

        while (m <= n) {
            long long higher = n / (m * 10);
            long long current = (n / m) % 10;
            long long lower = n % m;

            if (current == 0) {
                count += higher * m;
            } else if (current == 1) {
                count += higher * m + lower + 1;
            } else {
                count += (higher + 1) * m;
            }

            m *= 10;
        }

        return (int)count;
    }
};