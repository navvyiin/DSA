class Solution {
    public long findKthSmallest(int[] coins, int k) {
        long lo = 1;
        long hi = (long) coins[0] * k;

        for (int coin : coins) {
            hi = Math.min(hi, (long) coin * k);
        }

        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    private long count(long x, int[] coins) {
        int n = coins.length;
        long total = 0;

        // Inclusion-exclusion over all subsets.
        for (int mask = 1; mask < (1 << n); mask++) {
            long lcm = 1;
            int bits = 0;
            boolean valid = true;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    bits++;

                    long g = gcd(lcm, coins[i]);
                    lcm = lcm / g * coins[i];

                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            long multiples = x / lcm;

            if ((bits & 1) == 1) {
                total += multiples;
            } else {
                total -= multiples;
            }
        }

        return total;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}