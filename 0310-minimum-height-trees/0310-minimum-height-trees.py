from collections import defaultdict, deque

class Solution:
    def findMinHeightTrees(self, n, edges):
        if n == 1:
            return [0]

        graph = defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)

        leaves = deque()
        for i in range(n):
            if len(graph[i]) == 1:
                leaves.append(i)

        remaining = n

        # Trim leaves level by level
        while remaining > 2:
            leaf_count = len(leaves)
            remaining -= leaf_count

            for _ in range(leaf_count):
                leaf = leaves.popleft()
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)

                if len(graph[neighbor]) == 1:
                    leaves.append(neighbor)

        return list(leaves)