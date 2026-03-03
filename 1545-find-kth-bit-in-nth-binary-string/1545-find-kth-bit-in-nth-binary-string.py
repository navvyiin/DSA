class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        # Base case
        if n == 1:
            return "0"
        
        length = (1 << n) - 1   # 2^n - 1
        mid = (length // 2) + 1
        
        # If k is the middle element
        if k == mid:
            return "1"
        
        # If k lies in the left half
        if k < mid:
            return self.findKthBit(n - 1, k)
        
        # If k lies in the right half
        mirror = length - k + 1
        bit = self.findKthBit(n - 1, mirror)
        
        # Invert the result
        return "1" if bit == "0" else "0"