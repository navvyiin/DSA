class Solution:
    def findTheString(self, lcp):
        n = len(lcp)
        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px

        # Step 1: Union positions with lcp > 0
        for i in range(n):
            for j in range(n):
                if lcp[i][j] > 0:
                    union(i, j)

        # Step 2: Assign smallest lexicographical chars
        groups = {}
        char = ord('a')
        res = [''] * n

        for i in range(n):
            root = find(i)
            if root not in groups:
                if char > ord('z'):
                    return ""
                groups[root] = chr(char)
                char += 1
            res[i] = groups[root]

        word = "".join(res)

        # Step 3: Validate LCP matrix
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word[i] == word[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    dp[i][j] = 0

        for i in range(n):
            for j in range(n):
                if dp[i][j] != lcp[i][j]:
                    return ""

        return word