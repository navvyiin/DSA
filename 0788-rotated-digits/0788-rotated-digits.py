class Solution:
    def rotatedDigits(self, n: int) -> int:
        valid = {0, 1, 2, 5, 6, 8, 9}
        diff = {2, 5, 6, 9}
        
        count = 0
        
        for num in range(1, n + 1):
            digits = list(map(int, str(num)))
            
            if all(d in valid for d in digits) and any(d in diff for d in digits):
                count += 1
        
        return count