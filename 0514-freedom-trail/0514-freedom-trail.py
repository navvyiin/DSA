from collections import defaultdict
from functools import lru_cache

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        n = len(ring)
        pos = defaultdict(list)

        for i, c in enumerate(ring):
            pos[c].append(i)

        @lru_cache(None)
        def dfs(i, cur):
            if i == len(key):
                return 0

            res = float('inf')
            for p in pos[key[i]]:
                diff = abs(p - cur)
                step = min(diff, n - diff)
                res = min(res, step + 1 + dfs(i + 1, p))

            return res

        return dfs(0, 0)