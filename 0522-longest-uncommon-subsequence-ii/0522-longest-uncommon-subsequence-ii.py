class Solution:
    def findLUSlength(self, strs):
        def isSubseq(a, b):
            i = 0
            for c in b:
                if i < len(a) and a[i] == c:
                    i += 1
            return i == len(a)

        strs.sort(key=len, reverse=True)

        for i, s in enumerate(strs):
            uncommon = True
            for j, t in enumerate(strs):
                if i != j and isSubseq(s, t):
                    uncommon = False
                    break
            if uncommon:
                return len(s)

        return -1