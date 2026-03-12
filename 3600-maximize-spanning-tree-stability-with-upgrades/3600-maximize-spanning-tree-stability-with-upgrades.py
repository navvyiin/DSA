class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[py] = px
            self.rank[px] += 1
        return True


class Solution:
    def maxStability(self, n: int, edges: list[list[int]], k: int) -> int:

        def can(x):
            dsu = DSU(n)
            used = 0
            upgrades = 0

            for u, v, s, must in edges:
                if must:
                    if s < x:
                        return False
                    if not dsu.union(u, v):
                        return False
                    used += 1

            optional = []
            for u, v, s, must in edges:
                if not must:
                    optional.append((u, v, s))

            normal = []
            need_upgrade = []

            for u, v, s in optional:
                if s >= x:
                    normal.append((u, v))
                elif s * 2 >= x:
                    need_upgrade.append((u, v))

            for u, v in normal:
                if used == n - 1:
                    break
                if dsu.union(u, v):
                    used += 1

            for u, v in need_upgrade:
                if used == n - 1:
                    break
                if upgrades == k:
                    break
                if dsu.union(u, v):
                    upgrades += 1
                    used += 1

            return used == n - 1

        left, right = 1, 2 * 10**5
        ans = -1

        while left <= right:
            mid = (left + right) // 2
            if can(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans