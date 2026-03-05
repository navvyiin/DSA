class Solution:
    def findAnagrams(self, s, p):
        from collections import Counter
        
        p_count = Counter(p)
        window = Counter()
        res = []
        left = 0
        
        for right in range(len(s)):
            window[s[right]] += 1
            
            if right - left + 1 > len(p):
                window[s[left]] -= 1
                if window[s[left]] == 0:
                    del window[s[left]]
                left += 1
            
            if window == p_count:
                res.append(left)
        
        return res