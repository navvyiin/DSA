class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        # If target exceeds total capacity, impossible
        if target > x + y:
            return False
        
        # Trivial cases
        if target == 0:
            return True
        if target == x or target == y or target == x + y:
            return True

        # Euclidean algorithm for gcd
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        # Bézout’s identity condition
        return target % gcd(x, y) == 0