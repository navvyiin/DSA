class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = []
        chars = ['a', 'b', 'c']

        def dfs(path):
            if len(res) >= k:
                return
            if len(path) == n:
                res.append(path)
                return
            
            for c in chars:
                if not path or path[-1] != c:
                    dfs(path + c)

        dfs("")
        return res[k-1] if k <= len(res) else ""