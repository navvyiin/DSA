from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_count = Counter(magazine)
        
        for char in ransomNote:
            if magazine_count[char] == 0:
                return False
            magazine_count[char] -= 1
        
        return True