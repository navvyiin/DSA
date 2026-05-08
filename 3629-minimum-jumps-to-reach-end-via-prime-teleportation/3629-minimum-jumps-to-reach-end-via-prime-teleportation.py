from collections import defaultdict, deque

class Solution:
    def minJumps(self, nums):
        n = len(nums)

        if n == 1:
            return 0

        MAXV = max(nums)

        # Sieve for smallest prime factor
        spf = list(range(MAXV + 1))

        for i in range(2, int(MAXV ** 0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, MAXV + 1, i):
                    if spf[j] == j:
                        spf[j] = i

        def is_prime(x):
            return x > 1 and spf[x] == x

        # Map prime factor -> indices divisible by it
        divisible = defaultdict(list)

        for i, val in enumerate(nums):
            x = val
            factors = set()

            while x > 1:
                p = spf[x]
                factors.add(p)

                while x % p == 0:
                    x //= p

            for p in factors:
                divisible[p].append(i)

        q = deque([0])
        visited = [False] * n
        visited[0] = True

        used_prime = set()

        steps = 0

        while q:
            for _ in range(len(q)):
                i = q.popleft()

                if i == n - 1:
                    return steps

                # Adjacent moves
                for ni in (i - 1, i + 1):
                    if 0 <= ni < n and not visited[ni]:
                        visited[ni] = True
                        q.append(ni)

                # Prime teleport
                val = nums[i]

                if is_prime(val) and val not in used_prime:
                    for ni in divisible[val]:
                        if not visited[ni]:
                            visited[ni] = True
                            q.append(ni)

                    used_prime.add(val)

            steps += 1

        return -1