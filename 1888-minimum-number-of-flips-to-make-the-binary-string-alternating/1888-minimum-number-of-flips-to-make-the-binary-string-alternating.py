class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s = s + s
        
        alt1 = "".join('0' if i % 2 == 0 else '1' for i in range(2 * n))
        alt2 = "".join('1' if i % 2 == 0 else '0' for i in range(2 * n))
        
        res = float('inf')
        diff1 = diff2 = 0
        l = 0
        
        for r in range(2 * n):
            if s[r] != alt1[r]:
                diff1 += 1
            if s[r] != alt2[r]:
                diff2 += 1
            
            if r - l + 1 > n:
                if s[l] != alt1[l]:
                    diff1 -= 1
                if s[l] != alt2[l]:
                    diff2 -= 1
                l += 1
            
            if r - l + 1 == n:
                res = min(res, diff1, diff2)
        
        return res