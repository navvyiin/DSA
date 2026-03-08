#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        int max_m = log2(num);

        for (int m = max_m; m >= 1; --m) {
            long long k = pow(num, 1.0 / m);
            if (k < 2) continue;

            long long sum = 1, cur = 1;
            for (int i = 1; i <= m; ++i) {
                cur *= k;
                sum += cur;
            }

            if (sum == num) return to_string(k);
        }

        return to_string(num - 1);
    }
};