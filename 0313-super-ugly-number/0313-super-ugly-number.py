class Solution:
    def nthSuperUglyNumber(self, n, primes):
        k = len(primes)
        ugly = [1] * n
        idx = [0] * k
        next_val = primes[:]

        for i in range(1, n):
            nxt = min(next_val)
            ugly[i] = nxt

            for j in range(k):
                if next_val[j] == nxt:
                    idx[j] += 1
                    next_val[j] = primes[j] * ugly[idx[j]]

        return ugly[-1]