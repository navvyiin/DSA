class Solution:
    def closestTarget(self, words, target, startIndex):
        n = len(words)
        ans = float('inf')
        
        for i in range(n):
            if words[i] == target:
                dist = min(abs(i - startIndex), n - abs(i - startIndex))
                ans = min(ans, dist)
        
        return ans if ans != float('inf') else -1