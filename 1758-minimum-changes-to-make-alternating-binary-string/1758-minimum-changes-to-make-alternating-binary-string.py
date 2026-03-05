class Solution:
    def minOperations(self, s: str) -> int:
        mismatch_start0 = 0
        mismatch_start1 = 0
        
        for i, c in enumerate(s):
            expected0 = '0' if i % 2 == 0 else '1'
            expected1 = '1' if i % 2 == 0 else '0'
            
            if c != expected0:
                mismatch_start0 += 1
            if c != expected1:
                mismatch_start1 += 1
        
        return min(mismatch_start0, mismatch_start1)