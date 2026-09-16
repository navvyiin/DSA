class Solution {
    public int numberOfSets(int n, int k) {
        final long MOD = 1_000_000_007L;
        int N = n + k - 1;
        int R = 2 * k;
        long[] fact = new long[N + 1];
        long[] invFact = new long[N + 1];
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[N] = modPow(fact[N], MOD - 2, MOD);
        for (int i = N - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
        long ans = fact[N];
        ans = ans * invFact[R] % MOD;
        ans = ans * invFact[N - R] % MOD;
        return (int) ans;
    }
    private long modPow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
}